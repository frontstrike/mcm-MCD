#include <vector>

typedef std::vector<int> VectorInt;


class Prime_factorization {

private:
VectorInt dividend_prime_factorization;
VectorInt prime_factors;


public:
VectorInt prime_factorization(int num);
VectorInt get_dividend_prime_factorization();
void LCM(int num ,bool show_calculation_LCM);
};