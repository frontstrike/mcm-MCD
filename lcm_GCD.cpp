#include <iostream>
#include <vector>
#include <math.h>
#include "lcm_GCD.hh"

typedef std::vector<int> VectorInt;
typedef std::vector<std::vector<int>> VectorArrayInt;

VectorInt Prime_factorization::prime_factorization(int num) 
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
            dividend_prime_factorization.push_back(dividend);
            prime_factors.push_back(dividend);
            break;
        }
    }
    
    return prime_factors;
 
}

VectorInt Prime_factorization::get_dividend_prime_factorization() 
{
    if(! dividend_prime_factorization.empty()) {
        return dividend_prime_factorization;
    }
    else {
        std::cerr << "Warning! Prime factorization was not initialized,please call the function prime_factorization" << std::endl;
        return dividend_prime_factorization;
    }
    
}


void Prime_factorization::erase_array_factor() 
{
dividend_prime_factorization.clear();
prime_factors.clear();
}


int Prime_factorization::lcm_calc(int a, int b) 
{
    return(a*b/GCD_calculate(a,b));
    
}

int Prime_factorization::LCM(VectorInt num ,bool show_calculation_LCM) 
{
    int result = num[0];
    for (int i = 1; i < num.size(); i++)
    {
        result = lcm_calc(result,num[i]);
    }
    return result;
}

int Prime_factorization::GCD_calculate(int a,int b) 
{
    if(b == 0) 
    {
        return a;
    }
    else 
    {
        return GCD_calculate(b,a % b);
    }
}

int  Prime_factorization::GCD(VectorInt num , bool show_calculation_LCM) 
{

    int result = num[0];

    for(int i = 1;i < num.size();i++) 
    {
        result = GCD_calculate(result,num[i]);
    }

    return result;


}