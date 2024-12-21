#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
  int N, x, y;
  cin >> N >> x >> y;

  if (x + y > N) {
    cout << 0 << endl;
    return 0;
  }

  vector<vector<vector<vector<int>>>> dp(
      N + 1, vector<vector<vector<int>>>(
                 x + 1, vector<vector<int>>(y + 1, vector<int>(4, 0))));

  dp[1][1][0][1] = 1; // Start with P_1 = 1
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j <= x; ++j) {
      for (int k = 0; k <= y; ++k) {
        for (int l = 1; l <= 3; ++l) {
          if (dp[i][j][k][l] == 0)
            continue;
          if (l != 1 && j + 1 <= x)
            dp[i + 1][j + 1][k][1] =
                (dp[i + 1][j + 1][k][1] + dp[i][j][k][l]) % MOD;
          if (l != 2 && k + 1 <= y)
            dp[i + 1][j][k + 1][2] =
                (dp[i + 1][j][k + 1][2] + dp[i][j][k][l]) % MOD;
          if (l != 3)
            dp[i + 1][j][k][3] = (dp[i + 1][j][k][3] + dp[i][j][k][l]) % MOD;
        }
      }
    }
  }

  cout << dp[N][x][y][1] << endl;

  return 0;
}
