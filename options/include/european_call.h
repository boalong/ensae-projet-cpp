#ifndef EUROPEAN_CALL_H
#define EUROPEAN_CALL_H
#include "option.h"


class european_call : public option
{
    public:
        european_call(double spotprice, double strikeprice, double maturity, double volatility, double r);
        ~european_call();

        double price_BSM();
        double price_MC(int N);

        // void replication_strat();

};

#endif // EUROPEAN_CALL_H
