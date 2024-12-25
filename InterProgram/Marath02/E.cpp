#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#define fast_io                                                                \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(nullptr);

using namespace std;

double expected_maximum(int m, int n) {
  double expected_max = 0.0;
  double prob_k = 1;
  for (int k = 1; k <= m; ++k) {
    double prob_k = pow((double)k / m, n) - pow(((double)k - 1) / m, n);
    expected_max += k * prob_k;
  }
  return expected_max;
}

int main() {
  fast_io;
  int m, n;
  cin >> m >> n;
  cout << fixed << setprecision(12) << expected_maximum(m, n) << '\n';
  return 0;
}
