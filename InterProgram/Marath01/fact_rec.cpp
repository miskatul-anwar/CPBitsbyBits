#include <iostream>
typedef long long ll;

ll fact(int n) {
  if (n <= 1) {
    return 1;
  }
  return n * fact(n - 1);
}

int main(void) {
  int n;
  std::cin >> n;
  std::cout << fact(n);
  return 0;
}
