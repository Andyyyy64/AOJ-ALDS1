#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; i++)
    cin >> A[i];
  int q, key, sum = 0;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> key;
    // lower_boundの使用(Aがsortされている状態のときのみ使える)
    if (*lower_bound(A, A + n, key) == key)
      sum++;
  }
  cout << sum << endl;
}