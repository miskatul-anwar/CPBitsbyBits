#include <iostream>
#include <string>
typedef long long ll;
const int MOD = 998244353;

int main() {
  int n;
  std::string s;
  std::cin >> n >> s;

  int prefixLength = 1;
  while (prefixLength < n && s[prefixLength] == s[0]) {
    prefixLength++;
  }

  int suffixLength = 1;
  while (suffixLength < n && s[n - suffixLength - 1] == s[n - 1]) {
    suffixLength++;
  }

  if (s[0] == s[n - 1]) {
    ll res = (1LL * (prefixLength + 1) * (suffixLength + 1)) % MOD;
    std::cout << res << '\n';
  } else {
    ll res = (prefixLength + suffixLength + 1) % MOD;
    std::cout << res << '\n';
  }

  return 0;
}
