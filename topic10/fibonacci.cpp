#include <iostream>
#define MAX 44
using namespace std;

void find(int F[MAX], int n) {
  F[0] = 1;
  F[1] = 1;
  for (int i = 2; i <= n; i++)
    F[i] = F[i - 1] + F[i - 2];
}

int main() {
  int F[MAX], n;
  cin >> n;
  find(F, n);
  cout << F[n] << endl;
}