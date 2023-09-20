#include <iostream>
#include "lcm_GCD.hh"

int main(int argc, char *argv[]) 
{
    Prime_factorization gcd;
    std::vector <int> number;

    if(argc <= 2) 
    {
        std::cout << "Please enter two numbers" << std::endl;
        return -1;
    }

    for (int i = 1; i < argc; i++) {
        int x = atoi(argv[i]);
        number.push_back(x);
    }
    std::cout << gcd.GCD(number,true) << std::endl;

    return 0;
    
}

//https://www.youmath.it/domande-a-risposte/view/6654-algoritmo-euclide.html