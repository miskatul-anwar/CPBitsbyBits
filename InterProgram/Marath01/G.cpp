#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

// Modular exponentiation
long long mod_exp(long long base, long long exp, long long mod) {
  long long result = 1;
  while (exp > 0) {
    if (exp % 2 == 1) {
      result = (result * base) % mod;
    }
    base = (base * base) % mod;
    exp /= 2;
  }
  return result;
}

// Precompute factorials and modular inverses
void precompute_factorials(vector<long long> &fact, vector<long long> &invFact,
                           int max_n) {
  fact[0] = 1;
  for (int i = 1; i <= max_n; ++i) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  invFact[max_n] = mod_exp(fact[max_n], MOD - 2, MOD);
  for (int i = max_n - 1; i >= 0; --i) {
    invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
  }
}

// Compute nCr % MOD
long long nCr(long long n, long long r, const vector<long long> &fact,
              const vector<long long> &invFact) {
  if (r > n || r < 0)
    return 0;
  return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

int main() {
  int max_n = 1000000;
  vector<long long> fact(max_n + 1), invFact(max_n + 1);
  precompute_factorials(fact, invFact, max_n);

  int t;
  cin >> t;
  while (t--) {
    long long N, A, B, D;
    cin >> N >> A >> B >> D;

    // Compute combinations
    long long comb_schools = nCr(N, A, fact, invFact);  // C(N, A)
    long long comb_students = nCr(B, D, fact, invFact); // C(B, D)
    long long result = (comb_schools * mod_exp(comb_students, A, MOD)) % MOD;

    cout << result << endl;
  }
  return 0;
}
