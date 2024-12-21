#include <iostream>
#include <vector>

const int MAX_N = 20;
const int MOD = 1000000007;
using ll = long long;

std::vector<ll> fact(MAX_N + 1, 1);

void precomputeFactorials() {
  for (int i = 2; i <= MAX_N; ++i) {
    fact[i] = fact[i - 1] * i;
  }
}

ll binomialCoefficient(int n, int k) {
  return fact[n] / (fact[k] * fact[n - k]);
}

int main() {
  precomputeFactorials();

  int n;
  std::cin >> n;

  int half = n / 2;
  ll waysToChooseHalf = binomialCoefficient(n, half);
  ll waysToArrangeHalf = fact[half - 1];

  ll result = (waysToChooseHalf / 2) * (waysToArrangeHalf * waysToArrangeHalf);

  std::cout << result << '\n';

  return 0;
}
