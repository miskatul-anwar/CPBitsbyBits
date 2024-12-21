#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<char>> grid(n, vector<char>(m));
  vector<pair<int, int>> stars;

  // Read the grid and store positions of '*'
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> grid[i][j];
      if (grid[i][j] == '*') {
        stars.emplace_back(i, j);
      }
    }
  }

  int count = 0;
  // Count right triangles
  for (int i = 0; i < stars.size(); ++i) {
    for (int j = i + 1; j < stars.size(); ++j) {
      int x1 = stars[i].first, y1 = stars[i].second;
      int x2 = stars[j].first, y2 = stars[j].second;
      if (x1 == x2 || y1 == y2) {
        // Check if they can form the right angle of a triangle
        if (grid[x1][y2] == '*' && grid[x2][y1] == '*') {
          count++;
        }
      }
    }
  }

  cout << count << endl;
  return 0;
}
