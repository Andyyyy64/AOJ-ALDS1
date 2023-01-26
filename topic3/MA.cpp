#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  stack<int> s;
  string str;
  getline(cin, str);
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == ' ')
      continue;
    if (str[i] >= '0' && str[i] <= '9') {
      int num = 0;
      // i番目の文字が数字である限り繰り返す。
      while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
        // 文字'0'から'9'はそれぞれ48から57のASCIIコードを持つ。それを'0'と減算することでそれぞれ0から9に変換される
        num = num * 10 + str[i] - '0';
        // 例えば、numが12であり、str[i]が'3'である場合
        // num = num * 10 + str[i] - '0'はnum=123になります。
        i++;
      }
      i--;
      s.push(num);
    } else {
      int a = s.top();
      s.pop();
      int b = s.top();
      s.pop();
      if (str[i] == '+')
        s.push(b + a);
      else if (str[i] == '-')
        s.push(b - a);
      else if (str[i] == '*')
        s.push(b * a);
    }
  }
  cout << s.top() << endl;
  return 0;
}