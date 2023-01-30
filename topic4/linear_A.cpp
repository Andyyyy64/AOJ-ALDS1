#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
  int n, q;
  cin >> n;

  unordered_set<int> s; 
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.insert(x);
  }

  cin >> q;
  int c = 0;
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    if (s.count(x) > 0) { 
      c++;
    }
  }

  cout << c << endl;
  return 0;
}