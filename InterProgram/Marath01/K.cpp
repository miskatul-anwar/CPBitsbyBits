#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

const int MOD = 998244353;

vector<long long> fact, invFact;

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
void precomputeFactorials(int n) {
  fact.resize(n + 1);
  invFact.resize(n + 1);
  fact[0] = invFact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  invFact[n] = power(fact[n], MOD - 2, MOD);
  for (int i = n - 1; i >= 1; --i) {
    invFact[i] = invFact[i + 1] * (i + 1) % MOD;
  }
}

// Function to compute binomial coefficient
long long binomialCoefficient(int n, int k) {
  if (k > n)
    return 0;
  return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    // We will implement the DP approach here
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = 1; // Base case

    for (int i = 1; i <= n; ++i) {
      for (int g = 1; g <= m; ++g) {
        for (int x = 1; x <= m; ++x) {
          if (__gcd(g, x) == a[i - 1]) {
            dp[i][x] = (dp[i][x] + dp[i - 1][g]) % MOD;
          }
        }
      }
    }

    int result = 0;
    for (int i = 1; i <= m; ++i) {
      result = (result + dp[n][i]) % MOD;
    }

    cout << result << endl;
  }

  return 0;
}
