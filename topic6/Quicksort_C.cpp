#include <iostream>
#define MAX 100000
#define SENTINEL 2000000000
using namespace std;

struct Card {
  char suit;
  int value;
};

struct Card L[MAX / 2 + 2], R[MAX / 2 + 2];

void merge(struct Card A[], int n, int l, int mid, int r) {
  int n1 = mid - l;
  int n2 = r - mid;
  for (int i = 0; i < n1; i++)
    L[i] = A[l + i];
  for (int i = 0; i < n2; i++)
    R[i] = A[mid + i];
  L[n1].value = R[n2].value = SENTINEL;
  int i = 0, j = 0;
  for (int k = l; k < r; k++) {
    if (L[i].value <= R[j].value) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}

void mergesort(struct Card A[], int n, int l, int r) {
  if (l + 1 < r) {
    int mid = (l + r) / 2;
    mergesort(A, n, l, mid);
    mergesort(A, n, mid, r);
    merge(A, n, l, mid, r);
  }
}

int partition(struct Card A[], int n, int p, int r) {
  struct Card x;
  x = A[r]; // 配列の末尾の要素A[r]を基準にする
  int i = p - 1;
  for (int j = p; j <= r - 1; j++) {
    if (A[j].value <= x.value) {
      // j番目の要素A[j]が基準値x以下の場合、iをインクリメントし、i番目とj番目の要素をスワップする
      i++;
      swap(A[i], A[j]);
    }
  }
  swap(A[i + 1], A[r]);
  // for文が終了したら、最後に、i+1番目とr番目の要素をスワップする。これにより、基準値xが最終的な分割点になる。
  return i + 1; // 基準値xの添字を返す
}

void quicksort(struct Card A[], int n, int p, int r) {
  int q;
  if (p < r) {
    q = partition(A, n, p, r);
    quicksort(A, n, p, q - 1);
    quicksort(A, n, q + 1, r);
  }
}

int main() {
  int n, v;
  struct Card A[MAX], B[MAX];
  char S[10];
  int stable = 1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> S >> v;
    A[i].suit = B[i].suit = S[0];
    A[i].value = B[i].value = v;
  }

  mergesort(A, n, 0, n);
  quicksort(B, n, 0, n - 1);

  for (int i = 0; i < n; i++)
    if (A[i].suit != B[i].suit)
      stable = 0;

  if (stable == 1)
    cout << "Stable" << endl;
  else
    cout << "Not stable" << endl;
  for (int i = 0; i < n; i++)
    cout << B[i].suit << " " << B[i].value << endl;

  return 0;
}