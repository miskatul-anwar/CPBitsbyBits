#include <climits>
#include <iostream>
int main() {
  if (INT_MAX + 1 == INT_MIN) {
    std::cout << "True assumption!\n";
  } else {
    std::cout << "False!\n";
  }
  return 0;
}
