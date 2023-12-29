# C++ Options Pricing

This repository is a work of Marwen Khelifa, Adrien Letellier and Tsitohaina Ravelomanana for the 2023-2024 C++ course project at ENSAE.

It contains implementations of options pricing algorithms using Black-Scholes, Binomial Tree, and Monte Carlo models for various vanilla and exotic options.

Additionally, a replication strategy for European options without dividends has been implemented.

Here is a list of all options and methods available in our repository:


| Option Name | Black-Scholes | Binomial Tree | Monte Carlo | Replication Strategy |
|:-----------:|:-------------:|:-------:|:-----------:|:-----------:|
| *Example* | *:white_check_mark: (supported)* | *:x: (not supported)* | *- (not applicable)* | |
| **American** | :x: | :white_check_mark: | :white_check_mark: | :x: |
| Asian | :white_check_mark: | :x: | :white_check_mark: | :x: |
| Barrier | :x: | :x: | :white_check_mark: | :x: |
| **European** | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: |
| European with dividends | :white_check_mark: | :x: | :white_check_mark: | :x: |
| Lookback | :x: | :x: | :white_check_mark: | :x: |


## How to use our repository?

- For Code::Blocks users, the project is available in the *codeblocks* folder.

- If not using Code::Blocks, the project can be accessed manually using the 'Makefile' in the *manually* folder.

- An online C++ compiler link is provided for further accessibility: [https://onlinegdb.com/PQjal5Yps](https://onlinegdb.com/PQjal5Yps)

## How to run algorithms?

An example of utilisation is included in the main.cpp file. To price an option using a specific method, the process is the following:

1. Create an instance of the class of the option type you want to price in the main.cpp file:
  
```
[name_of_the_option]_[call] example([args]); // for a call option
[name_of_the_option]_[put] example([args]); // for a put option
```

2. Apply a method to compute the price according to the chosen method. The names of the methods are standardised for each method:

```
cout<<example.price_BSM()<<endl; // for Black-Scholes method
cout<<example.price_BT(10000)<<endl; // for Binomial Tree method with 10000 timesteps
cout<<example.price_MC(100, 10000)<<endl; // for Monte Carlo method with 100 timesteps and 10000 simulations
example.replication(); // for Replication Strategy. Note: .replication() is a void function
```
