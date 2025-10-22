#include <iostream>
using namespace std;

// 功能描述：
// 假设长度大于1的单循环链表中,既无头结点也无头指针 ,
//p为指向该链表中某一结点的指针，编写算法删除该结点的前驱结点。 


typedef int EleType;

typedef struct LNode{
    EleType data;
    struct LNode *next;
}LNode,*LinkList;

void InitList(LinkList &L){
    L = new LNode;
    L->next = L;
}

bool isEmpty(LinkList L){
    return L->next ==L;
}

void DeletePrior(LNode * &p){
    if(!p || p->next == p){
        return;
    }

    LNode *prepre = p;
    LNode *pre = p->next;

    while(pre->next != p){
        prepre = pre;
        pre = pre->next;
    }

    prepre->next = pre->next;
    delete pre;
}

bool isTail(LinkList L,LNode *p){
    return p->next ==L;
}

void PrintLinkList(LNode *p){
    LNode *current = p;
    do{
        cout << current->data << "\t";
        current = current->next;
    }while(current!=p);
    cout<<endl;
}

// 创建循环链表
void CreateLinkList(LNode *&p, int arr[], int n, int pIndex) {
  LNode *first = new LNode;
  first->data = arr[0];

  LNode *tail = first;
  LNode *temp = first;

  for (int i = 1; i < n; i++) {
    LNode *newNode = new LNode;
    newNode->data = arr[i];
    tail->next = newNode;
    tail = newNode;

    if (i == pIndex) {
      temp = newNode;
    }
  }
  tail ->next =first;
  if(pIndex == 0){
    p = first;
  }else{
    p = temp;
  }
}
int main() {
    LNode *p = nullptr;
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    
    // 创建循环链表，p指向值为3的结点（索引2）
    CreateLinkList(p, arr, n, 2);
    //从3开始
    cout << "原始循环链表：";
    PrintLinkList(p);
    
    cout << "p指向的结点值：" << p->data << endl;
    
    // 删除p的前驱（值为2）
    DeletePrior(p);
    
    cout << "删除后的循环链表：";
    PrintLinkList(p);

    cout << "按回车键退出..." << endl;
    cin.get();
    return 0;
}
