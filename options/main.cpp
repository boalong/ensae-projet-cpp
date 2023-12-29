#include <iostream>

#include "C:\Users\Letellier\Desktop\Projet C++\ensae-projet-cpp\options\include\european_call.h"
#include "C:\Users\Letellier\Desktop\Projet C++\ensae-projet-cpp\options\include\european_put.h"
#include "C:\Users\Letellier\Desktop\Projet C++\ensae-projet-cpp\options\include\american_put.h"
#include "C:\Users\Letellier\Desktop\Projet C++\ensae-projet-cpp\options\include\asian_call.h"
#include "C:\Users\Letellier\Desktop\Projet C++\ensae-projet-cpp\options\include\asian_put.h"
#include "C:\Users\Letellier\Desktop\Projet C++\ensae-projet-cpp\options\include\barrier_call.h"
#include "C:\Users\Letellier\Desktop\Projet C++\ensae-projet-cpp\options\include\barrier_put.h"
#include "C:\Users\Letellier\Desktop\Projet C++\ensae-projet-cpp\options\include\lookback_call.h"
#include "C:\Users\Letellier\Desktop\Projet C++\ensae-projet-cpp\options\include\lookback_put.h"
#include "C:\Users\Letellier\Desktop\Projet C++\ensae-projet-cpp\options\include\euro_dividend_call.h"
#include "C:\Users\Letellier\Desktop\Projet C++\ensae-projet-cpp\options\include\euro_dividend_put.h"

#include "C:\Users\Letellier\Desktop\Projet C++\ensae-projet-cpp\options\include\util.h"

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

    double p1 = Test.price_BSM();
    double p2 = Test.price_MC(100, 10000);
    double q1 = tEST.price_BSM();
    double q2 = tEST.price_MC(100, 10000);

    cout<<p1<<endl;
    cout<<p2<<endl;
    cout<<q1<<endl;
    cout<<q2<<endl;

    american_put AmPut(spotprice, strikeprice, maturity, volatility, r);

    cout << AmPut.price_BT(1000)<<endl;
    cout << AmPut.price_MC(100, 1000)<<endl;

    barrier_call Option(120.0, 65.0, 1.0, 0.2, 0.05, 1, 0, 80.0);
    double result = Option.price_MC(100, 10000);
    if (result != -1)
    {
        cout << "Price is "<<result << endl;
    }
    else
    {
        cout << "Error in pricing option." << endl;
    }

    barrier_put Option2(90.0, 95.0, 1.0, 0.2, 0.05, 1, 0, 80.0);
    double result2 = Option2.price_MC(100, 10000);
    if (result != -1)
    {
        cout << "Price is "<<result2 << endl;
    }
    else
    {
        cout << "Error in pricing option." << endl;
    }

    lookback_put lookbackPut(100.0, 90.0, 1.0, 0.2, 0.05);

    double lookbackPrice = lookbackPut.price_MC(100, 10000);
    cout << "Lookback Option Price: " << lookbackPrice << endl;

    lookback_call lookbackCall(100.0, 90.0, 1.0, 0.2, 0.05);

    double lookbackPrice2 = lookbackCall.price_MC(100, 10000);
    cout << "Lookback Option Price: " << lookbackPrice2 << endl;

    return 0;
}

