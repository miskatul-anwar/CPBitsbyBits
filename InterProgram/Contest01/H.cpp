#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>
#define fast_io                                                                \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0);
using namespace std;
using ll = long long;
using vi = vector<int>;

int main() {
  fast_io;
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    string a, b;
    cin >> a >> b;
    vector<set<char>> bf(130);
    for (int i = k - 1; i < n; i++) {
      bf[a[i]].insert(a[i - k + 1]);
    }

    ll r = 0;
    vi cnt(130);
    for (int i = 0; i < m; ++i) {
      cnt[b[i]]++;
      for (auto &j : bf[b[i]])
        r += cnt[j];
    }
    cout << r << endl;
  }
}
