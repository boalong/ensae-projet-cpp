#ifndef EUROPEAN_CALL_H
#define EUROPEAN_CALL_H
#include "option.h"


class european_call : public option     // creation of a subclass for specific options
{
    public:
        european_call(double spotprice, double strikeprice, double maturity, double volatility, double r);
        ~european_call();

        double price_BSM();     // function which computes the price of an European call with the Black-Scholes closed-form formula
        double price_MC(int N_timesteps, int N_simulations);    // function which computes the price of an European call with a Monte Carlo simulation

        void replication();     // function which returns the replication strategy for this option

};

#endif // EUROPEAN_CALL_H
