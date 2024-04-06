#include <bits/stdc++.h>
using namespace std;
int main(void) {
  vector<int> array = {12, 32, 113, 211, 1, 2, 31, 11, 62, 15};
  for (int i = 0; i < array.size(); i++) {
    for (int j = 0; j < array.size() - 1; j++) {
      if (array[j] > array[j + 1]) {
        swap(array[j], array[j + 1]);
      }
    }
  }
  for (auto i : array) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
