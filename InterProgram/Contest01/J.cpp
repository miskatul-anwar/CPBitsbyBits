#include <iostream>

#define fast_io                                                                \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(nullptr);

using ll = long long;

int calc(ll i, ll j) {
  if (j <= -1 or j > i) {
    return 0;
  } else if (i == 0 and j == 0) {
    return 1;
  }
  return calc(i - 1, j - 1) + calc(i - 1, j);
}

int main() {
  fast_io;
  int t;
  ll n;
  std::cin >> t;
  while (t--) {
    ll cnt = 0;
    std::cin >> n;
    for (int m = 0; m <= n; m++) {
      if (calc(n, m) % 2 == 0) {
        cnt++;
      }
    }
    std::cout << cnt << '\n';
  }
  return 0;
}
