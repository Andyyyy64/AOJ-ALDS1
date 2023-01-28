#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

unordered_set<string> dictionary;
int main() {
  int n;
  cin >> n;
  while (n--) {
    string command, str;
    cin >> command >> str;
    if (command == "insert") {
      dictionary.insert(str);
    } else if (command == "find") {
      if (dictionary.count(str)) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
  }
  return 0;
}
