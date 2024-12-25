#include <iostream>
#define fast_io                                                                \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(nullptr);

using ll = long long;
int main() {
  fast_io;
  int t;
  std::cin >> t;
  ll n, x, y;
  while (t--) {
    std::cin >> n >> x >> y;
    ll black = n / 2 + 1;
    ll white = n - black;
    if (x >= black and y >= white) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
  return 0;
}
