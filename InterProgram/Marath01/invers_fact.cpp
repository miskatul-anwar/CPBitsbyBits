#include <exception>
#include <iostream>
#include <vector>

const int M = 1e7; // M is now an integer constant

int main(int argc, char *argv[]) {
  int n;
  std::cin >> n;
  if (n <= 0) {
    std::cout << "Invalid input: n must be greater than 0\n";
    return 1;
  }

  std::vector<int> invFact(n + 1, 0);
  invFact[0] = 1;
  invFact[1] = 1;

  std::vector<int> invModM(n + 1, 0);
  invModM[1] = 1;

  for (int i = 2; i <= n; ++i) {
    invModM[i] = (M - (long long)(M / i) * invModM[M % i] % M) % M;
  }

  for (int i = 2; i <= n; i++) {
    invFact[i] = (long long)(invModM[i] * invFact[i - 1]) % M;
  }

  std::cout << invFact[n] << "\n";
  return 0;
}
