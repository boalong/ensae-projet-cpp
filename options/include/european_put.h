#ifndef EUROPEAN_PUT_H
#define EUROPEAN_PUT_H
#include "option.h"


class european_put : public option
{
    public:
        european_put(double spotprice, double strikeprice, double maturity, double volatility, double r);
        ~european_put();

        double price_BSM();
        double price_MC(int N);

        // void replication_strat();

};

#endif // EUROPEAN_PUT_H
