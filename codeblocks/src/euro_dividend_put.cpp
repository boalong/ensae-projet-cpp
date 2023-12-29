#include "C:\Users\Letellier\Desktop\Projet C++\ensae-projet-cpp\options\include\euro_dividend_put.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include <random>

using namespace std;

/*
Made according to Hull's method in Option Futures and other derivatives, you need to have a known dividend yield
*/

euro_dividend_put::euro_dividend_put(double spotprice, double strikeprice, double maturity,
                                       double volatility, double r, double dividend)
                                       : option(spotprice, strikeprice, maturity, volatility, r), dividend(dividend){}

euro_dividend_put::~euro_dividend_put() {}

double euro_dividend_put::get_dividend() const { return dividend; }

void euro_dividend_put::set_dividend(double newDividend) { dividend = newDividend; }

double euro_dividend_put::price_BSM()
{
    double adjustedPrice = get_spotprice() * exp(-get_dividend() * get_maturity());
    double d1 = (log(get_spotprice() / get_strikeprice()) + (get_r() - get_dividend() + 0.5 * get_volatility() * get_volatility()) * get_maturity()) / (get_volatility() * sqrt(get_maturity()));
    double d2 = d1 - get_volatility() * sqrt(get_maturity());

    return -adjustedPrice * 0.5 * (1.0 + erf(-d1 / sqrt(2.0))) + get_strikeprice() * exp(-get_r() * get_maturity()) * 0.5 * (1.0 + erf(-d2 / sqrt(2.0)));
}

double euro_dividend_put::price_MC(int N_timesteps, int N_simulations)
{
    double sum = 0.0;
    default_random_engine generator(time(NULL));
    normal_distribution<double> distribution(0.0, 1.0);

    for (int i = 0; i < N_simulations; i++)
    {
        double S = get_spotprice();

        for (int j = 0; j < N_timesteps; j++)
        {
            double gauss = distribution(generator);
            S *= exp((get_r() - get_dividend() - 0.5 * get_volatility() * get_volatility()) * (get_maturity() / N_timesteps) + get_volatility() * sqrt(get_maturity() / N_timesteps) * gauss);
        }

        sum += max(get_strikeprice() - S, 0.0);
    }

    return (sum / N_simulations) * exp(-get_r() * get_maturity());
}

