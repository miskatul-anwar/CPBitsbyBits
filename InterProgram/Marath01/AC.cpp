#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    long long total_sum = 0;
    map<int, int> freq;

    // Read the array and compute the total sum
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      total_sum += a[i];
      freq[a[i]]++;
    }

    int nearly_full_count = 0;
    // Check for each element if its removal makes the sum equal to total_sum -
    // 1
    for (int i = 0; i < n; ++i) {
      if (total_sum - a[i] == total_sum - 1) {
        nearly_full_count += freq[a[i]];
      }
    }

    // Print the result for this test case
    cout << nearly_full_count << endl;
  }
  return 0;
}
