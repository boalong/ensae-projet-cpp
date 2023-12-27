#include <iostream>
#include "european_call.h"
#include "european_put.h"
#include "asian_call.h"
#include "asian_put.h"

using namespace std;

int main()
{

    double spotprice = 70;
    double strikeprice = 65;
    double maturity = 1;
    double volatility = 0.2;
    double r = 0.02;

    european_call test(spotprice, strikeprice, maturity, volatility, r);
    european_put TEST(spotprice, strikeprice, maturity, volatility, r);

    double P1 = test.price_BSM();
    double P2 = test.price_MC(100, 10000);
    double Q1 = TEST.price_BSM();
    double Q2 = TEST.price_MC(100, 10000);

    test.replication();
    TEST.replication();

    cout<<P1<<endl;
    cout<<P2<<endl;
    cout<<Q1<<endl;
    cout<<Q2<<endl;



    asian_call Test(spotprice, strikeprice, maturity, volatility, r);
    asian_put tEST(spotprice, strikeprice, maturity, volatility, r);

    double p1 = Test.price_cont_BSM();
    double p2 = Test.price_disc_MC(100, 10000);
    double q1 = tEST.price_cont_BSM();
    double q2 = tEST.price_disc_MC(100, 10000);

    cout<<p1<<endl;
    cout<<p2<<endl;
    cout<<q1<<endl;
    cout<<q2<<endl;

    return 0;
}
