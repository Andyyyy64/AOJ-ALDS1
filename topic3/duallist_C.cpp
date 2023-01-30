#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

struct Node {
  int key;
  Node *prev, *next;
};

Node *nil;

void init() {
  // malloc: 指定したサイズだけのメモリを確保する関数
  nil = (Node *)malloc(sizeof(Node));
  nil->next = nil;
  nil->prev = nil;
}

void insert(int key) {
  Node *x = (Node *)malloc(sizeof(Node));
  x->key = key;
  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

Node *listSearch(int key) {
  Node *cur = nil->next;
  while (cur != nil && cur->key != key)
    cur = cur->next;
  return cur;
}

void deleteNode(Node *t) {
  if (t == nil)
    return;
  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
}

void deleteFirst() { deleteNode(nil->next); }

void deleteLast() { deleteNode(nil->prev); }

void deleteKey(int key) { deleteNode(listSearch(key)); }

void printList() {
  Node *cur = nil->next;
  int isf = 0;
  while (1) {
    if (cur == nil)
      break;
    if (isf++ > 0)
      cout << " ";
    cout << cur->key;
    cur = cur->next;
  }
  cout << endl;
}

int main() {
  int key, n, i;
  int size = 0;
  char com[20];
  int np = 0, nd = 0;
  cin >> n;
  init();
  for (i = 0; i < n; i++) {
    scanf("%s%d", com, &key);
    if (com[0] == 'i') {
      insert(key);
      np++;
      size++;
    } else if (com[0] == 'd') {
      if (strlen(com) > 6) {
        if (com[6] == 'F')
          deleteFirst();
        else if (com[6] == 'L')
          deleteLast();
      } else {
        deleteKey(key); nd++;
      }
      size--;
    }
  }
  printList();
  return 0;
}