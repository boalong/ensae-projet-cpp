#include "asian_put.h"
#include <cmath>
#include <random>
#include <ctime>

using namespace std;


asian_put::asian_put(double spotprice, double strikeprice, double maturity, double volatility, double r) : option(spotprice, strikeprice, maturity, volatility, r) {}

asian_put::~asian_put() {}


double asian_put::price_cont_BSM()
{
    double v0 = get_volatility() / sqrt(3.0);
    double b = 0.5 * (get_r() - 0.5 * v0 * v0);
    double d1 = (log(get_spotprice() / get_strikeprice()) + (b + 0.5 * v0 * v0) * get_maturity()) / (v0 * sqrt(get_maturity()));
    double d2 = d1 - v0 * sqrt(get_maturity());

    return - get_spotprice() * exp(b - get_r()) * 0.5 * (1.0 + erf(-d1 / sqrt(2.0))) + get_strikeprice() * exp(-get_r()*get_maturity()) * 0.5 * (1.0 + erf(-d2 / sqrt(2.0)));
}

double asian_put::price_disc_MC(int N_timesteps, int N_simulations)
{
    double sum = 0;
    double S;
    double diff;
    double gauss;
    double mean;

    default_random_engine generator(time(NULL));
    normal_distribution<double> distribution(0.0,1.0);

    for (int i=0 ; i < N_simulations ; i++)
    {
        S = get_spotprice();
        mean = S;

        for (int j=0 ; j < N_timesteps ; j++)
        {
            gauss = distribution(generator);
            S *= exp((get_r() - 0.5 * get_volatility() * get_volatility()) * (get_maturity() / N_timesteps) + get_volatility() * sqrt(get_maturity() / N_timesteps) * gauss);
            mean += S;
        }

        mean = mean / (N_timesteps + 1);
        diff = get_strikeprice() - mean;
        if (diff>0)
        {
            sum += diff;
        }
    }

    return (sum / N_simulations) * exp(-get_r() * get_maturity());
}
