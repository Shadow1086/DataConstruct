#include <iostream>
#include <stack>
using namespace std;
typedef int EleType;
// 功能描述：
// 写算法,借助于栈将一个单链表置逆。

typedef struct LNode {
  EleType data;
  struct LNode *next;
} LNode, *LinkList;

void InitLinkList(LinkList &L) {
  L = new LNode;
  L->next = nullptr;
}

void CreateLinkList(LinkList &L, int arr[], int n) {
  InitLinkList(L);
  if (n < 0) {
    cout << "输入的n不能<=0" << endl;
    return;
  } else {
    LNode *tail = L;
    for (int i = 0; i < n; i++) {
      LNode *newNode = new LNode;
      newNode->data = arr[i];
      tail->next = newNode;
      tail = newNode;
    }
    tail->next = nullptr;
  }
}

void reverseLinkList(LinkList &L) {
  stack<LNode *> s;
  LNode *temp = L->next;
  while (temp != nullptr) {
    s.push(temp);
    temp = temp->next;
  }

  temp = L;

  while (!s.empty()) {
    LNode *node = s.top();
    s.pop();

    temp->next = node;
    temp = node;
  }

  temp->next = nullptr;
}

void PrintLinkList(LinkList L) {
  LNode *p = L->next;
  while (p != nullptr) {
    cout << p->data << "\t";
    p = p->next;
  }
  cout << endl;
}

int main() {
  LinkList L;
  int arr[] = {1, 2, 3, 4, 5};
  int n = 5;

  // 创建链表
  CreateLinkList(L, arr, n);
  cout << "原链表: ";
  PrintLinkList(L);

  // 逆置链表
  reverseLinkList(L);
  cout << "逆置后: ";
  PrintLinkList(L);

  cout << "按回车键退出..." << endl;
  cin.get();
  return 0;
}
