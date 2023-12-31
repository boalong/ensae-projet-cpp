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

    cout<<"==========================================="<<endl;
    cout<<"Default values for the option's parameters:" << endl;
    cout<<"===========================================" << endl;
    cout<<"     Spot price: " << spotprice << endl;
    cout<<"     Strike price: " << strikeprice << endl;
    cout<<"     Maturity (years): " << maturity << endl;
    cout<<"     Volatility: " << volatility << endl;
    cout<<"     Risk-free interest rate: " << r << endl;
    cout<<"     Annual dividend rate: " << dividend<<endl;
    cout<<"==========================================="<<endl<<endl;


    // European options testing

    european_call EuropeanCall(spotprice, strikeprice, maturity, volatility, r);
    european_put EuropeanPut(spotprice, strikeprice, maturity, volatility, r);

    cout<<"European call, Black-Scholes: "<<EuropeanCall.price_BSM()<<endl;
    cout<<"European call, Binomial Tree with 10000 timesteps: "<<EuropeanCall.price_BT(10000)<<endl;
    cout<<"European call, Monte Carlo with 100 timesteps, 10000 simulations: "<<EuropeanCall.price_MC(100, 10000)<<endl;
    EuropeanCall.replication();

    cout<<"European put, Black-Scholes: "<<EuropeanPut.price_BSM()<<endl;
    cout<<"European put, Binomial Tree with 10000 timesteps: "<<EuropeanPut.price_BT(10000)<<endl;
    cout<<"European put, Monte Carlo with 100 timesteps, 10000 simulations: "<<EuropeanPut.price_MC(100, 10000)<<endl;
    EuropeanPut.replication();
    cout<<endl;


    // Asian options testing

    asian_call AsianCall(spotprice, strikeprice, maturity, volatility, r);
    asian_put AsianPut(spotprice, strikeprice, maturity, volatility, r);

    cout<<"Asian call, Black-Scholes: "<<AsianCall.price_BSM()<<endl;
    cout<<"Asian call, Monte Carlo with 100 timesteps, 10000 simulations: "<<AsianCall.price_MC(100, 10000)<<endl;

    cout<<"Asian put, Black-Scholes: "<<AsianPut.price_BSM()<<endl;
    cout<<"Asian put, Monte Carlo with 100 timesteps, 10000 simulations: "<<AsianPut.price_MC(100, 10000)<<endl<<endl;


    // American options testing

    american_put AmericanPut(spotprice, strikeprice, maturity, volatility, r);

    cout<<"American put, Binomial Tree with 1000 timesteps: "<<AmericanPut.price_BT(1000)<<endl;
    cout<<"American put, Monte Carlo with 100 timesteps, 10000 simulations: "<<AmericanPut.price_MC(100, 10000)<<endl<<endl;


    // European options with dividends testing

    euro_dividend_call EuroDividendCall(spotprice, strikeprice, maturity, volatility, r, dividend);
    euro_dividend_put EuroDividendPut(spotprice, strikeprice, maturity, volatility, r, dividend);

    cout<<"European call with dividends, Black-Scholes: "<<EuroDividendCall.price_BSM()<<endl;
    cout<<"European call with dividends, Monte Carlo with 100 timesteps, 10000 simulations: "<<EuroDividendCall.price_MC(100, 10000)<<endl;

    cout<<"European put with dividends, Black-Scholes: "<<EuroDividendPut.price_BSM()<<endl;
    cout<<"European put with dividends, Monte Carlo with 100 timesteps, 10000 simulations: "<<EuroDividendPut.price_MC(100, 10000)<<endl<<endl;


    // Barrier options testing

    barrier_call BarrierCall(spotprice, strikeprice, maturity, volatility, r, 1, 1, 75.0); //up-and-in call, barrier is 75
    barrier_put BarrierPut(spotprice, strikeprice, maturity, volatility, r, 0, 1, 75.0); //up-and-out put, barrier is 75

    cout<<"Barrier call (up-and-in call, barrier is 75), Monte Carlo with 100 timesteps, 10000 simulations: "<<BarrierCall.price_MC(100, 10000)<<endl;

    cout<<"Barrier put (up-and-out put, barrier is 75), Monte Carlo with 100 timesteps, 10000 simulations: "<<BarrierPut.price_MC(100, 10000)<<endl<<endl;


    // Lookback options testing

    lookback_call LookbackCall(spotprice, strikeprice, maturity, volatility, r);
    lookback_put LookbackPut(spotprice, strikeprice, maturity, volatility, r);

    cout<<"Lookback call, Monte Carlo with 100 timesteps, 10000 simulations: "<<LookbackCall.price_MC(100, 10000)<<endl;

    cout<<"Lookback put, Monte Carlo with 100 timesteps, 10000 simulations: "<<LookbackPut.price_MC(100, 10000)<<endl<<endl;


    return 0;
}

