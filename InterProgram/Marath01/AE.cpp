#include <iostream>
#include <vector>
#define fast                                                                   \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(NULL);                                                          \
  std::cout.tie(NULL);

using ll = long long;

const int MOD = 1000000007;
const int MAX = 200000; // Since 2*(10^5) is the maximum factorial we will need

std::vector<ll> fact(MAX + 1), invFact(MAX + 1);

ll power(ll x, ll y, ll p) {
  ll res = 1;
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
  fact[0] = invFact[0] = 1;
  for (int i = 1; i <= MAX; ++i) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  invFact[MAX] = power(fact[MAX], MOD - 2, MOD);
  for (int i = MAX - 1; i >= 1; --i) {
    invFact[i] = invFact[i + 1] * (i + 1) % MOD;
  }
}

ll binomialCoefficient(int n, int k) {
  if (k > n || k < 0)
    return 0;
  return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

int main() {
  fast precomputeFactorials();
  int t;
  std::cin >> t;
  while (t--) {
    int N, M, O_R, O_C;
    std::cin >> N >> M >> O_R >> O_C;

    ll totalPaths = binomialCoefficient(N + M - 2, N - 1);
    ll pathsThroughObstacle =
        (binomialCoefficient(O_R + O_C - 2, O_R - 1) *
         binomialCoefficient((N - O_R) + (M - O_C), N - O_R)) %
        MOD;

    ll validPaths = (totalPaths - pathsThroughObstacle + MOD) % MOD;
    std::cout << validPaths << '\n';
  }
  return 0;
}
