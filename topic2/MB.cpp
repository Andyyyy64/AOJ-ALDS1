/*例えば、配列 A = [3, 1, 4, 2, 5] の場合、最初の i = 0 のとき、minj = 0
が設定され、j = 0 から n-1 までの要素を見ていき、最小値 1 を見つけ、minj =
1になります。そして、i = 0, minj = 1をswapし、A = [1, 3, 4, 2, 5]
となります。次に i = 1 のとき、minj = 1 が設定され、j = 1 から n-1
までの要素を見ていき、最小値 2 を見つけ、minj = 3になり、i = 1, minj =
3をswapし、A = [1, 2, 4, 3, 5] となります。これを繰り返し、最終的に A = [1, 2,
3, 4, 5] となり、昇順にソートされます。
*/

#include <iostream>
using namespace std;

void sort(int A[], int n) {
  int minj;
  for (int i = 0; i < n; i++) {
    minj = i;
    for (int j = i; j < n; j++) {
      if (A[j] < A[minj]) {
        minj = j;
      }
    }
    swap(A[i], A[minj]);
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
  return 0;
}