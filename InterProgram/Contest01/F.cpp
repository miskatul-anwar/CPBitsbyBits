#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>

#define fast_io                                                                \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0);
using ll = long long;
using vi = std::vector<int>;

using namespace std;
int main() {
  fast_io;
  int t;
  cin >> t;
  while (t--) {
    vi num(26);
    for (int i = 0; i < 26; ++i) {
      cin >> num[i];
    }
    sort(num.rbegin(), num.rend());

    int l = 0, sz = INT_MAX;
    if (num[0] == 0)
      sz = 0;
    for (int i = 0; i < 26; ++i) {
      if (num[i] >= 2) {
        l += 2;
        sz = min(sz, num[i] / 2);
      } else if (num[i] == 1) {
        l++;
        int cnt = 0;
        for (int j = i; j < 26; ++j) {
          cnt += num[j];
        }
        sz = min(sz, cnt);
        break;
      }
    }
    cout << l << " " << sz << endl;
  }
}
