#include "american_put.h"
#include "util.h"

#include<cmath>
#include<random>
#include<ctime>
#include<iostream>
#include<algorithm>

using namespace std;


american_put::american_put(double spotprice, double strikeprice, double maturity, double volatility, double r) : option(spotprice, strikeprice, maturity, volatility, r) {}

american_put::~american_put() {}


double american_put::price_BT(int N)
{
    double deltaT = get_maturity()/N;
    double up = exp(get_volatility() * sqrt(deltaT));
    double p0 = (up - exp( -r * deltaT )) / ( pow(up, 2) - 1);
    double p1 = exp( -r * deltaT) - p0;

    double p[N]; // declaration of an array of length N

    // initial values at time T
    for (int i=0 ; i < N ; i++)
    {
        p[i] = get_strikeprice() - get_spotprice() * pow(up, 2*i - N);
        if (p[i] < 0)
        {
            p[i] = 0;
        }
    }

    // move to earlier times
    for (int j=N-1 ; j > 0 ; j--)
    {
        for (int i=0 ; i < j ; i++)
        {
            // binomial value
            p[i] = p0 * p[i+1] + p1 * p[i];
            // exercise value
            double exercise = get_strikeprice() - get_spotprice() * pow(up, 2*i - j);
            if (p[i] < exercise)
            {
                p[i] = exercise;
            }
        }
    }
    return p[0];
}


double american_put::price_MC(int N_timesteps, int N_simulations)
{
    Matrix Path(N_simulations, N_timesteps+1);
    double S;

    double deltaT = get_maturity() / N_timesteps;
    // cout<<deltaT<<endl;

    double gauss;

    default_random_engine generator(time(NULL));
    normal_distribution<double> distribution(0.0,1.0);

    for (int i=0 ; i < N_simulations ; i++)
    {
        S = get_spotprice();
        for (int j=0 ; j < N_timesteps ; j++)
        {
            Path.insert_item(S, i, j);
            gauss = distribution(generator);
            S *= exp((get_r() - 0.5 * get_volatility() * get_volatility()) * (get_maturity() / N_timesteps) + get_volatility() * sqrt(get_maturity() / N_timesteps) * gauss);
        }
        Path.insert_item(S, i, N_timesteps);
    }

    Matrix PotentialPayoffs(N_simulations, N_timesteps+1);

    for (int i=0 ; i < N_simulations ; i++)
    {
        for (int j=0 ; j < N_timesteps+1 ; j++)
        {
            PotentialPayoffs.insert_item( max(get_strikeprice() - Path.get_item(i, j), 0.0) , i, j);
        }
    }

    int ExerciseTime[N_simulations];
    double PayoffAtExercise[N_simulations];

    for (int i=0 ; i<N_simulations ; i++)
    {
        ExerciseTime[i] = N_timesteps;
        PayoffAtExercise[i] = PotentialPayoffs.get_item(i, N_timesteps);
    }

    for (int i = N_timesteps - 1 ; i>0 ; i--)
    {
        double X[N_simulations];
        int X_index[N_simulations];
        int X_length = 0;
        double Y[N_simulations];

        for (int j = 0 ; j<N_simulations ; j++)
        {
            if (PotentialPayoffs.get_item(j, i) > 0.0)
            {
                X[X_length] = Path.get_item(j, i);
                X_index[X_length] = j;
                Y[X_length] = exp(-get_r() * deltaT * (ExerciseTime[j]-i)) * PayoffAtExercise[j];
                X_length += 1;
            }
        }

        double alpha;
        double beta;

        beta = regressionBeta(Y, X, X_length);
        alpha = mean(Y, X_length) - beta*mean(X, X_length);

        double PayoffIfExercisedNow[X_length];
        double ExpectedPayoffIfContinues[X_length];

        for (int k = 0 ; k<X_length ; k++)
        {
            PayoffIfExercisedNow[k] = get_strikeprice() - X[k];
            ExpectedPayoffIfContinues[k] = alpha + beta*X[k];

            if (PayoffIfExercisedNow[k] > ExpectedPayoffIfContinues[k])
            {
                ExerciseTime[X_index[k]] = i; // i is current timestep
                PayoffAtExercise[X_index[k]] = PayoffIfExercisedNow[k];
            }
        }
    }

    double sum = 0;
    double SimulationValue = 0;

    for (int i = 0 ; i < N_simulations ; i++)
    {
        SimulationValue = PayoffAtExercise[i] * exp( -r * deltaT * ExerciseTime[i] ) ; // discounted cashflow
        sum += SimulationValue;
    }

    return sum/N_simulations;
}
