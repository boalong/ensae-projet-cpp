#ifndef EURO_DIVIDEND_CALL_H
#define EURO_DIVIDEND_CALL_H
#include "option.h"


class euro_dividend_call : public option     // creation of a subclass for specific options
{
    private:
        double dividend;

    public:
        euro_dividend_call(double spotprice, double strikeprice, double maturity, double volatility, double r, double dividend);
        ~euro_dividend_call();

        double get_dividend() const;
        void set_dividend(double newDividend);

        double price_BSM();
        double price_MC(int N_timesteps, int N_simulations);
};

#endif // EURO_DIVIDEND_CALL_H
