#include <iostream>
using namespace std;
#define MAX 100005
#define NIL -1

struct Node {
  int p, l, r; // 親、左の子、右の子
};

Node T[MAX];
int n, D[MAX];

void print(int u) {
  int i, c;
  cout << "node " << u << ": ";
  cout << "parent = " << T[u].p << ", ";
  cout << "depth = " << D[u] << ", ";

  if (T[u].p == NIL)
    cout << "root, "; // 親がいない場合がroot(根)
  else if (T[u].l == NIL)
    cout << "leaf, "; // 子がない場合はleaf(外部節点)
  else
    cout << "internal node, "; // leaf以外の節点はinternal node(内部節点)
  cout << "[";

  for (i = 0, c = T[u].l; c != NIL; i++, c = T[c].r) {
    if (i)
      cout << ", ";
    cout << c;
  }
  cout << "]" << endl;
}

int rec(int u, int p) {
  D[u] = p;
  if (T[u].r != NIL)
    rec(T[u].r, p); // 右の兄弟に同じ深さを設定
  if (T[u].l != NIL)
    rec(T[u].l, p + 1); // 最も右の子に自分の深さを+1を設定
}

int main() {
  int d, v, c, l, r;
  cin >> n;
  for (int i = 0; i < n; i++)
    T[i].p = T[i].l = T[i].r = NIL;

  for (int i = 0; i < n; i++) {
    cin >> v >> d;
    for (int j = 0; j < d; j++) {
      cin >> c;
      if (j == 0)
        T[v].l = c;
      else
        T[l].r = c;
      l = c;
      T[c].p = v;
    }
  }
  for (int i = 0; i < n; i++) {
    if (T[i].p == NIL)
      r = i;
  }
  rec(r, 0);
  for (int i = 0; i < n; i++)
    print(i);
  return 0;
}
