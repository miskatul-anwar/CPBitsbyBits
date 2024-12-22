// Snippet code to efficiently calculate a^b
#include <iostream>
using ll = long long;
const ll mod = 1e7;
ll power(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      res = res * a;
    }
    a = a * a;
    b /= 2;
  }
  return res;
}

ll power_mod(ll a, ll b, ll mod) {
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

int main() {
  ll a, b;
  std::cin >> a >> b;
  std::cout << power(a, b) << '\n';
  std::cout << power_mod(a, b, mod) << '\n';
  return 0;
}
