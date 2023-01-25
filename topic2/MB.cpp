#include <iostream>
using namespace std;
#define MAX 100
void sort(int A[MAX], int n) {
  int minj;
  for (int i = 0; i < n; i++) {
    minj = i;
    for (int j = i; j < n; j++) 
      if (A[j] < A[minj])
        minj = j;
    swap(A[i], A[minj]);
  }
  for (int i = 0; i < n; i++)
    cout << A[i] << " ";
}

int main() {
  int n, A[MAX];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> A[i];
  sort(A, n);
}