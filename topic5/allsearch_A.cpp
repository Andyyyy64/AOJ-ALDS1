#include <iostream>
using namespace std;

bool solve(int n, int i, int key, int A[]) {
  if (key == 0)
    return true;
  if (i >= n)
    return false;
  int res = solve(n, i + 1, key, A) || solve(n, i + 1, key - A[i], A);
  return res;
}

int main() {
  int n, q, key;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; i++)
    cin >> A[i];
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> key;
    if (solve(n, 0, key, A))
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}