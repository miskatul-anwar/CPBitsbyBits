#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#define MOD 1000000007
#define fast_io                                                                \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(nullptr);

using namespace std;

// Function to calculate binomial coefficient C(n, k)
long long binomial_coefficient(int n, int k) {
  vector<vector<long long>> C(n + 1, vector<long long>(k + 1, 0));
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= min(i, k); ++j) {
      if (j == 0 || j == i) {
        C[i][j] = 1;
      } else {
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
      }
    }
  }
  return C[n][k];
}

int main() {
  fast_io;
  int T;
  cin >> T;

  while (T--) {
    int n, m;
    cin >> n >> m;

    long long x = binomial_coefficient(n, m);
    long long y = static_cast<long long>(ceil(log2(x)));

    cout << x % MOD << " " << y % MOD << '\n';
  }

  return 0;
}
