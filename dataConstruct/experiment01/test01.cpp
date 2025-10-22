#include <iostream>
#include <vector>
using namespace std;

// 链表节点结构体
struct Person {
    int number;        // 人员编号
    Person* next;      // 指向下一个人的指针
    
    // 构造函数：创建新的人员节点
    Person(int num) {
        number = num;
        next = nullptr;
    }
};

// 约瑟夫问题：使用单向循环链表
// n: 总人数, m: 报数步长, k: 起始位置
int josephus(int n, int m, int k) {
    
    // 1. 创建循环链表
    Person* head = new Person(1);  // 创建第一个人
    Person* tail = head;           // 指向当前链表的最后一个人
    
    // 创建剩余的人并连接成循环链表
    for (int i = 2; i <= n; i++) {
        tail->next = new Person(i);
        tail = tail->next;
    }
    tail->next = head;  // 最后一个人指向第一个人，形成循环
    
    // 2. 移动到起始位置
    Person* curr = head;
    Person* prev = tail; // prev 始终指向 curr 的前一个人
    for (int i = 1; i < k; i++) {
        prev = curr;
        curr = curr->next;
    }
    
    vector<int> outOrder;  // 记录出局顺序
    int remaining = n;     // 剩余人数
    
    // 3. 循环删除直到只剩一人
    while (remaining > 1) {
        // 报数：移动 m-1 次，使 curr 指向要删除的人
        for (int i = 1; i < m; i++) {
            prev = curr;
            curr = curr->next;
        }

        outOrder.push_back(curr->number);
        
        // 删除当前节点
        prev->next = curr->next;
        Person* toDelete = curr;
        curr = curr->next;
        delete toDelete;
        --remaining;
    }
    
    // 4. 输出结果
    cout << "\n出局顺序：";
    for (int i = 0; i < outOrder.size(); i++) {
        cout << outOrder[i];
        if (i < outOrder.size() - 1) cout << " -> ";
    }
    cout << "\n最终幸存者：第" << curr->number << "个人" << endl;
    
    int survivor = curr->number;
    delete curr;  // 释放最后一个结点
    
    return survivor;
}

int main() {
    cout << "=== 约瑟夫问题===" << endl;
    
    int n, m, k;
    
    // 输入参数
    cout << "请输入总人数 n：";
    cin >> n;
    
    cout << "请输入报数步长 m：";
    cin >> m;
    
    cout << "请输入起始位置 k：";
    cin >> k;
    
    // 检查输入是否合法
    if (n <= 0 || m <= 0 || k <= 0 || k > n) {
        cout << "输入错误！请确保人数和步长大于0，起始位置在1到n之间。" << endl;
        return 0;
    }
    
    cout << "总人数：" << n << "，报数步长：" << m << "，起始位置：" << k;
    
    // 求解约瑟夫问题
    int winner = josephus(n, m, k);
    
    // 暂停程序，让用户看到结果
    cout << "\n按回车键退出...";
    cin.ignore();
    cin.get();
    
    return 0;
}
