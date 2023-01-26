#include <iostream>
using namespace std;

void sort(int A[], int n) {
  for (int i = 0; i < n; i++) {
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
  }
}

int main() {
  int n;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; i++)
    cin >> A[i];
  sort(A, n);
  for (int i = 0; i < n; i++)
    cout << A[i] << " ";
}