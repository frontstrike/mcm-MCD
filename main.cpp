#include <iostream>
#include "mcm_MCD.hh"

int main () {
Prime_factorization test;

int t;
std::cin >> t;
std::vector <int> tmp;
tmp.push_back(t);
std::cin >> t;
tmp.push_back(t);

/*
for (auto i : test.prime_factorization(t)) 
{
    std::cout << i << std::endl;
}


for (auto i : test.get_dividend_prime_factorization()) 
{
    std::cout << i << std::endl;
}
*/
test.LCM(tmp,false);
}