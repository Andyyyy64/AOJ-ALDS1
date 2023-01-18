#include <iostream>
using namespace std;
#define MAX 100
void insertionsort(int A[MAX], int N) {
  for (int i = 0; i < N; ++i) {
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
    for (int j = 0; j < N; ++j) {
      if (j != N)
        cout << A[j] << " ";
      else
        cout << A[j];
    }
    cout << endl;
  }
}

int main() {
  int A[MAX], N;
  cin >> N;
  for (int i = 0; i < N; ++i)
    cin >> A[i];
  insertionsort(A, N);
  return 0;
}

/*具体例を上げると、配列 A = [5, 2, 4, 6, 1, 3] が与えられたとします。

1回目のイテレーションで、i = 0、A[i] = 5 が vに格納されます。
whileループに入りますが、j = -1なので条件は成立しません。そのため、A[j + 1] =
vが実行され、A[0] = 5 となります。

2回目のイテレーションで、i = 1、A[i] = 2がvに格納されます。 whileループに入り、j
= 0、A[j] = 5がv = 2より大きいため、条件が成立します。 A[j + 1] =
A[j]が実行され、A[1] = 5、j--が実行され、j = -1になります。
条件が成立しなくなるのでwhileループを抜けます。 最後に、A[j + 1] = v
が実行され、A[0] = 2となります。

同様に、3回目のイテレーションでは、A[1] = 4、4回目のイテレーションではA[2] =
4、5回目のイテレーションではA[3] = 6、6回目のイテレーションではA[4] =
6、7回目のイテレーションではA[5] = 6となります。

配列 A の要素が全て比較されると、A = [2, 4, 5, 6, 6,
6]となり、ソートが完了します。

while文の条件j >= 0 && A[j] >
vは、jが0以上であり、かつ配列Aのj番目の要素がvより大きい間、whileループを続けるための条件です。*/