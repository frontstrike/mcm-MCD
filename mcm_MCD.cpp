#include <iostream>
#include <vector>
#include <math.h>
#include "mcm_MCD.hh"


std::vector <int> Prime_factorization::prime_factorization(int num) 
{
    int dividend = num;

    if (dividend != 0) {
    dividend_prime_factorization.push_back(dividend);
    }

    while(dividend != 1 && dividend != 0) 
    {
        if(dividend%2 == 0) {
            dividend = dividend/2;
            dividend_prime_factorization.push_back(dividend);
            prime_factors.push_back(2);
        }
        else if (dividend%3 == 0) {
            dividend = dividend/3;
            dividend_prime_factorization.push_back(dividend);
            prime_factors.push_back(3);
        }
        else if (dividend%5 == 0) {
            dividend = dividend/5;
            dividend_prime_factorization.push_back(dividend);
            prime_factors.push_back(5);
        }
        else {
            dividend = dividend/dividend;
            dividend_prime_factorization.push_back(dividend);
            prime_factors.push_back(dividend);
        }
    }
    
    return prime_factors;
 
}

std::vector <int> Prime_factorization::get_dividend_prime_factorization() 
{
    if(! dividend_prime_factorization.empty()) {
        return dividend_prime_factorization;
    }
    else {
        std::cerr << "Warning! Prime factorization was not initialized,please call the function prime_factorization" << std::endl;
        return dividend_prime_factorization;
    }
    
}