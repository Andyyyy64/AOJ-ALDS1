#include <iostream>
using namespace std;

int gcd(int A, int B) {
  if (A % B == 0)
    return B;
  else
    return gcd(B, A % B);
}

int main() {
  int A, B;
  cin >> A >> B;
  cout << gcd(A, B) << endl;
}