#include "option.h"

option::option(double spotprice, double strikeprice, double maturity, double volatility, double r)
    {
        this->spotprice=spotprice;
        this->strikeprice=strikeprice;
        this->maturity=maturity;
        this->volatility=volatility;
        this->r=r;
    }

option::~option() {}

double option::get_spotprice() { return spotprice; }
double option::get_strikeprice() { return strikeprice; }
double option::get_maturity() { return maturity; }
double option::get_volatility() { return volatility; }
double option::get_r() { return r; }

void option::set_spotprice() { this->spotprice=spotprice; }
void option::set_strikeprice() { this->strikeprice=strikeprice; }
void option::set_maturity() { this->maturity=maturity; }
void option::set_volatility() { this->volatility=volatility; }
void option::set_r() { this->r=r; }
