#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 2000000
#define INFTY (1 << 30)

int H, A[MAX + 1];

void maxHeapify(int i) {
  int l = 2 * i;     // iの左の添字
  int r = 2 * i + 1; // iの右の添字
  int largest;
  if (l <= H && A[l] > A[i])
    largest = l;
  // 節点iの左の子が存在することを確認し、節点iの左の子が節点iより値が大きかったらlargestをleftに設定する
  else
    largest = i;
  // 上の条件式が成り立たなかったら自分自身がlargestになる。
  if (r <= H && A[r] > A[largest])
    largest = r;
  // 節点iの右の子が存在することを確認し、節点iの右の子が節点iより値が大きかったらlargestをrightに設定する。
  if (largest != i) {
    swap(A[i], A[largest]);
    // largestがiと異なる場合、A[i]とA[largest]の値を交換し、max-ヒープ条件を満たすように調整する。
    maxHeapify(largest);
    // 交換した節点largestを新たな節点iとして、maxHeapify関数を再帰的に呼び出し、その部分木もmax-ヒープ条件を満たすように調整する。
  }
}

int extract() {
  int maxv;
  if (H < 1)
    return -INFTY;
  maxv = A[1];
  A[1] = A[H--];
  maxHeapify(1);
  return maxv;
}

void increaseKey(int i, int key) {
  if (key < A[i])
    return;
  A[i] = key;
  while (i > 1 && A[i / 2] < A[i]) {
    swap(A[i], A[i / 2]);
    i = i / 2;
  }
}

void insert(int key) {
  H++;
  A[H] = -INFTY;
  increaseKey(H, key);
}

int main() {
  int key;
  char com[10];
  while (1) {
    scanf("%s", com);
    if (com[0] == 'e' && com[1] == 'n')
      break;
    if (com[0] == 'i') {
      scanf("%d", &key);
      insert(key);
    } else {
      printf("%d\n", extract());
    }
  }
  return 0;
}