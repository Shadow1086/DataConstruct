#include <cstddef>
#include <iostream>
using namespace std;

// 功能描述：
// 假设有两个已排序(递增)的单链表 A 和 B，
// 编写算法将它们合并成一个链表 C 而不改变其排序性。

typedef int ELeType;

typedef struct LNode{
    ELeType data;
    struct LNode *next;
}LNode,*LinkList;

void InitLNode(LinkList &L){
    L = new LNode;
    L->next = nullptr;
}

void CreatList(LinkList &L,int arr[],int n){
    InitLNode(L);
    LNode *tail = L;
    for(int i = 0;i<n;i++){
        LNode *p = new LNode;
        p->data = arr[i];
        tail->next = p;
        tail = p;
    }
    tail->next = nullptr;
}
int main() {


    cout << "按回车键退出..." << endl;
    cin.get();
    return 0;
}
