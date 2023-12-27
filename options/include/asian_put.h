#ifndef ASIAN_PUT_H
#define ASIAN_PUT_H
#include "option.h"


class asian_put : public option     // creation of a subclass for specific options
{
    public:
        asian_put(double spotprice, double strikeprice, double maturity, double volatility, double r);
        ~asian_put();

        double price_cont_BSM();    // function which computes the price of an Asian put for a continuous geometric average using the Black-Scholes closed-form formula
        double price_disc_MC(int N_timesteps, int N_simulations);   // function which computes the price of an Asian put for an arithmetic discrete average using a Monte Carlo simulation

};

#endif // ASIAN_PUT_H

