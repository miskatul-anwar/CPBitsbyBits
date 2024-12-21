#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

// Function to compute factorial and modular inverse
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
  invFact[0] = 1;
}

long long binomialCoefficient(int n, int k) {
  if (k > n)
    return 0;
  return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

int main() {
  precomputeFactorials();

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    // Sort the array of followers in descending order
    sort(a.rbegin(), a.rend());

    // Identify the k-th maximum follower count in the sorted list
    int threshold = a[k - 1];

    // Count the number of bloggers with the k-th maximum follower count
    int countThreshold = count(a.begin(), a.end(), threshold);
    int countInK = count(a.begin(), a.begin() + k, threshold);

    // Calculate the number of valid combinations
    long long result = binomialCoefficient(countThreshold, countInK) % MOD;

    cout << result << endl;
  }

  return 0;
}
