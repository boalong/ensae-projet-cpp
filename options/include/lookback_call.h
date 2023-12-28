#ifndef LOOKBACK_CALL_H
#define LOOKBACK_CALL_H
#include "option.h"


class lookback_call : public option     // creation of a subclass for specific options
{
    public:
        lookback_call(double spotprice, double strikeprice, double maturity, double volatility, double r);
        ~lookback_call();

        double price_MC(int N_simulations, int N_timesteps);
};

#endif // LOOKBACK_CALL_H
