#include <cmath>
#include <iomanip>
#include <iostream>
#define fast_io                                                                \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(nullptr);

using namespace std;

double comb(int n, int k) {
  if (k > n)
    return 0;
  if (k == 0 || k == n)
    return 1;
  double res = 1;
  for (int i = 1; i <= k; ++i) {
    res *= (n - i + 1);
    res /= i;
  }
  return res;
}

int main() {
  fast_io;
  string s1, s2;
  cin >> s1 >> s2;

  int target = 0;
  for (char c : s1) {
    if (c == '+')
      target++;
    else if (c == '-')
      target--;
  }

  int current = 0, num_unrecognized = 0;
  for (char c : s2) {
    if (c == '+')
      current++;
    else if (c == '-')
      current--;
    else if (c == '?')
      num_unrecognized++;
  }

  int required_difference = target - current;

  if ((required_difference + num_unrecognized) % 2 != 0 ||
      abs(required_difference) > num_unrecognized) {
    cout << fixed << setprecision(12) << 0.0 << '\n';
    return 0;
  }

  int num_plus_needed = (required_difference + num_unrecognized) / 2;

  if (num_plus_needed < 0 || num_plus_needed > num_unrecognized) {
    cout << fixed << setprecision(12) << 0.0 << '\n';
    return 0;
  }

  double valid_ways = comb(num_unrecognized, num_plus_needed);
  double total_ways = pow(2, num_unrecognized);
  double probability = valid_ways / total_ways;

  cout << fixed << setprecision(12) << probability << '\n';

  return 0;
}
