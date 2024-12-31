#include <iostream>
int main() {
  int x = 5, y = 6, z = 7, a = 8, b = 10;
  int **pp;
  for (int *i = &x; *i <= b; i++) {
    pp = &i;
    std::cout << *i << " " << *pp << " " << i << '\n';
  }
  return 0;
}
