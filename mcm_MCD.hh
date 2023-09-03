#include <vector>

class Prime_factorization {

private:
typedef std::vector<int> VectorInt;
typedef std::vector<std::vector<int>> VectorArrayInt;

VectorInt dividend_prime_factorization;
VectorInt prime_factors;


//Erase array dividend_prime_factorization and prime_factors
void erase_array_factor();

public:
VectorInt prime_factorization(int num);
VectorInt get_dividend_prime_factorization();
void LCM(VectorInt num ,bool show_calculation_LCM);

};