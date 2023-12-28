#include <iostream>
#include "european_call.h"
#include "european_put.h"
#include "asian_call.h"
#include "asian_put.h"
#include "american_put.h"
#include "util.h"

using namespace std;


int main()
{
    american_put test(1.0, 1.1, 3, 0.20, 0.06);
    test.price_MC(3, 8);
    return 0;
}


int main0()
{
    Matrix X(2, 2);
    X.insert_item(1.8, 0, 0);
    cout<<X.get_item(0, 0)<<endl;
    X.print_matrix();
}


int main1()
{
    american_put test(60, 55, 1, 0.20, 0.05);
    test.price_MC(10, 3);
}


int main2()
{
    double spotprice = 70;
    double strikeprice = 65;
    double maturity = 1;
    double volatility = 0.2;
    double r = 0.02;

    cout<<"Default values for the option's parameters:" << endl;
    cout<<"===========================================" << endl << endl;
    cout<<"Spot price: " << spotprice << endl;
    cout<<"Strike price: " << strikeprice << endl;
    cout<<"Maturity (years): " << maturity << endl;
    cout<<"Volatility: " << volatility << endl;
    cout<<"Risk-free interest rate: " << r << endl << endl;

    cout<<"Keep default values? (Yes: 0, No:1)" << endl;
    int default_values;
    cin>> default_values;
    cout<<endl;

    if (default_values == 1)
    {
        cout<<"Spot price: ";
        cin>>spotprice;

        cout<<"Strike price: ";
        cin>>strikeprice;

        cout<<"Maturity (years): ";
        cin>>maturity;

        cout<<"Volatility: ";
        cin>>volatility;

        cout<<"Risk-free interest rate: ";
        cin>>r;

    }

    cout<<"Calculate the price of every option with every method? (Yes:0, No:1)" << endl;
    int calc_all;
    cin>> calc_all;
    cout<<endl;

    int to_compute[12];
    int length_to_compute;
    if (calc_all == 1)
    {

        cout<<"Enter options and methods which values you want to calculate: " << endl << endl;
        cout<<"1. European call, Black & Scholes method" << endl;
        cout<<"2. European call, binomial tree method" << endl;
        cout<<"3. European call, Monte Carlo method" << endl;
        cout<<"4. European put, Black & Scholes method" << endl;
        cout<<"5. European put, binomial tree method" << endl;
        cout<<"6. European put, Monte Carlo method" << endl << endl;
        cout<<"7. American put, binomial tree method" << endl;
        cout<<"8. American put, Monte Carlo method" << endl << endl;;
        cout<<"9. Asian call, Black & Scholes method" << endl;
        cout<<"10. Asian call, Monte Carlo method" << endl;
        cout<<"11. Asian put, Black & Scholes method" << endl;
        cout<<"12. Asian put, Monte Carlo method" << endl << endl;

        cout<<"Note that if you want the value of an American call option, it can be retrieved by using the European call value.\n" << endl;

        cout<<"Enter the numbers corresponding to your choice one by one. If you are done, press 0:" << endl;

        int i=0;
        while (true)
        {
            cin>>to_compute[i];
            if (to_compute[i] == 0)
            {
                length_to_compute = i;
                break;
            }
            i++;
        }

        /*
        for (int k=0; k<length_to_compute; k++)
        {
            cout<<to_compute[k]<<endl;
        }
        */
    }

    for (int i=0; i<length_to_compute; i++)
    {
        cout<<endl<<to_compute[i]<<endl;
        if (to_compute[i] == 1)
        {
            european_call test(spotprice, strikeprice, maturity, volatility, r);
            cout<<test.price_BSM();
        }
        else if (to_compute[i] == 2)
        {
            european_call test(spotprice, strikeprice, maturity, volatility, r);
            cout<<test.price_BT(10000);
        }
        else if (to_compute[i] == 3)
        {
            european_call test(spotprice, strikeprice, maturity, volatility, r);
            cout<<test.price_MC(100, 10000);
        }
        else if (to_compute[i] == 4)
        {
            european_put test(spotprice, strikeprice, maturity, volatility, r);
            cout<<test.price_BSM();
        }
        else if (to_compute[i] == 5)
        {
            european_put test(spotprice, strikeprice, maturity, volatility, r);
            cout<<test.price_BT(10000);
        }
        else if (to_compute[i] == 6)
        {
            european_put test(spotprice, strikeprice, maturity, volatility, r);
            cout<<test.price_MC(100, 10000);
        }
        else if (to_compute[i] == 7)
        {
            american_put test(spotprice, strikeprice, maturity, volatility, r);
            cout<<test.price_BT(10000);
        }
        else if (to_compute[i] == 8)
        {
            american_put test(spotprice, strikeprice, maturity, volatility, r);
            cout<<test.price_MC(100, 10000);
        }
        else if (to_compute[i] == 9)
        {
            asian_call test(spotprice, strikeprice, maturity, volatility, r);
            cout<<test.price_cont_BSM();
        }
        else if (to_compute[i] == 10)
        {
            asian_call test(spotprice, strikeprice, maturity, volatility, r);
            cout<<test.price_disc_MC(100, 10000);
        }
        else if (to_compute[i] == 11)
        {
            asian_put test(spotprice, strikeprice, maturity, volatility, r);
            cout<<test.price_cont_BSM();
        }
        else if (to_compute[i] == 12)
        {
            asian_put test(spotprice, strikeprice, maturity, volatility, r);
            cout<<test.price_disc_MC(100, 10000);
        }
    }

    return 0;
}

/*
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
*/
    /*

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

    */

/*
    american_call TEst(spotprice, strikeprice, maturity, volatility, r);
    american_put teST(spotprice, strikeprice, maturity, volatility, r);

    double p1 = TEst.price_BSM();
    double p2 = TEst.price_MC(100, 10000);
    double p3 = TEst.price_BT(10000);

    // double q1 = teST.price_BSM();
    // double q2 = teST.price_MC(100, 10000);
    double q3 = teST.price_BT(10000); // longer to compute

    cout<<p1<<endl;
    cout<<p2<<endl;
    cout<<p3<<endl;

    // cout<<q1<<endl;
    // cout<<q2<<endl;
    cout<<q3<<endl;

    return 0;
}
/
*/
