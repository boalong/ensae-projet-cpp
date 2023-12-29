#ifndef EURO_DIVIDEND_PUT_H
#define EURO_DIVIDEND_PUT_H
#include "option.h"


class euro_dividend_put : public option     // creation of a subclass for specific options
{
    private:
        double dividend;

    public:
        euro_dividend_put(double spotprice, double strikeprice, double maturity, double volatility, double r, double dividend);
        ~euro_dividend_put();

        double get_dividend() const;
        void set_dividend(double newDividend);

        double price_BSM();
        double price_MC(int N_timesteps, int N_simulations);
};

#endif // EURO_DIVIDEND_PUT_H
