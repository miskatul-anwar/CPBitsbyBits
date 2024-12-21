#include <iostream>
#include <string>
#include <vector>
#define fast_io                                                                \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(NULL);                                                          \
  std::cout.tie(NULL);
using ll = long long;
using namespace std;

int main() {
  fast_io ll a;
  string s;
  cin >> a >> s;
  int n = s.size();

  vector<vector<int>> b(n, vector<int>(n));

  // Compute the matrix b
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      b[i][j] = (s[i] - '0') * (s[j] - '0');
    }
  }

  // Count rectangles with sum equal to a
  int count = 0;

  // Use nested loops to consider all rectangles
  for (int x1 = 0; x1 < n; ++x1) {
    for (int y1 = 0; y1 < n; ++y1) {
      for (int x2 = x1; x2 < n; ++x2) {
        for (int y2 = y1; y2 < n; ++y2) {
          ll sum = 0;
          for (int i = x1; i <= x2; ++i) {
            for (int j = y1; j <= y2; ++j) {
              sum += b[i][j];
            }
          }
          if (sum == a) {
            count++;
          }
        }
      }
    }
  }

  cout << count << '\n';
  return 0;
}
