#include <iostream>
#include "mcm_MCD.hh"

int main () {
Prime_factorization test;
for (auto i : test.prime_factorization(150)) 
{
    std::cout << i << std::endl;
}


for (auto i : test.get_dividend_prime_factorization()) 
{
    std::cout << i << std::endl;
}

}