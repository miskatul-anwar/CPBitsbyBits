#include <iostream>
#include <vector>
#define fast_io                                                                \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(nullptr);
using vi = std::vector<int>;

const int lim = 12;
vi derangements(lim + 1);
vi factorial(lim + 1);

void precompute() {

  derangements[0] = 1;
  derangements[1] = 0;
  for (int i = 2; i <= lim; ++i) {
    derangements[i] = (i - 1) * (derangements[i - 1] + derangements[i - 2]);
  }

  factorial[0] = 1;
  for (int i = 1; i <= lim; i++) {
    factorial[i] = factorial[i - 1] * i;
  }
}

int main() {
  fast_io precompute();
  int n, t;
  std::cin >> t;
  while (t--) {
    std::cin >> n;
    std::cout << derangements[n] << "/" << factorial[n] << '\n';
  }
  return 0;
}
