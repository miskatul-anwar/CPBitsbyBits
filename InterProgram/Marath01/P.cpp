#include <iostream>
#include <string>
#define MOD 1000000007
typedef long long ll;

int main() {
  std::string s;
  std::cin >> s;

  ll result = 0;
  ll count_b = 0;

  for (int i = s.length() - 1; i >= 0; --i) {
    if (s[i] == 'b') {
      count_b = (count_b + 1) % MOD;
    } else if (s[i] == 'a') {
      result = (result + count_b) % MOD;
      count_b = (count_b * 2) % MOD;
    }
  }

  std::cout << result << std::endl;
  return 0;
}
