/* gcd.cpp program that allows you to calculate the GCD.

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