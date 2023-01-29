#include <iostream>
using namespace std;

#define MAX 200000
#define SENTINEL 2000000000
typedef long long ll;

int L[MAX / 2 + 2], R[MAX / 2 + 2];

ll merge(int A[], int n, int l, int mid, int r) {
  int i, j, k;
  ll cnt = 0;
  int n1 = mid - l;
  int n2 = r - mid;
  for (i = 0; i < n1; i++)
    L[i] = A[l + i];
  for (i = 0; i < n2; i++)
    R[i] = A[mid + i];
  L[n1] = R[n2] = SENTINEL;
  i = j = 0;
  for (k = l; k < r; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
      cnt += n1 - i;
    }
  }
  return cnt;
}

ll mergesort(int A[], int n, int l, int r) {
  int mid;
  ll v1, v2, v3;
  if (l + 1 < r) {
    mid = (l + r) / 2;
    v1 = mergesort(A, n, l, mid);
    v2 = mergesort(A, n, mid, r);
    v3 = merge(A, n, l, mid, r);
    return v1 + v2 + v3;
  } else
    return 0;
}

int main() {
  int n, A[MAX];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> A[i];

  mergesort(A, 0, n, n);

  ll ans = mergesort(A, n, 0, n);
  cout << ans << endl;

  return 0;
}