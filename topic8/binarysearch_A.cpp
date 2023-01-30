#include <iostream>
#include <string>
using namespace std;

struct Node {
  int key; // 要素のキー #キーとは、二分探索木の要素（ノード）に格納される値
  Node *left, *right; // 左の子、右の子
};

Node *newNode(int key) {
  Node *node = new Node;
  // 新しいNode構造体のインスタンスを確保し、それをnodeポインタが指すようにする
  node->key = key; // nodeポインタが指すNode構造体のkeyに、引数のkeyを代入する
  node->left = node->right = nullptr;
  // 型安全なポインタのためのNULL 新しいノードはまだ子を持っていないことを示す　
  return node;
}

Node *insert(Node *node, int key) {
  if (node == nullptr)
    return newNode(key);
  // もしnodeがnullptr(空)だったら、newNode関数を使って新しいノードを生成し、それを返す。これによって、二分探索木に新しい根が追加される
  if (key < node->key)
    node->left = insert(node->left, key);
  // 再帰的にinsert関数を呼び出し、keyとnode->keyを比較して最終的に新しいノードを挿入する。
  else if (key > node->key)
    node->right = insert(node->right, key);
  return node;
}

void inorder(Node *node) { // 中間順巡回
  if (node != nullptr) {
    inorder(node->left);
    cout << " " << node->key;
    inorder(node->right);
  }
}

void preorder(Node *node) { // 先行順巡回
  if (node != nullptr) {
    cout << " " << node->key;
    preorder(node->left);
    preorder(node->right);
  }
}
int main() {
  int m, key;
  string command;
  Node *root = nullptr; // 最初に入れたkeyが根になる
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> command;
    if (command == "insert") {
      cin >> key;
      root = insert(root, key);
    } else if (command == "print") {
      inorder(root);
      cout << endl;
      preorder(root);
      cout << endl;
    }
  }
  return 0;
}
