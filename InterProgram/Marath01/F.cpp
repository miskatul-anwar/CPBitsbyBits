#include <iostream>
#include <vector>
#define fast_io                                                                \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(nullptr);
using ll = long long;
using vll = std::vector<long long>;
using namespace std;

const int lim = 1e6;
const ll MOD = 1e9 + 7;
vll derangements(lim + 1, 0);

void countDerangements() {
  derangements[0] = 1;
  derangements[1] = 0;

  for (int i = 2; i <= lim; ++i) {
    derangements[i] =
        (i - 1) * (derangements[i - 1] + derangements[i - 2]) % MOD;
  }
}

int main() {
  fast_io countDerangements();
  int n;
  cin >> n;
  cout << derangements[n] << '\n';
  return 0;
}
