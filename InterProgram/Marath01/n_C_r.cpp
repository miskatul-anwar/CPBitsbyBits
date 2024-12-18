#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAX = 1e6;

vector<ll> factorial(MAX + 1), inv_factorial(MAX + 1);

ll mod_exp(ll base, ll exp, ll mod) {
  ll result = 1;
  while (exp > 0) {
    if (exp % 2 == 1) {
      result = (result * base) % mod;
    }
    base = (base * base) % mod;
    exp /= 2;
  }
  return result;
}

void precompute_factorials() {
  factorial[0] = 1;
  for (int i = 1; i <= MAX; i++) {
    factorial[i] = (factorial[i - 1] * i) % MOD;
  }
  inv_factorial[MAX] = mod_exp(factorial[MAX], MOD - 2, MOD);
  for (int i = MAX - 1; i >= 0; i--) {
    inv_factorial[i] = (inv_factorial[i + 1] * (i + 1)) % MOD;
  }
}

ll binomial_coeff(ll n, ll r) {
  if (r > n)
    return 0;
  return (factorial[n] * inv_factorial[r] % MOD * inv_factorial[n - r] % MOD) %
         MOD;
}

int main() {
  precompute_factorials();
  ll n, r;
  std::cin >> n >> r;
  std::cout << binomial_coeff(n, r) << std::endl;
  return 0;
}
