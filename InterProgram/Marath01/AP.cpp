#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MOD = 1000000007;

long long fact[1000006], invFact[1000006];

// Function to compute power in O(log y)
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

// Function to precompute factorials and inverse factorials
void precomputeFactorials(int n) {
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  invFact[n] = power(fact[n], MOD - 2, MOD);
  for (int i = n - 1; i >= 0; --i) {
    invFact[i] = invFact[i + 1] * (i + 1) % MOD;
  }
}

// Function to count permutations in range
long long countPerms(string &a, string &b, vector<int> &freq) {
  long long count = 0, totalPerms = fact[a.length()];
  for (int i = 0; i < 26; ++i) {
    totalPerms = totalPerms * invFact[freq[i]] % MOD;
  }

  for (int i = 0; i < a.length(); ++i) {
    for (char ch = a[i] + 1; ch < b[i]; ++ch) {
      if (freq[ch - 'a'] > 0) {
        count = (count + totalPerms * freq[ch - 'a'] % MOD *
                             invFact[a.length() - i - 1] % MOD) %
                MOD;
      }
    }
    if (freq[a[i] - 'a'] == 0)
      break;
    freq[a[i] - 'a']--;
    totalPerms = totalPerms * fact[freq[a[i] - 'a'] + 1] % MOD *
                 invFact[freq[a[i] - 'a']] % MOD;
  }

  return count;
}

int main() {
  string a, b;
  cin >> a >> b;

  int n = a.length();
  precomputeFactorials(n);

  vector<int> freq(26, 0);
  for (char ch : a) {
    freq[ch - 'a']++;
  }

  cout << countPerms(a, b, freq) << endl;

  return 0;
}
