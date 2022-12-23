#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

void insertionSort(int A[MAX], int N) {
  for (int i = 0; i < N; ++i) {
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }

    A[j + 1] = v;
    for (int n = 0; n < N; ++n) {
      if (n != N - 1) {
        cout << A[n];
        cout << " ";
      } else {
        cout << A[n];
      }
    }
    cout << endl;
  }
}

int main() {
  int A[MAX];
  int i, j, N;
  cin >> N;
  for (i = 0; i < N; ++i) {
    cin >> A[i];
  }
  insertionSort(A, N);
  return 0;
}