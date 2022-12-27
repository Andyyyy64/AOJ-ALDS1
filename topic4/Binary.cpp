#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  // S を読み込む
  vector<int> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  int q;
  cin >> q;

  // T を読み込む
  vector<int> t(q);
  for (int i = 0; i < q; i++) {
    cin >> t[i];
  }

  // C をカウントする
  int c = 0;
  for (int i = 0; i < q; i++) {
    // lower_bound 関数を使って、t[i] 以上の最小の要素を探す
    auto it = lower_bound(s.begin(), s.end(), t[i]);
    // t[i] 以上の最小の要素が、s の末尾よりも後ろにあれば、t[i] は s に含まれていない
    if (it == s.end() || *it != t[i]) continue;
    // t[i] が s に含まれている場合は c をインクリメントする
    c++;
  }

  // 結果を出力する
  cout << c << endl;
  return 0;
}
