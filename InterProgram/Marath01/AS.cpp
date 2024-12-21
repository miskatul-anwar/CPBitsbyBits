#include <iostream>
#include <vector>
using namespace std;

// Function to count number of set bits in binary representation of a number
int countSetBits(long long n) {
  int count = 0;
  while (n) {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

// Function to count even binomial coefficients
int countEvenBinomialCoefficients(long long n) {
  int total_count = n + 1;
  int odd_count = 1 << countSetBits(n);
  return total_count - odd_count;
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    long long n;
    cin >> n;

    // Calculate the number of even binomial coefficients in the nth row
    cout << countEvenBinomialCoefficients(n) << endl;
  }

  return 0;
}
