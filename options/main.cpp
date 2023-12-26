#include <iostream>
#include "european_call.h"
#include "european_put.h"

using namespace std;

int main()
{

    double spotprice = 100;
    double strikeprice = 105;
    double maturity = 2;
    double volatility = 0.3;
    double r = 0.05;

    european_call test(spotprice, strikeprice, maturity, volatility, r);
    european_put TEST(spotprice, strikeprice, maturity, volatility, r);

    double P1 = test.price_BSM();
    double P2 = test.price_MC(10000);
    double Q1 = TEST.price_BSM();
    double Q2 = TEST.price_MC(10000);

    cout<<P1<<endl;
    cout<<P2<<endl;
    cout<<Q1<<endl;
    cout<<Q2<<endl;

    return 0;
}
