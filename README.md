# C++ Options Pricing

This repository is a work of Marwen Khelifa, Adrien Letellier and Tsitohaina Ravelomanana for the 2023-2024 C++ course project at ENSAE.

We implemented options pricing algorithms using Black-Scholes, Binomial Tree and Monte Carlo models for various vanilla and exotic options.

We also implemented replication strategy for European options without dividends.

| Option Name | Black-Scholes | Binomial Tree | Monte Carlo | Replication Strategy |
|:-----------:|:-------------:|:-------:|:-----------:|:-----------:|
| *Example* | *:white_check_mark: (supported)* | *:x: (not supported)* | *- (not applicable)* | |
| **American** | - | :white_check_mark: | :white_check_mark: | :x: |
| Asian | :white_check_mark: | :x: | :white_check_mark: | :x: |
| Barrier | :x: | :x: | :white_check_mark: | :x: |
| **European** | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: |
| European with dividends | :white_check_mark: | :x: | :white_check_mark: | :x: |
| Lookback | :x: | :x: | :white_check_mark: | :x: |

## How to use our repository?

- We worked mainly with Code::Blocks, so our project is avaible to be used in Code::Blocks using the folder *codeblocks*.

- If you are not using Code::Blocks, our project is also avaible using the folder *manually* with contains a Makefile.

- If this method does not work, you can use our project on this online C++ compiler: https://onlinegdb.com/jBLR1ynp8.

## How to run algorithms?

An example of utilisation is included in the main.cpp file. To price an option using a particular method, the process is the following:

- in the main.cpp file, create an instance of the class of the option type you want to price:
  
```
[name_of_the_option]_[call] example([args]); // for a call option
```

```
[name_of_the_option]_[put] example([args]); // for a put option
```

- then apply a method to compute the price according to the method of your choice. The names of the methods are standardised for each method:

```
cout<<example.price_BSM()<<endl; // for Black-Scholes method
cout<<example.price_BT(10000)<<endl; // for Binomial Tree method with 10000 timesteps
cout<<example.price_MC(100, 10000)<<endl; // for Monte Carlo method with 100 simulations and 10000 timesteps
cout<<example.replication()<<endl; // for Replication Strategy
```
