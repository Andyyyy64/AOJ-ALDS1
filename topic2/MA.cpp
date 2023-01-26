#include <iostream>
using namespace std;
const int MAX = 100;

void sort(int A[MAX], int n) {
  bool flag = true;
  while (flag) {
    flag = false;
    for (int i = n - 1; i > 0; i--) // 後ろから見ていく
      if (A[i] < A[i - 1]) {
        swap(A[i], A[i - 1]);
        //現在と一個前を比較して現在のほうが小さかったら交換する
        flag = true;
      }
  }
}

int main() {
  int A[MAX], n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> A[i];
  sort(A, n);
  for (int i = 0; i < n; i++)
    cout << A[i] << " ";
  return 0;
}