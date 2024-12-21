#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long total_sum = 0;
    unordered_map<long long, int> freq;

    // Read the array and compute the total sum
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      total_sum += a[i];
      freq[a[i]]++;
    }

    int nearly_full_count = 0;
    // Iterate over the frequency map to find nearly full subsequences
    for (auto &entry : freq) {
      long long element = entry.first;
      int count = entry.second;
      if (total_sum - element == total_sum - 1) {
        nearly_full_count += count;
      }
    }

    // Output the result for this test case
    cout << nearly_full_count << endl;
  }

  return 0;
}
