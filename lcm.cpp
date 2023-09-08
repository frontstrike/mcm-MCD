#include <iostream>
#include "mcm_MCD.hh"

int main(int argc, char *argv[]) 
{
    Prime_factorization lcm;
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
    std::cout << lcm.LCM(number,true) << std::endl;

    return 0;
    
}