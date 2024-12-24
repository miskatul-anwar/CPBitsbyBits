#include <iomanip>
#include <iostream>
#include <vector>

#define fast_io                                                                \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(nullptr);

using namespace std;
using vi = vector<int>;
int main() {
  fast_io;

  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;

    vi A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    int max_sum = 0;
    int count_max_sum_pairs = 0;

    // Calculate the maximum sum and count the valid pairs
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        int sum = A[i] + A[j];
        if (sum > max_sum) {
          max_sum = sum;
          count_max_sum_pairs = 1;
        } else if (sum == max_sum) {
          count_max_sum_pairs++;
        }
      }
    }

    // Calculate total pairs
    int total_pairs = (N * (N - 1)) / 2;

    // Calculate probability
    double probability = static_cast<double>(count_max_sum_pairs) / total_pairs;

    cout << fixed << setprecision(8) << probability << '\n';
  }

  return 0;
}
