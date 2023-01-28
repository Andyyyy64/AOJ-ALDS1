#include <algorithm>
#include <iostream>
using namespace std;

int search(int S[], int n, int key) {
  int l = 0; // 左
  int r = n; // 右 (配列の最後だからn)
  int mid;   // 中央
  while (l < r) {
    mid = (l + r) / 2;
    if (S[mid] == key)
      return true;    // keyを発見したらtrueを返す
    if (key < S[mid]) // 右を中央に寄せて前半を探索
      r = mid;
    else if (key > S[mid]) // 左を中央+1に寄せて後半を探索
      l = mid + 1;
  }
  return false; // 見つからなかったらfalseを返す
}

int main() {
  int n, q, key;
  int sum = 0;
  cin >> n;
  int S[n];
  for (int i = 0; i < n; i++)
    cin >> S[i];
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> key;
    if (search(S, n, key))
      sum++;
  }
  cout << sum << endl;
}