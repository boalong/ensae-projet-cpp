#ifndef EUROPEAN_PUT_H
#define EUROPEAN_PUT_H
#include "option.h"


class european_put : public option     // creation of a subclass for specific options
{
    public:
        european_put(double spotprice, double strikeprice, double maturity, double volatility, double r);
        ~european_put();

        double price_BSM();     // function which computes the price of an European put with the Black-Scholes closed-form formula
        double price_MC(int N_timesteps, int N_simulations);    // function which computes the price of an European put with a Monte Carlo simulation

        void replication();     // function which returns the replication strategy for this option

};

#endif // EUROPEAN_PUT_H
