#include <iostream>
using namespace std;

//ただのユークリッドの互助法です。

int gcd(int a, int b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
int main() {
  int a, b;
  cin >> a >> b;
  cout << gcd(a,b) << endl;
}