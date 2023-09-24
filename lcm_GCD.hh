/* lcm_GCD.hh  header declaring class,methods and variable.

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



#include <vector>

class Prime_factorization {

private:
    typedef std::vector<int> VectorInt;
    typedef std::vector<std::vector<int>> VectorArrayInt;

    VectorInt dividend_prime_factorization;
    VectorInt prime_factors;
    /*
        The calculation of the LCM and the GCD is carried out using the Euclid algorithm. 
        If you want to know more about how it works, consult the internet 
        or if you know Italian, use this site: 
        https://www.youmath.it/domande-a- answers/view/6654-algorithm-euclide.html
    */
    int lcm_calc(int a, int b);
    int GCD_calculate(int a,int b);


public:
    VectorInt prime_factorization(int num);

    VectorInt get_dividend_prime_factorization();
    VectorInt get_prime_factors();

    int LCM(VectorInt num ,bool show_calculation_LCM = false);
    int GCD(VectorInt num , bool show_calculation_GCD = false);
};