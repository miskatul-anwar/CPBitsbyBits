#include <iostream>
#include <string>
#include <vector>
#define fast_io                                                                \
  ios::sync_with_stdio();                                                      \
  cin.tie(0);                                                                  \
  cout.tie(0);
using namespace std;

int main() {
  fast_io;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    vector<pair<int, char>> w;
    for (int i = 0; i < n; ++i)
      if (a[i] != b[i])
        w.emplace_back(i, b[i]);
    for (int i = 0; i < w.size(); ++i)
      b[w[(i + 1) % w.size()].first] = w[i].second;
    if (b == a)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
