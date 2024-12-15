#include "bits/stdc++.h"
using namespace std;
int main(void) {
  vector<int> nums = {2, 4, 6, 8, 10};
  int target, d = nums[1] - nums[0], a = nums[0];
  cin >> target;
  cout << ((target - a + d) / d) - 1 << endl;
  return 0;
}
