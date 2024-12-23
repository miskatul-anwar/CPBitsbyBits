#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;

long long factorial(int n) {
  long long result = 1;
  for (int i = 2; i <= n; ++i) {
    result = (result * i) % MOD;
  }
  return result;
}

long long modInverse(long long a, long long m) {
  long long result = 1;
  long long power = m - 2;
  while (power) {
    if (power % 2 == 1) {
      result = (result * a) % m;
    }
    a = (a * a) % m;
    power /= 2;
  }
  return result;
}

int main() {
  string s;
  cin >> s;
  int n = s.length();

  vector<int> freq(26, 0);
  for (char c : s) {
    freq[c - 'a']++;
  }

  long long result = factorial(n);
  for (int count : freq) {
    if (count > 0) {
      result = (result * modInverse(factorial(count), MOD)) % MOD;
    }
  }

  cout << result << endl;
  return 0;
}
