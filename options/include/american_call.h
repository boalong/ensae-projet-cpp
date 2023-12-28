#ifndef AMERICAN_CALL_H
#define AMERICAN_CALL_H
#include "option.h"


class american_call : public option     // creation of a subclass for specific options
{
    public:
        american_call(double spotprice, double strikeprice, double maturity, double volatility, double r);
        ~american_call();

        double price_BSM();     // function which computes the price of an American call with the Black-Scholes closed-form formula
        double price_BT(int N_timesteps);     // function which computes the price of an American call using a binomial tree method
        double price_MC(int N_timesteps, int N_simulations);    // function which computes the price of an American call with a Monte Carlo simulation

        void replication();     // function which returns the replication strategy for this option

};

#endif // AMERICAN_CALL_H
