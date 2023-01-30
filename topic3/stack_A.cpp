#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

int main() {
  stack<int> A;
  string str;
  getline(cin, str);
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == ' ')
      continue;
    if (str[i] >= '0' && str[i] <= '9') {
      int num = 0;
      while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
        num = 10 * num + str[i] - '0';
        i++;
      }
      i--;
      A.push(num);
    } else {
      int a = A.top();
      A.pop();
      int b = A.top();
      A.pop();
      if (str[i] == '+')
        A.push(a + b);
      else if (str[i] == '-')
        A.push(a - b);
      else if (str[i] == '*')
        A.push(a * b);
    }
  }
  cout << A.top() << endl;
  return 0;
}