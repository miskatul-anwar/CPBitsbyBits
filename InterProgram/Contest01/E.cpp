#include <algorithm>
#include <iostream>
#include <string>
int s[10001];
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, m, a, b;
    std::string x;
    std::cin >> n >> m >> a;
    for (int i = 1; i <= n; i++) {
      std::cin >> x;
      if (x[0] == 'S') {
        s[i] = 0;
      } else {
        s[i] = 1;
      }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
      std::cin >> x;
      if (x[0] == 'W') {
        std::cin >> b;
        if (s[b] == 0) {
          if (b <= a) {
            ans++;
          }
        }
        a = std::max(a, b);
      } else if (x[0] == 'A') {
        a = n;
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}
