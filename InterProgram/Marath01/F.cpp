#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

const ll MOD = 1e9 + 7;

ll countDerangements(int n) {
  if (n == 0)
    return 1;
  if (n == 1)
    return 0;

  vector<ll> derangements(n + 1, 0);
  derangements[0] = 1;
  derangements[1] = 0;

  for (int i = 2; i <= n; ++i) {
    derangements[i] =
        (i - 1) * (derangements[i - 1] + derangements[i - 2]) % MOD;
  }

  return derangements[n];
}

int main() {
  int n;
  cin >> n;
  cout << countDerangements(n) << '\n';
  return 0;
}
