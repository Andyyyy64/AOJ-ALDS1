#include <iostream>
using namespace std;

int partition(int A[], int p, int r) {
  int x = A[r]; // 配列の末尾の要素A[r]を基準にする
  int i = p - 1;
  for (int j = p; j <= r - 1; j++) {
    if (A[j] <= x) {
      // j番目の要素A[j]が基準値x以下の場合、iをインクリメントし、i番目とj番目の要素をスワップする
      i++;
      swap(A[i], A[j]);
    }
  }
  swap(A[i + 1], A[r]);
  // for文が終了したら、最後に、i+1番目とr番目の要素をスワップする。これにより、基準値xが最終的な分割点になる。
  return i + 1; // 基準値xの添字を返す
}

int main() {
  int n;
  cin >> n;

  int A[n];
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  int q = partition(A, 0, n - 1);

  for (int i = 0; i < q; i++) {
    cout << A[i] << " ";
  }
  cout << "[" << A[q] << "]";
  for (int i = q + 1; i < n; i++) {
    if (i != n - 1)
      cout << " " << A[i];
    else
      cout << " " << A[i] << endl;
  }
  return 0;
}