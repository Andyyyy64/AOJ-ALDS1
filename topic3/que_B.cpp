#include <iostream>
#include <queue>
using namespace std;

struct Prosess {
  string name;
  int time;
  int finish_time;
};

int main() {
  int n, q;
  cin >> n >> q;
  queue<Prosess> A;
  for (int i = 0; i < n; i++) {
    string name;
    int time;
    cin >> name >> time;
    Prosess p = {name, time};
    A.push(p);
  }
  int current_time = 0;
  while (!A.empty()) {
    Prosess p = A.front();
    A.pop();
    if (p.time <= q) {
      current_time += p.time;
      p.finish_time = current_time;
      cout << p.name << " " << p.finish_time << endl;
    } else {
      current_time += q;
      p.time -= q;
      A.push(p);
    }
  }
  return 0;
}