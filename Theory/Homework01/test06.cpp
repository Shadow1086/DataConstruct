#include <cstddef>
#include <iostream>
using namespace std;

// 功能描述：
// 假设有两个已排序(递增)的单链表 A 和 B，
// 编写算法将它们合并成一个链表 C 而不改变其排序性。

typedef int ELeType;

typedef struct LNode {
  ELeType data;
  struct LNode *next;
} LNode, *LinkList;

void InitLNode(LinkList &L) {
  L = new LNode;
  L->next = nullptr;
}

void CreateList(LinkList &L, int arr[], int n) {
  InitLNode(L);
  LNode *tail = L;
  for (int i = 0; i < n; i++) {
    LNode *p = new LNode;
    p->data = arr[i];
    tail->next = p;
    tail = p;
  }
  tail->next = nullptr;
}

void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc) {
  LNode *pa = La->next;
  LNode *pb = Lb->next;

  Lc = La;
  LNode *pc = Lc;

  while (pa && pb) {
    // La中的元素比Lb中元素小，那么Lc指向的就是较小的元素
    if (pa->data <= pb->data) {
      pc->next = pa;
      pc = pa;
      pa = pa->next;
    } else {
      pc->next = pb;
      pc = pb;
      pb = pb->next;
    }
  }
  pc->next = pa ? pa : pb;
  delete Lb;
}

// 打印链表
void PrintLink(LinkList &L) {
  LNode *p = L->next;
  while (p) {
    cout << p->data << "\t";
    p = p->next;
  }
  cout << endl;
}
int main() {
  LinkList La, Lb, Lc;

  // 创建有序链表A
  int arrA[] = {1, 3, 5, 7, 9};
  CreateList(La, arrA, 5);
  cout << "链表A: ";
  PrintLink(La);

  // 创建有序链表B
  int arrB[] = {2, 4, 6, 8, 10};
  CreateList(Lb, arrB, 5);
  cout << "链表B: ";
  PrintLink(Lb);

  // 合并链表
  MergeList(La, Lb, Lc);
  cout << "合并后链表C: ";
  PrintLink(Lc);

  cout << "按回车键退出..." << endl;
  cin.get();
  return 0;
}
