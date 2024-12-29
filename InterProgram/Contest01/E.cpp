#include <iostream>
#include <vector>
#define fast_io                                                                \
  std::ios::sync_with_stdio(0);                                                \
  std::cin.tie(0);                                                             \
  std::cout.tie(0);

using vi = std::vector<int>;

vi s(10001);

int main() {
  fast_io;
  int t;
  std::cin >> t;
  while (t--) {
    int n, m, k, b;
    char x;
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
      std::cin >> x;
      if (x == 'S') {
        s[i] = 0;
      } else {
        s[i] = 1;
      }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
      std::cin >> x;
      if (x == 'W') {
        std::cin >> b;
        if (s[b] == 0) {
          if (b <= k) {
            ans++;
          }
        }
        k = (k > b ? k : b);
      } else if (x == 'A') {
        k = n;
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}
