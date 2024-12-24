#include <iostream>
#include <string>
#include <vector>
#define fast_io                                                                \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(nullptr);

using str = std::string;
using vs = std::vector<std::string>;

const vs prob = {"0/1", "1/6", "1/3", "1/2", "2/3", "5/6", "1/1"};

int main() {
  fast_io;
  int y, w, req;
  std::cin >> y >> w;
  req = 7 - (y > w ? y : w);
  std::cout << prob[req] << '\n';
  return 0;
}
