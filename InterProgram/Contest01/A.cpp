#include <cmath>
#include <iostream>
#include <vector>
#define fast_io                                                                \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0);
using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi special_number(int n) {
  vi return_val;
  bool neg = n < 0;
  if (neg)
    n = -n;
  string s = to_string(n);
  for (int i = 0; i < s.length(); ++i) {
    int num = (ll(s[i] - '0')) * pow(10, s.length() - 1 - i);
    if (num)
      return_val.push_back(num);
  }
  if (neg)
    for (int i = 0; i < return_val.size(); ++i) {
      return_val[i] = -return_val[i];
    }
  return return_val;
}

int main() {
  fast_io;
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    vi av = special_number(a);
    vi bv = special_number(b);

    for (int i = 0; i < av.size(); ++i) {
      for (int j = 0; j < bv.size(); ++j) {
        if (i || j)
          cout << "+ ";
        cout << av[i] << " x " << bv[j]
             << " \n"[i == av.size() - 1 && j == bv.size() - 1];
      }
    }
  }
}
