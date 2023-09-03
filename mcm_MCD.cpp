#include <iostream>
#include <vector>
#include <math.h>
#include "mcm_MCD.hh"

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
            dividend = dividend/dividend;
            dividend_prime_factorization.push_back(dividend);
            prime_factors.push_back(dividend);
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

void Prime_factorization::LCM(VectorInt num ,bool show_calculation_LCM) 
{
    VectorArrayInt lcm;

    for(int i : num) 
    {
        VectorInt tempV;
        VectorInt TempPf;
        TempPf = prime_factorization(i);
        erase_array_factor();

        tempV.push_back(i);

        for(int y : TempPf) 
        {
            tempV.push_back(y);
        }
        lcm.push_back(tempV);
    }

    for(int i = 0; i < lcm.size();i++) 
    {
        for(int x = 0;x < lcm[i].size();x++) 
        {
            std::cout << lcm[i][x] << " ";
            
        }
        std::cout << std::endl;
    }

    VectorArrayInt TempV1;
    VectorInt test;
    int exponent = 1;   
    for(int x = 0; x < lcm.size();x++) 
    {
        VectorInt TempV2;
        TempV2.push_back(lcm[x][1]);
        for(int y = 1; y < lcm[x].size();y++) 
        {
            if(lcm[x][y] == lcm[x][y+1] && y+1 < lcm[x].size()) 
            {
                if(lcm[x][y] != 1) 
                {
                    exponent++;
                }
                
            }
            else 
            {
                if(y+1 < lcm[x].size()) 
                {
                    if(lcm[x][y+1] != 1) 
                    {
                        TempV2.push_back(exponent);
                        TempV1.push_back(TempV2); 
                        TempV2.clear();
                        TempV2.push_back(lcm[x][y+1]);
                        exponent=1;
                    }
                }
                
                
                else 
                {
                    TempV2.push_back(exponent);
                    TempV1.push_back(TempV2); 
                    TempV2.clear();
                    //TempV2.push_back(lcm[x][y]);
                    exponent=1;
                }
            }
            
        }
        if(TempV1.empty() != false) 
        {
        TempV1.push_back(TempV2); 
        }
        


    }



    for(int x = 0; x < TempV1.size();x++) 
    {
        for(int y = 0;y < TempV1[x].size();y++) 
        {
            std::cout << TempV1[x][y] <<" ";
        }
        std::cout << std::endl;
    }



}