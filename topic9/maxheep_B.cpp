#include <iostream>
using namespace std;

void maxHeapify(int A[], int H, int i) {
  int l = 2 * i;     // iの左の添字
  int r = 2 * i + 1; // iの右の添字
  int largest;
  if (l <= H && A[l] > A[i])
    largest = l;
  // 節点iの左の子が存在することを確認し、節点iの左の子が節点iより値が大きかったらlargestをleftに設定する
  else
    largest = i;
  //上の条件式が成り立たなかったら自分自身がlargestになる。
  if (r <= H && A[r] > A[largest])
    largest = r;
  //節点iの右の子が存在することを確認し、節点iの右の子が節点iより値が大きかったらlargestをrightに設定する。
  if (largest != i) {
    swap(A[i], A[largest]);
    // largestがiと異なる場合、A[i]とA[largest]の値を交換し、max-ヒープ条件を満たすように調整する。
    maxHeapify(A, H, largest);
    //交換した節点largestを新たな節点iとして、maxHeapify関数を再帰的に呼び出し、その部分木もmax-ヒープ条件を満たすように調整する。
  }
}

void buildMaxHeap(int A[], int H) {
  for (int i = H / 2; i >= 1; i--)
    maxHeapify(A, H, i);
}
// buildMaxHeap関数は、配列Aをmax-ヒープに変換するために、配列Aの "後半部分" から、maxHeapify関数を適用する。

int main() {
  int H;
  cin >> H;
  int A[H + 1];
  for (int i = 1; i <= H; i++)
    cin >> A[i];
  buildMaxHeap(A, H);
  for (int i = 1; i <= H; i++)
    cout << " " << A[i];
  cout << endl;
  return 0;
}