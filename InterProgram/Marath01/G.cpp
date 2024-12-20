#include <iostream>
#include <vector>

#define fast                                                                   \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(NULL);                                                          \
  std::cout.tie(NULL);

#define MOD 1000000007
typedef long long ll;

const int lines = 1e4;

ll mod_expo(ll base, ll exp, ll mod) {
  ll result = 1;
  while (exp > 0) {
    if (exp % 2 == 1)
      result = (result * base) % mod;
    base = (base * base) % mod;
    exp /= 2;
  }
  return result;
}

void precomp(std::vector<ll> &fact, std::vector<ll> &invFact, int max_n) {
  fact[0] = 1;
  for (int i = 1; i <= max_n; ++i) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  invFact[max_n] = mod_expo(fact[max_n], MOD - 2, MOD);
  for (int i = max_n - 1; i >= 0; --i) {
    invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
  }
}

// Compute nCr % MOD
ll nCr(ll n, ll r, const std::vector<ll> &fact,
       const std::vector<ll> &invFact) {
  if (r > n || r < 0)
    return 0;
  return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

int main() {
  fast;
  int max_n = 1000000;
  std::vector<ll> fact(max_n + 1), invFact(max_n + 1);
  precomp(fact, invFact, max_n);

  ll N, A, B, D;
  for (int i = 1; i <= lines; i++) {
    std::cin >> N >> A >> B >> D;
    ll choose_schools = nCr(N, A, fact, invFact);
    ll choose_students_per_school = nCr(B, D, fact, invFact);

    ll stdnt_comb = mod_expo(choose_students_per_school, A, MOD);

    ll result = (choose_schools * stdnt_comb) % MOD;
    std::cout << result << '\n';
  }
  return 0;
}
