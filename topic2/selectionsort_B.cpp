#include <iostream>
using namespace std;
#define MAX 100
void selectionsort(int A[MAX], int N) {
  int cnt = 0;
  int minj;
  for (int i = 0; i < N; ++i) {
    minj = i;
    for (int j = i; j < N; ++j) {
      if (A[j] < A[minj])
        minj = j;
    }
    swap(A[i], A[minj]);
    if (A[i] != A[minj])
      cnt++;
  }
  for (int j = 0; j < N; ++j) {
    if (j)
      cout << " ";
    cout << A[j];
  }
  cout << endl;
  cout << cnt << endl;
}
int main() {
  int A[MAX], N;
  cin >> N;
  for (int i = 0; i < N; ++i)
    cin >> A[i];
  selectionsort(A, N);
}