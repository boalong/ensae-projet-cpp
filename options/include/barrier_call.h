#ifndef BARRIER_CALL_H
#define BARRIER_CALL_H
#include "option.h"


class barrier_call : public option     // creation of a subclass for specific options
{
    private:
        int knock; // Type = 1 if in, 0 if out (if initial price is greater than H,
                   // can't be equal to 1)
        int dir;   // Dir = 1 up in, 0 if down
        double H;  // Barrier

    public:
        barrier_call(double spotprice, double strikeprice, double maturity,
                      double volatility, double r, int knock, int dir, double H);
        ~barrier_call();

        // Methods for retrieving arguments
        double get_knock();
        double get_dir();
        double get_H();

        double price_MC(int N_simulations, int N_timesteps);
};

#endif // BARRIER_CALL_H
