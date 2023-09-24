/* test.cpp verify correct functioning of the library

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


#include <iostream>
#include "lcm_GCD.hh"

int main(int argc, char *argv[]) 
{
    Prime_factorization PF;

    std::vector <int> pf;
    std::vector <int> vf;

    for(int x : PF.prime_factorization(12)) 
    {
        pf.push_back(x);
    }
    for(int x : pf) 
    {
        std::cout << x << std::endl;
    }
    std::cout << "--------" << std::endl;

    for(int x : PF.prime_factorization(14)) 
    {
        vf.push_back(x);
    }

    for(int x : vf) 
    {
        std::cout << x << std::endl;
    }
    std::cout << "--------" << std::endl;

    for(int x : PF.get_dividend_prime_factorization()) 
    {
        std::cout << x << std::endl;
    }

    std::cout << "--------" << std::endl;

    for(int x : PF.get_prime_factors()) 
    {
        std::cout << x << std::endl;
    }

    std::cout << "--------" << std::endl;
    
    std::cout << PF.LCM({12,18}) << std::endl;
    std::cout << PF.LCM({18,21}) << std::endl;

    std::cout << "--------" << std::endl;

    std::cout << PF.GCD({12,18}) << std::endl;
    std::cout << PF.GCD({18694,12}) << std::endl;


    return 0;
}