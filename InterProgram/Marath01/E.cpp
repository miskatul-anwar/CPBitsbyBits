#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n;
  string prefix;
  cin >> n >> prefix;

  int k = prefix.length();
  int open = 0, close = 0;

  for (char ch : prefix) {
    if (ch == '(')
      open++;
    else
      close++;
  }

  if (close > open || open > n / 2) {
    cout << 0 << endl;
    return 0;
  }

  vector<vector<int>> bracketSequences(n + 1, vector<int>(n + 1, 0));
  bracketSequences[k][open] = 1;

  for (int i = k; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (bracketSequences[i][j] > 0) {
        if (j + 1 <= n / 2) {
          bracketSequences[i + 1][j + 1] =
              (bracketSequences[i + 1][j + 1] + bracketSequences[i][j]) % MOD;
        }
        if (j > 0) {
          bracketSequences[i + 1][j - 1] =
              (bracketSequences[i + 1][j - 1] + bracketSequences[i][j]) % MOD;
        }
      }
    }
  }

  cout << bracketSequences[n][0] << endl;
  return 0;
}
