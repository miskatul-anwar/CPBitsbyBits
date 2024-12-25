#include <iomanip>
#include <iostream>
#include <vector>

#define fast_io                                                                \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(nullptr);

using vi = std::vector<int>;
using vvi = std::vector<vi>;

vvi adj;
std::vector<bool> visited;

double dfs(int node) {
  visited[node] = true;
  double total = 0.0;
  int count = 0;

  for (int neighbor : adj[node]) {
    if (!visited[neighbor]) {
      total += dfs(neighbor) + 1;
      count++;
    }
  }

  if (count == 0)
    return 0.0;

  return total / count;
}

int main() {
  fast_io;
  int n;
  std::cin >> n;

  adj.resize(n + 1);
  visited.resize(n + 1, false);
  int v, u;
  for (int i = 0; i < n - 1; i++) {
    std::cin >> v >> u;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }

  double expected_length = dfs(1);

  std::cout << std::fixed << std::setprecision(15) << expected_length << '\n';

  return 0;
}
