#include <iomanip>
#include <iostream>
#define fast_io                                                                \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(nullptr);

double probability(int a, int b, int c, int d) {
  return (double)(a * d) / ((a * d) + (b * c) - (a * c));
}

int main() {
  fast_io;
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;
  std::cout << std::fixed << std::setprecision(12) << probability(a, b, c, d)
            << '\n';
  return 0;
}
