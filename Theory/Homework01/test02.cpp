#include <iostream>
using namespace std;

// 功能描述：已知一顺序表A,其元素值非递减有序排列,
// 编写一个算法删除顺序表中多余的值相同的元素。
typedef int Element;
#define MAXSIZE 100

typedef struct {
  Element *elem;
  int length;
} SqList;

void deleteEle(SqList &L) {
  if (L.length < 1)
    return;
  // 慢指针
  int i = 0;
  for (int j = 1; j < L.length; j++) {
    if (L.elem[j] !=
        L.elem
            [i]) { // 遇到一个新元素就保存下来，最后将长度更改为共遇到的新元素的值
      i++;
      L.elem[i] = L.elem[j];
    }
  }
  L.length = i + 1;
}

int main() {
  // 初始化
  SqList L;
  L.elem = new Element[MAXSIZE];
  L.length = 0;
  int arr[] = {1, 2, 2, 2, 3, 4, 4, 5};
  int n = 8;
  for (int i = 0; i < 8; i++) {
    L.elem[i] = arr[i];
  }
  L.length = n;

  deleteEle(L);

  cout << "删除后的表：" << endl;
  for (int i = 0; i < L.length; i++) {
    cout << L.elem[i] << "\t";
  }

  cin.get();
  return 0;
}
