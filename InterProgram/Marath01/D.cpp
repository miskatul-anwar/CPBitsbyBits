#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

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

// Function to compute nCr % p using Fermat's little theorem
long long modInverse(long long n, long long p) { return power(n, p - 2, p); }

long long nCrModPFermat(long long n, long long r, long long p) {
  if (r == 0)
    return 1;
  vector<long long> fac(n + 1, 1);
  for (long long i = 2; i <= n; i++) {
    fac[i] = fac[i - 1] * i % p;
  }
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}

int main() {
  int n;
  cin >> n;

  if (n % 2 != 0) {
    cout << 0 << endl;
    return 0;
  }

  int k = n / 2;

  // Calculate the k-th Catalan number
  long long catalan = nCrModPFermat(2 * k, k, MOD);
  catalan = (catalan * modInverse(k + 1, MOD)) % MOD;

  cout << catalan << endl;
  return 0;
}
