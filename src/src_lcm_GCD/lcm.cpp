/* lcm.cpp program that allows you to calculate the lcm.

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
#include "../lcm_GCD.hh"

bool check_number(std::string str) 
{
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false)
   {
      return false;
   }
 return true;
}



int main(int argc, char *argv[]) 
{
    Prime_factorization lcm;
    std::vector <int> number;
    bool show_calculation = false;
    if(argc <= 2) 
    {

        std::cout << "Please enter two numbers" << std::endl;

        std::cout << "program that calculates the lcm" << std::endl;
               
        std::cout << std::endl;

        std::cout << "-h show the options" << std::endl;
        std::cout << "-n show the factorization" << std::endl;

        std::cout << std::endl;

        std::cout << "Version: 1.0" << std::endl;
        std::cout << "Report bug at https://github.com/frontstrike/mcm-MCD " << std::endl;

        return -1;
    }

    for (int i = 1; i < argc; i++) {
        if(check_number(argv[i]) == true)
        {
            int x = atoi(argv[i]);
            number.push_back(x);
        }
        else 
        {
            std::string arg = argv[i];
            if(arg == "-n") 
            {
                show_calculation = true;
            }

            else if(arg == "-h") 
            {
               std::cout << "program that calculates the lcm" << std::endl;
               
               std::cout << std::endl;

               std::cout << "-h show the options" << std::endl;
               std::cout << "-n show the factorization" << std::endl;

               std::cout << std::endl;

               std::cout << "Version: 1.0" << std::endl;
               std::cout << "Report bug at https://github.com/frontstrike/mcm-MCD " << std::endl;

            }  

            else 
            {
                std::cout << "option not valide" << std::endl;
            }
        }
    }
    std::cout << lcm.LCM(number,show_calculation) << std::endl;

    return 0;
    
}