#ifndef LOOKBACK_PUT_H
#define LOOKBACK_PUT_H
#include "option.h"


class lookback_put : public option     // creation of a subclass for specific options
{
    public:
        lookback_put(double spotprice, double strikeprice, double maturity, double volatility, double r);
        ~lookback_put();

        double price_MC(int N_simulations, int N_timesteps);
};

#endif // LOOKBACK_PUT_H
