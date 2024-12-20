#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
  int n;
  string prefix;
  cin >> n >> prefix;

  int k = prefix.length();
  int open = 0, close = 0;

  // Count the number of opening and closing brackets in the prefix
  for (char c : prefix) {
    if (c == '(')
      open++;
    else
      close++;
  }

  // If the prefix is already invalid or its length is longer than n
  if (close > open || k > n || open > n / 2) {
    cout << 0 << endl;
    return 0;
  }

  // dp[i][j] represents the number of valid sequences of length i with j more
  // opening than closing brackets
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  dp[k][open - close] = 1; // Starting point after the prefix

  for (int i = k; i < n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (dp[i][j] > 0) {
        if (j + 1 <= n) { // Add an opening bracket
          dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
        }
        if (j > 0) { // Add a closing bracket
          dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % MOD;
        }
      }
    }
  }

  cout << dp[n][0] << endl;
  return 0;
}
