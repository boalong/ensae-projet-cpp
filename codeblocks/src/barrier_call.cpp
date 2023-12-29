#include "barrier_call.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include <random>

using namespace std;

/* Disclaimer:
  In this code, the pricing function doesn't allow to price some barrier options: example you can't use this to price
  up options if you already have initial spotprice > barrier
*/


barrier_call::barrier_call(double spotprice, double strikeprice, double maturity,
                           double volatility, double r, int knock, int dir, double H)
                           : option(spotprice, strikeprice, maturity, volatility, r), knock(knock), dir(dir), H(H){}

barrier_call::~barrier_call() {}

double barrier_call::get_knock() { return knock; }
double barrier_call::get_dir() { return dir; }
double barrier_call::get_H() { return H; }


double barrier_call::price_MC(int numTimeSteps, int numSimulations)
{
  double sum = 0.0;
  default_random_engine generator(time(nullptr));
  normal_distribution<double> distribution(0.0, 1.0);

  if (get_dir() == 1 && get_knock() == 1) // up-and-in
  {
    if (get_H() < get_spotprice()) {
      cout << "Barrier is lower than the initial price" << endl;
      return -1;
    } else {
      for (int i = 0; i < numSimulations; i++) {
        double S = get_spotprice();

        for (int j = 0; j < numTimeSteps; j++) {
          double gauss = distribution(generator);
          S *= exp((get_r() - 0.5 * get_volatility() * get_volatility()) *
                       (get_maturity() / numTimeSteps) +
                   get_volatility() * sqrt(get_maturity() / numTimeSteps) *
                       gauss);
        }

        if (get_H() < S) {
          sum += max(S - get_strikeprice(), 0.0);
        }
      }
      return (sum / numSimulations) * exp(-get_r() * get_maturity());
    }
  } else if (get_dir() == 1 && get_knock() == 0) // up-and-out
  {
    if (get_H() < get_spotprice()) {
      cout << "Barrier is lower than the initial price" << endl;
      return -1;
    } else {
      for (int i = 0; i < numSimulations; i++) {
        double S = get_spotprice();

        for (int j = 0; j < numTimeSteps; j++) {
          double gauss = distribution(generator);
          S *= exp((get_r() - 0.5 * get_volatility() * get_volatility()) *
                       (get_maturity() / numTimeSteps) +
                   get_volatility() * sqrt(get_maturity() / numTimeSteps) *
                       gauss);
        }

        if (get_H() > S) {
          sum += max(S - get_strikeprice(), 0.0);
        }
      }
      return (sum / numSimulations) * exp(-get_r() * get_maturity());
    }
  }

  else if (get_dir() == 0 && get_knock() == 0) // down-and-out
  {
    if (get_H() > get_spotprice()) {
      cout << "Barrier is higher than the initial price" << endl;
      return -1;
    }
    for (int i = 0; i < numSimulations; i++) {
      double S = get_spotprice();

      for (int j = 0; j < numTimeSteps; j++) {
        double gauss = distribution(generator);
        S *=
            exp((get_r() - 0.5 * get_volatility() * get_volatility()) *
                    (get_maturity() / numTimeSteps) +
                get_volatility() * sqrt(get_maturity() / numTimeSteps) * gauss);
      }

      if (get_H() < S) {
        sum += max(S - get_strikeprice(), 0.0);
      }
    }
    return (sum / numSimulations) * exp(-get_r() * get_maturity());
  }

  else if (get_dir() == 0 && get_knock() == 1) // down-and-in
  {
    if (get_H() > get_spotprice()) {
      cout << "Barrier is higher than the initial price" << endl;
      return -1;
    }
    for (int i = 0; i < numSimulations; i++) {
      double S = get_spotprice();

      for (int j = 0; j < numTimeSteps; j++) {
        double gauss = distribution(generator);
        S *=
            exp((get_r() - 0.5 * get_volatility() * get_volatility()) *
                    (get_maturity() / numTimeSteps) +
                get_volatility() * sqrt(get_maturity() / numTimeSteps) * gauss);
      }

      if (get_H() > S) {
        sum += max(S - get_strikeprice(), 0.0);
      }
    }
    return (sum / numSimulations) * exp(-get_r() * get_maturity());
  }

  return 0.0;
}
