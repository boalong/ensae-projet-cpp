# C++ Options Pricing

This repository is a work of Marwen Khelifa, Adrien Letellier and Tsitohaina Ravelomanana for the 2023-2024 C++ course project at ENSAE.

We implemented options pricing algorithms using Black-Scholes, Binomial Trees and Monte Carlo models for various vanilla and exotic options.

| Option Name | Black-Scholes | Binomial Trees | Monte Carlo |
|:-----------:|:-------------:|:-------:|:-----------:|
| *Example* | *:white_check_mark: (supported)* | *:x: (not supported)* | *- (not applicable)* |
| **American** | - | :white_check_mark: | :white_check_mark: |
| Asian | :white_check_mark: | :x: | :white_check_mark: |
| Barrier | :x: | :x: | :white_check_mark: |
| **European** | :white_check_mark: | :white_check_mark: | :white_check_mark: |
| Lookback | :white_check_mark: | :white_check_mark: | :x: |

## How to use our repository?

We worked mainly with Code::Blocks, so our project is available as a .cbp file.

If you are not using Code::Blocks, our project is

## How to run algorithms?

An example of utilisation is included in the main.cpp file. To price an option using a particular method, the process is the following:

- in the main.cpp file, create an instance of the class of the option type you want to price:
  
```
[name_of_the_option]_[call] example([args]) // for a call option
```

```
[name_of_the_option]_[put] example([args]) // for a put option
```

- then apply a method to compute the price according to the method of your choice. The names of the methods are standardised for each method:

| **Black-Scholes** | **Binomial Tree** | **Monte Carlo** |
|:-----------:|:-------------:|:-------:|
| price_BSM() | price_BT(int N_timesteps) | price_MC(int N_simulations, int N_timesteps) |
