#include <iostream>
using namespace std;

bool isPrime(int n) {
  if (n <= 1)
    return false;
  if (n <= 3)
    return true;
  if (n % 2 == 0 || n % 3 == 0)
    return false;
  for (int i = 5; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0)
      return false;
  return true;
}

int main() {
  int n;
  int cnt = 0;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; i++)
    cin >> A[i];
  for (int i = 0; i < n; i++)
    if (isPrime(A[i]))
      cnt++;
  cout << cnt << endl;
  return 0;
}