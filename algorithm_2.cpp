#include "bits/stdc++.h"
using namespace std;
int main(void) {
  vector<int> v = {-1, 2, 4, -3, 5, 2, -5, 2};
  int n = v.size(), best = 0, sum;
  for (int i = 0; i < n; i++) {
    sum = 0;
    for (int j = i; j < n; j++) {
      sum += v[j];
      best = max(best, sum);
    }
  }
  cout << best << endl;
}

