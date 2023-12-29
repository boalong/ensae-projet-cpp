#ifndef OPTION_H
#define OPTION_H


class option
{

    protected:

        double spotprice;       // current price of the underlying asset
        double strikeprice;     // strike price of the option
        double maturity;        // maturity of the option, in years
        double volatility;      // volatility of the option
        double r;               // risk-free interest rate

    public:

        option(double spotprice, double strikeprice, double maturity, double volatility, double r);
        ~option();

        // get methods
        double get_spotprice();
        double get_strikeprice();
        double get_maturity();
        double get_volatility();
        double get_r();

        // set methods
        void set_spotprice();
        void set_strikeprice();
        void set_maturity();
        void set_volatility();
        void set_r();

};

#endif // OPTION_H
