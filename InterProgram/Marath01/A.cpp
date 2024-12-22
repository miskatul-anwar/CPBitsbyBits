#include "iostream"
#include "vector"
using ll = long long;
#define fast_io                                                                \
  std::ios::sync_with_stdio(false);                                            \
  std::cin.tie(nullptr);
const int MOD = 1e9 + 7;
const int LIMIT = 1e6;

std::vector<ll> fact(LIMIT + 1);
std::vector<ll> inv_fact(LIMIT + 1);

ll power(ll x, ll y, ll mod) {
  ll result = 1;
  while (y > 0) {
    if (y % 2 == 1) {
      result = (result * x) % mod;
    }
    x = (x * x) % mod;
    y /= 2;
  }
  return result;
}

void precompute() {
  fact[0] = 1;
  for (int i = 1; i <= LIMIT; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  inv_fact[LIMIT] = power(fact[LIMIT], MOD - 2, MOD); // Fermat's inverse
  for (int i = LIMIT - 1; i >= 0; i--) {
    inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
  }
}

ll binom(int a, int b) {
  if (b > a || b < 0)
    return 0;
  return fact[a] * inv_fact[b] % MOD * inv_fact[a - b] % MOD;
}

int main() {
  fast_io;
  precompute();

  int n;
  std::cin >> n;

  while (n--) {
    int a, b;
    std::cin >> a >> b;
    std::cout << binom(a, b) << '\n';
  }

  return 0;
}
