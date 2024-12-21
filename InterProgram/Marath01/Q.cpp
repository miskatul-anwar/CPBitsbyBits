#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

// Function to calculate factorial modulo MOD
vector<long long> compute_factorials(int n) {
  vector<long long> fact(n + 1, 1);
  for (int i = 2; i <= n; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  return fact;
}

// Function to calculate modular exponentiation
long long mod_exp(long long base, long long exp, long long mod) {
  long long result = 1;
  while (exp > 0) {
    if (exp % 2 == 1) {
      result = (result * base) % mod;
    }
    base = (base * base) % mod;
    exp /= 2;
  }
  return result;
}

// Function to calculate binomial coefficient modulo MOD
long long binomial_mod(int n, int k, const vector<long long> &fact) {
  if (k > n)
    return 0;
  long long numerator = fact[n];
  long long denominator = (fact[k] * fact[n - k]) % MOD;
  return (numerator * mod_exp(denominator, MOD - 2, MOD)) %
         MOD; // Modular inverse
}

// Function to calculate derangement D(k)
long long derangement(int k) {
  if (k == 0)
    return 1;
  if (k == 1)
    return 0;
  vector<long long> der(k + 1, 0);
  der[0] = 1;
  der[1] = 0;
  for (int i = 2; i <= k; i++) {
    der[i] = (i - 1) * (der[i - 1] + der[i - 2]) % MOD;
  }
  return der[k];
}

int main() {
  int n, k;
  cin >> n >> k;

  // Precompute factorials modulo MOD
  vector<long long> fact = compute_factorials(n);

  // Compute binomial coefficient and derangement
  long long comb = binomial_mod(n, n - k, fact);
  long long der = derangement(k);

  // Result is the product of the two
  long long result = (comb * der) % MOD;

  cout << result << endl;
  return 0;
}
