/* lcm_GCD.cpp is a library for calculate prime factors,lcm and GCD.

   Copyright (C) 1992, 1997-2002, 2004-2023 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA
   02110-1301, USA.  */

/* Written  by Pierfrancesco Gallo <pierfrancesco.gallo.work@gmail.com> */


#include <iostream>
#include <vector>
#include <math.h>
#include "lcm_GCD.hh"

typedef std::vector<int> VectorInt;
typedef std::vector<std::vector<int>> VectorArrayInt;

VectorInt Prime_factorization::prime_factorization(int num) 
{
    /*checks whether the variables contain information
    If they are empty, continue normally without carrying out any operations.
    If both/one of them are full they are emptied.*/

    if(dividend_prime_factorization.empty() == true && prime_factors.empty() == true)
    {
        /*continue*/
    } 
    else 
    {
        dividend_prime_factorization.clear();
        prime_factors.clear();
    }


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

VectorInt Prime_factorization::get_prime_factors() 
{
    if(! prime_factors.empty()) {
        return prime_factors;
    }
    else {
        std::cerr << "Warning! Prime factorization was not initialized,please call the function prime_factorization" << std::endl;
        return prime_factors;
    }
    
}

int Prime_factorization::lcm_calc(int a, int b) 
{
    return(a*b/GCD_calculate(a,b));
    
}

int Prime_factorization::LCM(VectorInt num ,bool show_calculation_LCM) 
{
    if(show_calculation_LCM)
    {
        for(int x : num) 
        {
            std::cout << x << ":";
            for(int y : prime_factorization(x)) 
            {
                std::cout << " " << y;
            } 
            std::cout << std::endl;
        }
    }

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

int  Prime_factorization::GCD(VectorInt num , bool show_calculation_GCD) 
{

    if(show_calculation_GCD)
    {
        for(int x : num) 
        {
            std::cout << x << ":";
            for(int y : prime_factorization(x)) 
            {
                std::cout << " " << y;
            } 
            std::cout << std::endl;
        }
    }


    int result = num[0];

    for(int i = 1;i < num.size();i++) 
    {
        result = GCD_calculate(result,num[i]);
    }

    return result;


}