#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

long long factorial[1001], inverse[1001];

// Function to compute power in O(log y)
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

// Function to precompute factorials and inverse factorials
void precomputeFactorials(int maxN, long long mod) {
  factorial[0] = inverse[0] = 1;
  for (int i = 1; i <= maxN; ++i) {
    factorial[i] = factorial[i - 1] * i % mod;
  }
  inverse[maxN] = power(factorial[maxN], mod - 2, mod);
  for (int i = maxN - 1; i >= 1; --i) {
    inverse[i] = inverse[i + 1] * (i + 1) % mod;
  }
}

// Function to compute binomial coefficient
long long binomialCoefficient(int n, int k, long long mod) {
  if (k > n)
    return 0;
  return factorial[n] * inverse[k] % mod * inverse[n - k] % mod;
}

int main() {
  int n, m;
  cin >> n >> m;

  precomputeFactorials(max(n, m), MOD);

  // Count valid arrays a in non-descending order
  long long countA = binomialCoefficient(n + m - 1, m, MOD);

  // Count valid arrays b in non-ascending order
  long long countB = binomialCoefficient(n + m - 1, m, MOD);

  // The result is the product of countA and countB
  long long result = countA * countB % MOD;

  cout << result << endl;

  return 0;
}
