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


VectorArrayInt Prime_factorization::lcm_MCD_calc(VectorArrayInt lcm_prime_factorization) 
{

    VectorArrayInt lcm_MCD;
    int exponent = 1;   
    for(int x = 0; x < lcm_prime_factorization.size();x++) 
    {
        VectorInt Temp;
        Temp.push_back(lcm_prime_factorization[x][1]); //add a prime number factorized in array
        for(int y = 1; y < lcm_prime_factorization[x].size();y++) 
        {
            if(lcm_prime_factorization[x][y] == lcm_prime_factorization[x][y+1] && y+1 < lcm_prime_factorization[x].size()) 
            {
                if(lcm_prime_factorization[x][y] != 1) 
                {
                    exponent++;
                }
                
            }
            else 
            {
                if(y+1 < lcm_prime_factorization[x].size()) 
                {
                    if(lcm_prime_factorization[x][y+1] != 1) 
                    {
                        Temp.push_back(exponent);
                        lcm_MCD.push_back(Temp); 
                        Temp.clear();
                        Temp.push_back(lcm_prime_factorization[x][y+1]);
                        exponent=1;
                    }
                }
                
                
                else 
                {
                    Temp.push_back(exponent);
                    lcm_MCD.push_back(Temp); 
                    Temp.clear();
                    //Temp.push_back(lcm_prime_factorization[x][y]);
                    exponent=1;
                }
            }
            
        }
        if(lcm_MCD.empty() != false) 
        {
        lcm_MCD.push_back(Temp); 
        }
        


    }
    return lcm_MCD;

}

int Prime_factorization::LCM(VectorInt num ,bool show_calculation_LCM) 
{
    VectorArrayInt lcm_prime_factorization;

    /*structure array example:
    {
     {4 2 2}
     {6 3 3}

     index 0: Number to factor
     Rest of index: Number factored 
    }*/

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
        lcm_prime_factorization.push_back(tempV);
    }

    if(show_calculation_LCM) 
    {
        for(int i = 0; i < lcm_prime_factorization.size();i++) 
        {
            std::cout << lcm_prime_factorization[i][0] << ": ";
                for(int x = 1;x < lcm_prime_factorization[i].size();x++) 
                {
                    std::cout << lcm_prime_factorization[i][x] << " ";
                    
                }
            std::cout << std::endl;
        }
    }

    VectorArrayInt lcm_calc = lcm_MCD_calc(lcm_prime_factorization);


    for(int x = 0; x < lcm_calc.size();x++) 
    {
        int x2 = x;
        int y = 0;
      
        while (x2 < lcm_calc.size())
        {
            if(x2+1 < lcm_calc.size()) 
            {
            
            if(lcm_calc[x][y] == lcm_calc[x2+1][y]) 
            {
                if(lcm_calc[x][y+1] > lcm_calc[x2+1][y+1]) 
                {
                    lcm_calc[x2+1][y] = 0;
                    lcm_calc[x2+1][y+1] = 0;
                }
                
                else if(lcm_calc[x][y+1] < lcm_calc[x2+1][y+1])
                {
                    lcm_calc[x][y] = 0;
                    lcm_calc[x][y+1] = 0;
                    break;
                }
                
                else if(lcm_calc[x][y+1] == lcm_calc[x2+1][y+1])
                {
                    lcm_calc[x][y] = 0;
                    lcm_calc[x][y+1] = 0;
                    break;                    
                }
            }
            }
            x2++;
        }
        
    }

    int result = 1;
    
    for (int x = 0; x < lcm_calc.size(); x++) 
    {
        result = result * pow(lcm_calc[x][0],lcm_calc[x][1]);
    }

    return result;
    

}