#include <iostream>
#define MAX 500000
#define SENTINEL 2000000000
using namespace std;

int L[MAX / 2 + 2], R[MAX / 2 + 2];
int cnt = 0;

void merge(int A[], int l, int mid, int r, int n) {
  int n1 = mid - l;
  int n2 = r - mid;
  for (int i = 0; i < n1; i++)
    L[i] = A[l + i];
  for (int i = 0; i < n2; i++)
    R[i] = A[mid + i];
  L[n1] = R[n2] = SENTINEL;
  int i = 0, j = 0;
  for (int k = l; k < r; k++) {
    cnt++;
    if (L[i] <= R[j]) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}

void mergesort(int A[], int l, int r, int n) {
  if (l + 1 < r) {
    int mid = (l + r) / 2;
    mergesort(A, l, mid, n);
    mergesort(A, mid, r, n);
    merge(A, l, mid, r, n);
  }
}

int main() {
  int n, A[MAX];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> A[i];

  mergesort(A, 0, n, n);

  for (int i = 0; i < n; i++) {
    if (i)
      cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << cnt << endl;

  return 0;
}