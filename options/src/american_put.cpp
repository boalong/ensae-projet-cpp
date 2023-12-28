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
    Matrix Path(N_simulations, N_timesteps);
    double S;

    double deltaT = get_maturity() / N_simulations;
    cout<<deltaT<<endl;

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
    }

    // Notre matrice Path est remplie

    Path.print_matrix();

    double inTheMoney[N_simulations];
    double maxPayoff[N_simulations];
    double expectedCashFlowFromContinuing[N_simulations];

    for (int i=N_timesteps-1 ; i > 0 ; i--) // Should the option be exercised at time i?
    {
        for (int j=0 ; i<N_simulations ; j++)
        {
            if (get_strikeprice() > Path.get_item(j, i))
            {
                inTheMoney[j] = Path.get_item(j, i);
            }
            else
            {
                inTheMoney[j] = 0.0;
            }
        }

    }

    Matrix PayoffIfNotExercised(N_simulations, N_timesteps - 1);

    // Remplir la matrice des PayoffIfNotExercised
    for (int i=0 ; i<N_simulations ; i++)
    {
        for (int j=0 ; j<N_timesteps - 1 ; j++)
        {
            PayoffIfNotExercised.insert_item(exp(-get_r()*deltaT) * max(get_strikeprice() - Path.get_item(i, j+1), 0.0), i, j);
        }
    }

    PayoffIfNotExercised.print_matrix();

    // To make the regression, we only keep the in-the-money rows
    double X[N_simulations];
    int X_index[N_simulations];

    for (int j=0 ; j<N_timesteps - 1 ; j++)
    {
        for (int i=0 ; i<N_simulations ; i++)
        {
            if (get_strikeprice() - Path.get_item(i, j) > 0) // in-the-money
            {
                X[i] = get_strikeprice() - Path.get_item(i, j);
                X_index[i] = 1; // hash
            }
        }
    }

    for (int i=0 ; i<N_simulations ; i++)
    {
        cout<<X[i]<<endl;
        cout<<X_index[i]<<endl;
    }








        // we want to compute value of the option at time 0

        // we have to create matrix


        // for the regression, we will have to check that the matrix is invertible


}

