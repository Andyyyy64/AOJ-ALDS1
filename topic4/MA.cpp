#include <iostream>
using namespace std;

int search(int S[], int n, int key) {
  int i = 0;
  S[n] = key; // 配列の末尾にkeyを格納
  while (S[i] != key) // 配列Sの要素とkeyが一致するまでiをインクリメント
    i++;
  return i != n; //keyがなかった場合はnまで探索するため、iがnと一緒かを返す。
}

int main() {
  int n, q, key;
  int sum = 0;
  // 配列Sの初期化
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

  return 0;
}