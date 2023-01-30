#include <cstdio>
#include <iostream>
using namespace std;
#define MAX 10000
#define NIL -1

struct Node {
  int p, l, r; // 親、左の子、右の子
};

Node T[MAX];
int n, D[MAX], H[MAX];

void setDepth(int u, int d) {
  if (u == NIL)
    return;
  D[u] = d;
  setDepth(T[u].l, d + 1);
  setDepth(T[u].r, d + 1);
}

int setHeight(int u) {
  int h1 = 0, h2 = 0;
  if (T[u].l != NIL) {
    h1 = setHeight(T[u].r) + 1;
  }
  if (T[u].r != NIL) {
    h2 = setHeight(T[u].r) + 1;
  }
  return H[u] = (h1 > h2 ? h1 : h2); // 三項演算子
}

int getSibling(int u) {
  if (T[u].p == NIL)
    return NIL;
  if (T[T[u].p].l != u && T[T[u].p].l != NIL)
    return T[T[u].p].l;
  if (T[T[u].p].r != u && T[T[u].p].r != NIL)
    return T[T[u].p].r;
  return NIL;
}

void print(int u) {
  int i, c;
  cout << "node " << u << ": ";
  cout << "parent = " << T[u].p << ", ";
  cout << "sibling = " << getSibling(u) << ", ";
  int deg = 0;
  if (T[u].l != NIL)
    deg++;
  if (T[u].r != NIL)
    deg++;
  cout << "degree = " << deg << ", ";
  cout << "depth = " << D[u] << ", ";
  cout << "height = " << H[u] << ", ";

  if (T[u].p == NIL)
    cout << "root" << endl; // 親がいない場合がroot(根)
  else if (T[u].l == NIL && T[u].r == NIL)
    cout << "leaf" << endl; // 子がない場合はleaf(外部節点)
  else
    cout << "internal node" << endl; // leaf以外の節点はinternal node(内部節点)
}

int main() {
  int v, l, r, root = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
    T[i].p = NIL;
  for (int i = 0; i < n; i++) {
    cin >> v >> l >> r;
    T[v].l = l;
    T[v].r = r;
    if (l != NIL)
      T[l].p = v;
    if (r != NIL)
      T[r].p = v;
  }
  for (int i = 0; i < n; i++) {
    if (T[i].p == NIL)
      root = i;
  }
  setDepth(root, 0);
  setHeight(root);

  for (int i = 0; i < n; i++)
    print(i);
  return 0;
}
