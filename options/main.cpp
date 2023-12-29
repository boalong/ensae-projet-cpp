#include <iostream>

#include "european_call.h"
#include "european_put.h"
#include "american_put.h"
#include "asian_call.h"
#include "asian_put.h"
#include "barrier_call.h"
#include "barrier_put.h"
#include "lookback_call.h"
#include "lookback_put.h"
#include "euro_dividend_call.h"
#include "euro_dividend_put.h"

#include "util.h"

using namespace std;


int main()
{

    double spotprice = 70;
    double strikeprice = 65;
    double maturity = 1;
    double volatility = 0.2;
    double r = 0.02;
    double dividend = 0.01;

    european_call test(spotprice, strikeprice, maturity, volatility, r);
    european_put TEST(spotprice, strikeprice, maturity, volatility, r);

    double P1 = test.price_BSM();
    double P2 = test.price_MC(100, 10000);
    double P3 = test.price_BT(10000);
    double Q1 = TEST.price_BSM();
    double Q2 = TEST.price_MC(100, 10000);
    double Q3 = TEST.price_BT(10000);

    test.replication();
    TEST.replication();

    cout<<P1<<endl;
    cout<<P2<<endl;
    cout<<P3<<endl;
    cout<<Q1<<endl;
    cout<<Q2<<endl;
    cout<<Q3<<endl;

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


    euro_dividend_put test1(spotprice, strikeprice, maturity, volatility, r, dividend);
    euro_dividend_call test2(spotprice, strikeprice, maturity, volatility, r, dividend);

    cout<<test1.price_BSM()<<endl;
    cout<<test1.price_MC(100, 1000)<<endl;
    cout<<test2.price_BSM()<<endl;
    cout<<test2.price_MC(100, 1000)<<endl;

    barrier_call test3(spotprice, strikeprice, maturity, volatility, r, 1, 1, 75.0); //up-and-in call, barrier is 75
    barrier_put test4(spotprice, strikeprice, maturity, volatility, r, 0, 1, 75.0); //up-and-out put, barrier is 75
    
    double R1 = test3.price_MC(100, 1000);
    double R2 = test4.price_MC(100, 1000);
    
    cout<<R1<<endl;
    cout<<R2<<endl;

    lookback_call test5(spotprice, strikeprice, maturity, volatility, r);
    lookback_put test6(spotprice, strikeprice, maturity, volatility, r);

    cout<<test5.price_MC(100, 1000)<<endl;
    cout<<test6.price_MC(100, 1000)<<endl;

    return 0;
}

