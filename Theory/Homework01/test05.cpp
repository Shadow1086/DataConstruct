#include <iostream>
using namespace std;

// 功能描述：
// 已知带头结点的单链表L中的结点是按整数值递增排列的,试写一算法,
// 将值为x的结点插入到表L中,使得L仍然递增有序,并且分析算法的时间复杂度。

typedef int EleType;

typedef struct LNode {
  EleType data;
  struct LNode *next;
} LNode, *LinkList;

// 初始化带有头节点的单链表
void InitList(LinkList &L) {
  L = new LNode;
  L->next = nullptr;
}

void insert(LinkList &L, int x) {
  // 初始化带有x的节点
  LNode *newNode = new LNode;
  newNode->data = x;

  LNode *p = L->next;
  LNode *pre = L;

  while (p != nullptr && p->data < x) {
    pre = p;
    p = p->next;
  }

  newNode->next = p;
  pre->next = newNode;
}

void printList(LinkList L) {
  LNode *p = L->next;
  while (p != nullptr) {
    cout << p->data << "\t";
    p = p->next;
  }
  cout << endl;
}

int main() {
  LinkList L;
  InitList(L);

  insert(L, 1);
  insert(L, 2);
  insert(L, 3);
  insert(L, 5);
  insert(L, 7);
  insert(L, 8);

  cout << "原始链表：\t";
  printList(L);

  cout << "插入4后：\t";
  insert(L, 4);
  printList(L);

  cout << "插入6后：\t";
  insert(L, 6);
  printList(L);

  cout << "插入9后：\t";
  insert(L, 9);
  printList(L);

  cout << "按回车键退出..." << endl;
  cin.get();
  return 0;
}
