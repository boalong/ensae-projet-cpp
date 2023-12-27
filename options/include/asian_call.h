#ifndef ASIAN_CALL_H
#define ASIAN_CALL_H
#include "option.h"


class asian_call : public option     // creation of a subclass for specific options
{
    public:
        asian_call(double spotprice, double strikeprice, double maturity, double volatility, double r);
        ~asian_call();

        double price_cont_BSM();    // function which computes the price of an Asian call for a continuous geometric average using the Black-Scholes closed-form formula
        double price_disc_MC(int N_timesteps, int N_simulations);   // function which computes the price of an Asian call for an arithmetic discrete average using a Monte Carlo simulation

};

#endif // ASIAN_CALL_H
