#include <iostream>
int main(void) {
  int n;
  std::cin >> n;
  int fact = 1;
  while (n > 0) {
    fact = fact * n;
    n--;
  }
  std::cout << fact;
  return 0;
}
