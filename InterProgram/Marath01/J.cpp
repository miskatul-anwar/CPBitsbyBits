#include <algorithm>
#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;

// Modular exponentiation
ll mod_exp(ll base, ll exp, ll mod) {
  ll result = 1;
  while (exp > 0) {
    if (exp % 2 == 1)
      result = (result * base) % mod;
    base = (base * base) % mod;
    exp /= 2;
  }
  return result;
}

// Precompute factorials and modular inverses
void precompute_factorials(vector<ll> &fact, vector<ll> &invFact, int max_n) {
  fact[0] = 1;
  for (int i = 1; i <= max_n; ++i) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  invFact[max_n] = mod_exp(fact[max_n], MOD - 2, MOD);
  for (int i = max_n - 1; i >= 0; --i) {
    invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
  }
}

// Compute nCr % MOD according to Fermat's theorem
ll nCr(ll n, ll r, const vector<ll> &fact, const vector<ll> &invFact) {
  if (r > n || r < 0)
    return 0;
  return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

int main() {
  int max_n = 10000;
  vector<ll> fact(max_n + 1), invFact(max_n + 1);
  precompute_factorials(fact, invFact, max_n);

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; ++tc) {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
      cin >> a[i];
    }

    // Sort the array
    sort(a.begin(), a.end());

    ll result = 0;
    for (int i = 0; i < N; ++i) {
      // Contribution of a[i] as the maximum
      ll left_combinations = nCr(i, K - 1, fact, invFact);
      result = (result + left_combinations * a[i]) % MOD;
    }

    cout << "Case #" << tc << ": " << result << endl;
  }
  return 0;
}
