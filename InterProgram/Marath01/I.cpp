#include <iostream>
typedef long long ll;
const int MOD = 1e9 + 7;

// Function to compute x^y % p in O(log y)
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

// Function to compute nCr % p using Fermat's little theorem
ll modInverse(ll n, ll p) { return power(n, p - 2, p); }

ll factorialMod(ll n, ll p) {
  ll res = 1;
  for (ll i = 2; i <= n; ++i) {
    res = (res * i) % p;
  }
  return res;
}

int main() {
  int N, W, T, R;
  std::cin >> N >> W >> T >> R;

  if (W + T + R != N) {
    std::cout << 0 << '\n';
  } else {

    ll factorial_N = factorialMod(N, MOD);
    ll factorial_W = factorialMod(W, MOD);
    ll factorial_T = factorialMod(T, MOD);
    ll factorial_R = factorialMod(R, MOD);

    ll result = factorial_N;
    result = (result * modInverse(factorial_W, MOD)) % MOD;
    result = (result * modInverse(factorial_T, MOD)) % MOD;
    result = (result * modInverse(factorial_R, MOD)) % MOD;

    std::cout << result << '\n';
  }
  return 0;
}
