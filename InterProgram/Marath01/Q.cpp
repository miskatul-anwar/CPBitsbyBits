#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

// Function to compute factorial and modular inverses
vector<long long> fact(1001, 1), invFact(1001, 1);

long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1)
      res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}

void precomputeFactorials() {
  for (int i = 2; i <= 1000; ++i) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  invFact[1000] = power(fact[1000], MOD - 2, MOD);
  for (int i = 999; i >= 1; --i) {
    invFact[i] = invFact[i + 1] * (i + 1) % MOD;
  }
}

long long binomialCoefficient(int n, int k) {
  if (k > n)
    return 0;
  return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

int main() {
  precomputeFactorials();

  int n, k;
  cin >> n >> k;

  long long result = 0;
  for (int i = n - k; i <= n; ++i) {
    long long term = binomialCoefficient(n, i);
    long long derangements = 1;
    for (int j = 0; j < n - i; ++j) {
      derangements = (derangements * (n - i - j)) % MOD;
    }
    if ((n - i) % 2 == 1)
      term = (term - derangements + MOD) % MOD;
    else
      term = (term + derangements) % MOD;
    result = (result + term) % MOD;
  }

  cout << result << endl;

  return 0;
}
