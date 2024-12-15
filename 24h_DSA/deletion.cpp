#include <iostream>
#define n 8
using namespace std;
int main(void) {
  int v[n] = {1, 6, 3, 6, 5, 6, 7, 8};
  int target = 6;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (target == v[i]) {
      v[i] = 0, cnt++;
      for (int j = i; j < n - cnt; j++) {
        v[j] = v[j + 1];
      }
      v[n - cnt] = 0;
    }
  }
  for (int i = 0; i < 8; i++) {
    cout << v[i] << ' ';
  }
  cout << '\n';
  return 0;
}
