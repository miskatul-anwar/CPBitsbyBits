#include <iostream>
#include <vector>
using namespace std;
template <typename T> class ArrayIns {
private:
  vector<T> v;
  int nElems;

public:
  ArrayIns(int max) : nElems(0) { v.resize(max); }
  void insert(T value) {
    v[nElems] = value;
    nElems++;
  }
  void display() {
    for (int j = 0; j < nElems; j++) {
      cout << v[j] << ' ';
    }
    cout << '\n';
  }
  void insertionSort() {
    T in, out;
    for (out = 1; out < nElems; out++) {
      T temp = v[out], in = out;
      while (in > 0 and v[in - 1] >= temp) {
        v[in] = v[in - 1], --in;
      }
      v[in] = temp;
    }
  }
};

int main(void) {
  ArrayIns<int> arr(5);
  arr.insert(11);
  arr.insert(9);
  arr.insert(7);
  arr.insert(10);
  arr.insert(12);
  arr.display();
  arr.insertionSort();
  arr.display();
  return 0;
}
