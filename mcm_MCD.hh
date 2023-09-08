#include <vector>

class Prime_factorization {

private:
    typedef std::vector<int> VectorInt;
    typedef std::vector<std::vector<int>> VectorArrayInt;

    VectorInt dividend_prime_factorization;
    VectorInt prime_factors;

    //Erase array dividend_prime_factorization and prime_factors
    void erase_array_factor();

    VectorArrayInt lcm_MCD_calc(VectorArrayInt lcm_prime_factorization);

public:
    VectorInt prime_factorization(int num);
    VectorInt get_dividend_prime_factorization();
    int LCM(VectorInt num ,bool show_calculation_LCM = false);

};