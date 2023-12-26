#include "european_call.h"
#include <cmath>
#include <random>
#include <ctime>

using namespace std;


european_call::european_call(double spotprice, double strikeprice, double maturity, double volatility, double r) : option(spotprice, strikeprice, maturity, volatility, r) {}

european_call::~european_call() {}


double european_call::price_BSM()
{
    double d1 = (log(get_spotprice() / get_strikeprice()) + (get_r() + 0.5 * get_volatility() * get_volatility()) * get_maturity()) / (get_volatility() * sqrt(get_maturity()));
    double d2 = d1 - get_volatility() * sqrt(get_maturity());

    return get_spotprice() * 0.5 * (1.0 + erf(d1 / sqrt(2.0))) - get_strikeprice() * exp(-get_r()*get_maturity()) * 0.5 * (1.0 + erf(d2 / sqrt(2.0)));
}


double european_call::price_MC(int N)
{
    double sum = 0;
    double S = get_spotprice() * exp((get_r() - 0.5 * get_volatility() * get_volatility()) * get_maturity());
    double diff;
    double gauss;

    default_random_engine generator(time(NULL));
    normal_distribution<double> distribution(0.0,1.0);

    for (int i=0 ; i<N ; i++)
    {
        gauss = distribution(generator);
        diff = S * exp(get_volatility() * sqrt(get_maturity()) * gauss) - get_strikeprice();
        if (diff>0)
        {
            sum += diff;
        }
    }

    return (sum / N) * exp(-get_r() * get_maturity());
}
