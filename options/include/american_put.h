#ifndef AMERICAN_PUT_H
#define AMERICAN_PUT_H
#include "option.h"


class american_put : public option     // creation of a subclass for specific options
{
    public:
        american_put(double spotprice, double strikeprice, double maturity, double volatility, double r);
        ~american_put();

        double price_BT(int N_timesteps);     // function which computes the price of an American put using a binomial tree method
        double price_MC(int N_timesteps, int N_simulations);    // function which computes the price of an American put with a Monte Carlo simulation

        void replication();     // function which returns the replication strategy for this option
};

#endif // AMERICAN_PUT_H

