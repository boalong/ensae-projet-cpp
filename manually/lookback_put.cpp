#include "lookback_put.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include <random>

using namespace std;


lookback_put::lookback_put(double spotprice, double strikeprice, double maturity, double volatility, double r) : option(spotprice, strikeprice, maturity, volatility, r) {}

lookback_put::~lookback_put() {}

double lookback_put::price_MC(int numTimeSteps, int numSimulations)
{
    double sum = 0;
    double S;
    default_random_engine generator(time(nullptr));
    normal_distribution<double> distribution(0.0, 1.0);

    for (int i = 0; i < numSimulations; i++) {
      S = get_spotprice();
      double Min_S = get_spotprice();
      double Max_S = get_spotprice();

      for (int j = 0; j < numTimeSteps; j++) {
        double gauss = distribution(generator);
        S *= exp((get_r() - 0.5 * get_volatility() * get_volatility()) * (get_maturity() / numTimeSteps) + get_volatility() * sqrt(get_maturity() / numTimeSteps) * gauss);
        Min_S = min(Min_S, S);
        Max_S = max(Max_S, S);
      }
      sum += max(Max_S - S, 0.0);
    }

    return (sum / numSimulations) * exp(-get_r() * get_maturity());
}
