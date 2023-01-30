#include <iostream>
#include <stack>
using namespace std;
static const int N = 100;
static const int WHITE = 0; // 未訪問の頂点
static const int GRAY = 1;  // 現在訪問中の頂点 || 訪問した頂点
static const int BLACK = 2; // 訪問を完了して頂点

int n, M[N][N];
int color[N], d[N], f[N], tt;
// 頂点の状態、最初に訪れた時間(discovery)、訪問完了した時間(finish)、時間;
int nt[N]; // 各頂点に対応する次の深さ優先探索で訪れる頂点を格納するためのもの

// uに隣接するvを番号順に取得
int next(int u) {
  for (int v = nt[u]; v < n; v++) {
    nt[u] = v + 1; 
    // nt[u]にv + 1を代入することで、次回に同じ頂点uから探索するときに、この頂点vを再度訪問することを防ぐ
    if (M[u][v])
      return v;
  }
  return -1;
}
void dfs_visit(int r) {
  for (int i = 0; i < n; i++)
    nt[i] = 0;
  stack<int> S;
  S.push(r);
  color[r] = GRAY;
  d[r] = ++tt;

  while (!S.empty()) {
    int u = S.top();
    int v = next(u);
    if (v != -1) {
      if (color[v] == WHITE) {
        color[v] = GRAY;
        d[v] = ++tt;
        S.push(v);
      }
    } else {
      S.pop();
      color[u] = BLACK;
      f[u] = ++tt;
    }
  }
}

void dfs() { // 全ての頂点を探索する
  // 初期化
  for (int i = 0; i < n; i++) {
    color[i] = WHITE;
    nt[i] = 0;
  }
  tt = 0;

  // 未訪問のuを視点として深さ優先探索
  for (int u = 0; u < n; u++) {
    if (color[u] == WHITE)
      dfs_visit(u);
  }
  for (int i = 0; i < n; i++) {
    cout << i + 1 << " " << d[i] << " " << f[i] << endl;
  }
}

int main() {
  int u, k, v;

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
      v--;         // 2次元配列Mの列の添字に変換
      M[u][v] = 1; // uとvに辺を通す(二次元配列Mを1にする)
    }
  }

  dfs();

  return 0;
}
