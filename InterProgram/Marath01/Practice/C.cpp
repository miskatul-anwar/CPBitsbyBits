#include <iostream>
#include <vector>
#define fast_io                                                                \
  std::ios::sync_with_stdio(false);                                            \
  std::cin.tie(nullptr);
using ll = long long;
using vll = std::vector<long long>;

const ll mod = 1e9 + 7;
const ll lim = 1e6 + 1;
vll fact(lim + 1);
vll inv_fact(lim + 1);

ll power(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
    b /= 2;
  }
  return res;
}

void precompute() {
  fact[0] = 1;
  for (int i = 1; i <= lim; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
  inv_fact[lim] = power(fact[lim], mod - 2);
  for (int i = lim - 1; i >= 0; i--) {
    inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
  }
}

ll nCr(ll n, ll r) {
  if (r > n)
    return 0;
  if (r == 0 || r == n)
    return 1;
  return (fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod) % mod;
}

int main(int argc, char *argv[]) {
  fast_io precompute();

  ll n, m;
  std::cin >> n >> m;
  std::cout << nCr(n + m - 1, m) << '\n';

  return 0;
}
