#include <iostream>
#include <queue>

// タスクを表す構造体
struct Task {
  std::string name;   // タスク名
  int runtime;        // 実行時間
  int remaining;      // 残り実行時間
};

// ラウンドロビンスケジューリングをシミュレートする関数
void schedule(std::queue<Task>& tasks, int quantum, int& time) {
  // 全てのタスクを実行するまで繰り返す
  while (!tasks.empty()) {
    // タスクを取り出す
    Task task = tasks.front();
    tasks.pop();

    // タスクを実行する
    if (task.remaining > quantum) {
      // タスクがクォンタムを超えている場合
      task.remaining -= quantum;
      time += quantum;
      // タスクをキューに戻す
      tasks.push(task);
    } else {
      // タスクがクォンタム以下の場合
      time += task.remaining;
      // タスクを完了させる
      std::cout << task.name << " " << time << std::endl;
    }
  }
}

int main() {
  int n, q;
  std::cin >> n >> q;

  // タスクを格納するキューを作成
  std::queue<Task> tasks;

  // タスクの情報を読み込む
  for (int i = 0; i < n; i++) {
    std::string name;
    int time;
    std::cin >> name >> time;
    tasks.push({name, time, time});
  }

  // 現在時刻を初期化
  int time = 0;

  // ラウンドロビンスケジューリングを実行する
  schedule(tasks, q, time);

  return 0;
}