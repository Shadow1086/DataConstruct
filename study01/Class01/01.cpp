#include <iostream>
using namespace std;

// 功能描述：生成一个顺序表

//------顺序表的存储结构--------
#define MAXSIZE 100
typedef int ElemType;

typedef struct {
  ElemType *elem;
  int length;
} SqList;

// 查找元素
int findEle(int target, SqList &L) {
  for (int i = 0; i < L.length; i++) {
    if (target == L.elem[i]) {
      return i;
    }
  }
  return 0;
}

// 插入元素
bool insertNum(ElemType target, int index, SqList &L) {
  if (index > L.length || index <= 0 || L.length == MAXSIZE) {
    return false;
  } else {
    for (int j = L.length - 1; j >= index - 1; j--) {
      L.elem[j + 1] = L.elem[j];
    }
    L.elem[index - 1] = target;
    ++L.length;
    return true;
  }
}

//删除元素
bool deleteNum(ElemType target , SqList &L){
    for(int i= 0;i<L.length;i++){
        if(target == L.elem[i]){
            for(int j = i;j<L.length;j++){
                L.elem[j] = L.elem[j + 1];
            }
            L.length--;
            return true;
        }
    }
    return false;
}

int main() {
    // 创建顺序表
    SqList L;

    L.elem = new ElemType[MAXSIZE]; // 动态分配数组空间
    L.length = 0;                   // 初始化长度为0

    // 插入一些元素
    for (int i = 0; i < 5; i++) {
      L.elem[i] = i + 1;
      L.length++;
    }

    // 输出顺序表
    cout << "顺序表内容：" << endl;
    for (int i = 0; i < L.length; i++) {
     cout << L.elem[i] << " ";
    }
    cout << endl; // 添加换行

    cout << "顺序表长度：" << L.length << endl;

    cout << "寻找元素：" << endl;

    cout << findEle(2, L) << endl;

    cout << "插入元素" << endl;
    //插入元素
    insertNum(10, 2, L);

    cout << "插入后的：" << endl;
    
    for (int i = 0; i < L.length; i++) {
     cout << L.elem[i] << " ";
    }
    cout << endl; // 添加换行

//删除元素
    cout << "删除后的" << endl;
    
    deleteNum(10, L);
        
    for (int i = 0; i < L.length; i++) {
        cout << L.elem[i] << " ";
       }
       cout << endl; // 添加换行

    delete[] L.elem;  // 释放内存
    L.elem = nullptr; // 防止悬空指针

    cout << "按回车键退出..." << endl;
    cin.get(); // 使用cin.get()代替getchar()
    return 0;
}
