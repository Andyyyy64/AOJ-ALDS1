#include <iostream>
#include <queue>
using namespace std;

struct Process {
  string name;
  int time;        // プロセスの完了時間
  int finish_time; // プロセスが終了した時間
};

int main() {
  int n, q;
  cin >> n >> q;
  queue<Process> processes; // queueの初期化
  for (int i = 0; i < n; i++) {
    string name;
    int time;
    cin >> name >> time;
    Process p = {name, time};
    processes.push(p); // queueに追加
  }
  int current_time = 0;
  while (!processes.empty()) {
    Process p = processes.front(); // pにqueueの最初の情報を代入
    processes.pop();               // 最初を取り出す
    if (p.time <= q) { // 設定時間がプロセス完了時間より大きい場合
      current_time += p.time; // 現在時刻にプロセスの完了時間を足す
      p.finish_time = current_time; // プロセスの終了時間は現在時刻になる
      cout << p.name << " " << p.finish_time << endl;
    } else { // 設定時間がプロセス完了時間より小さい場合
      current_time += q; // 現在時刻に設定時間を足す
      p.time -= q; // 設定時間からプロセスの完了時間を引く
      processes.push(p); // そのまま末尾にpush
    }
  }
  return 0;
}