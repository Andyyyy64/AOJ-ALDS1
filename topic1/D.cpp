#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 200000;
int main() {
  int R[MAX], n;
  
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> R[i];

  int maxv = -2000000000;
  int minv = R[0];

  for (int i = 0; i < n; i++) {
    maxv = max(maxv, R[i] - minv); // 最大値を更新
    minv = min(minv, R[i]); // ここまでの最小値を保持しておく
  }

  cout << maxv << endl;
  return 0;
}
