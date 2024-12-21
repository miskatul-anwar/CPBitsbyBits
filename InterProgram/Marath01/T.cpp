#include <cmath>
#include <iostream>
#include <vector>
#define fast                                                                   \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(NULL);                                                          \
  std::cout.tie(NULL);
typedef long long ll;

int main() {
  fast;
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  if (n > m) {
    // If n > m, the result is 0 due to the pigeonhole principle
    std::cout << 0 << '\n';
    return 0;
  }

  ll result = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      result = (result * abs(a[i] - a[j])) % m;
    }
  }

  std::cout << result << '\n';
  return 0;
}
