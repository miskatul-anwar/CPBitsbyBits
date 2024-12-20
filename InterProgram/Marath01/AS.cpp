#include <iostream>
using namespace std;
typedef unsigned long long ull;
const int MOD = 1000000007;

int countSetBits(ull n) {
  int count = 0;
  while (n) {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    ull n;
    cin >> n;

    ull total = n + 1;

    int setBitsCount = countSetBits(n);

    ull oddCount = 1ULL << setBitsCount;

    ull evenCount = total - oddCount;

    cout << evenCount % MOD << '\n';
  }
  return 0;
}
