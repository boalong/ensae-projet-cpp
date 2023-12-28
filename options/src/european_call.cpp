#include "european_call.h"
#include <cmath>
#include <random>
#include <ctime>
#include <iostream>

using namespace std;


european_call::european_call(double spotprice, double strikeprice, double maturity, double volatility, double r) : option(spotprice, strikeprice, maturity, volatility, r) {}

european_call::~european_call() {}


double european_call::price_BSM()
{
    double d1 = (log(get_spotprice() / get_strikeprice()) + (get_r() + 0.5 * get_volatility() * get_volatility()) * get_maturity()) / (get_volatility() * sqrt(get_maturity()));
    double d2 = d1 - get_volatility() * sqrt(get_maturity());

    return get_spotprice() * 0.5 * (1.0 + erf(d1 / sqrt(2.0))) - get_strikeprice() * exp(-get_r()*get_maturity()) * 0.5 * (1.0 + erf(d2 / sqrt(2.0)));
}


double european_call::price_BT(int N)
{
    double deltaT = get_maturity()/N;
    double up = exp(get_volatility() * sqrt(deltaT));
    double p0 = (up - exp( -r * deltaT )) / ( pow(up, 2) - 1);
    double p1 = exp( -r * deltaT) - p0;

    double p[N]; // declaration of an array of length N

    // initial values at time T
    for (int i=0 ; i < N ; i++)
    {
        p[i] = get_spotprice() * pow(up, 2*i - N) - get_strikeprice();
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
        }
    }

    return p[0];
}


double european_call::price_MC(int N_timesteps, int N_simulations)
{
    double sum = 0;
    double S;
    double diff;
    double gauss;

    default_random_engine generator(time(NULL));
    normal_distribution<double> distribution(0.0,1.0);

    for (int i=0 ; i < N_simulations ; i++)
    {
        S = get_spotprice();

        for (int j=0 ; j < N_timesteps ; j++)
        {
            gauss = distribution(generator);
            S *= exp((get_r() - 0.5 * get_volatility() * get_volatility()) * (get_maturity() / N_timesteps) + get_volatility() * sqrt(get_maturity() / N_timesteps) * gauss);
        }

        diff = S - get_strikeprice();
        if (diff>0)
        {
            sum += diff;
        }
    }

    return (sum / N_simulations) * exp(-get_r() * get_maturity());
}


void european_call::replication()
{
    double d1 = (log(get_spotprice() / get_strikeprice()) + (get_r() + 0.5 * get_volatility() * get_volatility()) * get_maturity()) / (get_volatility() * sqrt(get_maturity()));
    double d2 = d1 - get_volatility() * sqrt(get_maturity());

    double N_shares = get_spotprice() * 0.5 * (1.0 + erf(d1 / sqrt(2.0)));
    double N_bonds = get_strikeprice() * exp(-get_r()*get_maturity()) * 0.5 * (1.0 + erf(d2 / sqrt(2.0)));

    cout<<"To replicate this European call, buy "<<N_shares<<" in shares of the stock \nand borrow "<<N_bonds<<" in bonds at the risk-free interest rate."<<endl;
}
