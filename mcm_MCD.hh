#include <vector>
class Prime_factorization {

private:
std::vector <int> dividend_prime_factorization;
std::vector <int> prime_factors;

public:
std::vector <int> prime_factorization(int num);
std::vector <int> get_dividend_prime_factorization();
};