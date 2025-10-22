#include <iostream>
using namespace std;
typedef int EleType;

// 功能描述：
//写一算法,只扫描一次单链表,就能找到链表中的倒数第n个结点。
typedef struct LNode{
    EleType data;
    struct LNode *next;
}LNode,*LinkList;

void InitLinkList(LinkList &L){
    L = new LNode;
    L->next = nullptr;
}

void CreateLinkList(LinkList &L,int arr[],int n){
    InitLinkList(L);
    LNode *tail = L;
    for(int i = 0;i<n;i++){
        LNode *newNode = new LNode;
        newNode->data = arr[i];
        tail->next = newNode;
        tail = newNode;
    }
    tail->next = nullptr;
}   

void PrintLinkList(LinkList L){
    LNode *p = L->next;
    while(p){
        cout << p->data << "\t";
        p=p->next;
    }
    cout  << endl;
    
}

LNode* FindNInList(LinkList L,int n){
    if(n <= 0){
        cout << "n需要大于0" << endl;
        return nullptr;
    }else{
        LNode *fast = L->next;
        LNode *slow =L->next;
        //让fast先走n步
        for(int i = 0;i<n;i++){
            if(fast == nullptr){
                cout << "链表超出长度" << endl;
                return nullptr;
            }
            fast = fast -> next;
        }

        //让slow and fast一起走
        while(fast != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        // if(slow != nullptr){
        //     cout << "倒数第"<<n<<"个节点的值是：" << slow->data << endl;
        // }else{
        //     cout << "未找到" << endl;
        // }
        return slow;
    }
}

int main() {
    LinkList L;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    
    CreateLinkList(L, arr, n);
    cout << "链表内容: ";
    PrintLinkList(L);
    
    // 测试倒数第1个
    LNode *result1 = FindNInList(L, 1);
    if (result1) {
        cout << "倒数第1个结点: " << result1->data << endl;
    }
    
    // 测试倒数第3个
    LNode *result3 = FindNInList(L, 3);
    if (result3) {
        cout << "倒数第3个结点: " << result3->data << endl;
    }
    
    // 测试倒数第5个
    LNode *result5 = FindNInList(L, 5);
    if (result5) {
        cout << "倒数第5个结点: " << result5->data << endl;
    }
    
    // 测试倒数第10个（第一个结点）
    LNode *result10 = FindNInList(L, 10);
    if (result10) {
        cout << "倒数第10个结点: " << result10->data << endl;
    }
    
    // 测试超出范围
    cout << "\n测试超出范围:" << endl;
    FindNInList(L, 15);

    cout << "按回车键退出..." << endl;
    cin.get();
    return 0;
}
