#include <algorithm>
#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
  int n, key;
  string command;
  list<int> v;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> command;
    if (command[0] == 'i') {
      cin >> key;
      v.push_front(key);
    } else if (command[6] == 'L') {
      v.pop_back();
    } else if (command[6] == 'F') {
      v.pop_front();
    } else if (command[0] == 'd') {
      cin >> key;
      // イテレータは、STLのコンテナの中身を走査するためのオブジェクトで、C++のforループの中で使用されている
      //  list<int>::iteratorは、list<int>型のイテレータで、それを使用することで、双方向連結リストの中身を走査することができる。
      for (list<int>::iterator it = v.begin(); it != v.end(); it++) {
        if (*it == key) {
          v.erase(it);
          break;
        }
      }
    }
  }
  int i = 0;
  // 双方向連結リストの最初から最後までを走査するためのforループ
  for (list<int>::iterator it = v.begin(); it != v.end(); it++) {
    if (i++)
      cout << " ";
    cout << *it;
  }
  cout << endl;
  return 0;
}
