#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

// Function to calculate power in O(log y)
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

// Function to compute factorial and modular inverse up to maxN
void precomputeFactorials(int maxN, vector<long long> &fact,
                          vector<long long> &invFact) {
  fact[0] = invFact[0] = 1;
  for (int i = 1; i <= maxN; ++i) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  invFact[maxN] = power(fact[maxN], MOD - 2, MOD);
  for (int i = maxN - 1; i >= 1; --i) {
    invFact[i] = invFact[i + 1] * (i + 1) % MOD;
  }
  invFact[0] = 1;
}

// Function to calculate nCr % MOD
long long binomialCoefficient(int n, int k, const vector<long long> &fact,
                              const vector<long long> &invFact) {
  if (k > n || k < 0)
    return 0;
  return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<long long> fact(m + 1), invFact(m + 1);
  precomputeFactorials(m, fact, invFact);

  long long result = 0;
  // Calculate the result using combinatorial logic
  for (int i = 1; i <= n - 1; ++i) {
    long long ways = binomialCoefficient(m, i, fact, invFact);
    ways = ways * binomialCoefficient(m - i, n - i - 1, fact, invFact) % MOD;
    ways = ways * fact[n - 1] % MOD;
    result = (result + ways) % MOD;
  }

  cout << result << endl;

  return 0;
}
