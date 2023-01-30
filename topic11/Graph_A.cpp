#include <iostream>
using namespace std;
static const int N = 100;

int main() {
  int M[N][N];
  int n, u, k, v;

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      M[i][j] = 0; // すべて0に初期化
  }
  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    u--; // 2次元配列Mの行の添字に変換
    for (int j = 0; j < k; j++) {
      cin >> v;
      v--; // 2次元配列Mの列の添字に変換
      M[u][v] = 1; // uとvに辺を通す(二次元配列Mを1にする)
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j)
        cout << " ";
      cout << M[i][j]; 
    }
    cout << endl;
  }
  return 0;
}
