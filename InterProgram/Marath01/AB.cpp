#include <iostream>
#include <vector>
#define fast_io                                                                \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(NULL);                                                          \
  std::cout.tie(NULL);
using ll = long long;
using namespace std;

const int MOD = 1000000007;

int main() {
  fast_io int t;
  cin >> t;
  while (t--) {
    fast_io int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    // Calculate the bitwise AND of the entire array
    int total_and = a[0];
    for (int i = 1; i < n; ++i) {
      total_and &= a[i];
    }

    // Count the number of elements equal to the bitwise AND
    int count = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == total_and) {
        count++;
      }
    }

    // If there are fewer than two elements equal to the bitwise AND, no good
    // permutation exists
    if (count < 2) {
      cout << 0 << '\n';
      continue;
    }

    // Calculate the number of permutations
    ll result = 1;
    for (int i = 1; i <= n - 2; ++i) {
      result = (result * i) % MOD;
    }
    result = (result * count * (count - 1)) % MOD;

    cout << result << '\n';
  }

  return 0;
}
