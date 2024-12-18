#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int LIMIT = 1e6;

vector<long long> fact(LIMIT + 1);
vector<long long> inv_fact(LIMIT + 1);

long long power(long long x, long long y, long long mod) {
  long long result = 1;
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

long long binom(int a, int b) {
  if (b > a || b < 0)
    return 0;
  return fact[a] * inv_fact[b] % MOD * inv_fact[a - b] % MOD;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  precompute();

  int n;
  cin >> n;

  while (n--) {
    int a, b;
    cin >> a >> b;
    cout << binom(a, b) << '\n';
  }

  return 0;
}
