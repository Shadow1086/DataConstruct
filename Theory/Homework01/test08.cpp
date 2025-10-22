#include <cstddef>
#include <iostream>
using namespace std;

typedef int EleType;

// 功能描述：
// 已知两个单链表A和B分别表示两个集合,其元素递增排列,
// 编写算法求出A和B的交集 C，要求 C 同样以元素递增的单链表形式存储。

typedef struct LNode{
    EleType data;
    struct LNode *next;
}LNode,*LinkList;

//初始化链表
void InitLinkList(LinkList &L){
    L = new LNode;
    L->next = nullptr;
}
//创建链表
void CreateLinkList(LinkList &L,int arr[],int n){
    InitLinkList(L);
    LNode *tail = L;
    for(int i = 0;i<n;i++){
        LNode *p = new LNode;
        p->data = arr[i];
        tail->next = p;
        tail = p;
    }
    tail->next = nullptr;
}

void InsertSameEle(LinkList La,LinkList Lb,LinkList &Lc){
    LNode *pa = La->next;
    LNode *pb = Lb->next;

    Lc = new LNode;
    Lc ->next = nullptr;
    LNode *pc = Lc;

    while(pa &&pb){
        if(pa->data < pb->data){
            pa = pa->next;
        }else if(pb->data < pa->data){
            pb = pb->next;
        }else{
            LNode *newNode = new LNode;
            newNode->data = pa->data;
            newNode->next = nullptr;

            pc->next = newNode;
            pc = newNode;

            pa = pa->next;
            pb = pb->next;
        }
    }
    pc->next = nullptr;
}

void PrintLinkList(LinkList L){
    LNode *p = L->next;
    if(!p ){
        cout << "空集" << endl;
        return;
    }
    while(p){
        cout << p->data << "\t";
        p = p->next;
    }
    cout  << endl;
}

int main() {
    LinkList La, Lb, Lc;
    
    // 创建集合A: {1, 3, 5, 7, 9}
    int arrA[] = {1, 3, 5, 7, 9};
    CreateLinkList(La, arrA, 5);
    cout << "集合A: ";
    PrintLinkList(La);
    
    // 创建集合B: {1, 2, 3, 6, 9}
    int arrB[] = {1, 2, 3, 6, 9};
    CreateLinkList(Lb, arrB, 5);
    cout << "集合B: ";
    PrintLinkList(Lb);
    
    // 求交集
    InsertSameEle(La, Lb, Lc);
    cout << "交集C: ";
    PrintLinkList(Lc);
    


    cout << "按回车键退出..." << endl;
    cin.get();
    return 0;
}
