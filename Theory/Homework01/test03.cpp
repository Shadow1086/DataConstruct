#include <iostream>
using namespace std;

// 功能描述：写一个算法,从一个给定的顺序表A中删除值在x~y(x<=y)的所有元素,要求以较高的效率来实现。

typedef int Element;
#define MAXSIZE 100

typedef struct {
  Element *elem;
  int length;
} SqList;

void deleteEle(SqList &L, int x, int y) {
  int i = 0;
  for (int j = 0; j < L.length; j++) {
    if (L.elem[j] < x || L.elem[j] > y) {
      L.elem[i] = L.elem[j];
      i++;
    }
  }
  L.length = i;
}

int main() {
  SqList L;
  L.elem = new Element[MAXSIZE];
  L.length = 0;

  int arr[] = {1, 3, 5, 7, 9, 11, 13};
  int n = 7;
  for (int i = 0; i < n; i++) {
    L.elem[i] = arr[i];
  }
  L.length = n;

  deleteEle(L, 2, 5);

  cout << "删除后结果为：" << endl;

  for (int i = 0; i < L.length; i++) {
    cout << L.elem[i] << "\t";
  }

  cout << "按回车键退出..." << endl;
  cin.get();
  return 0;
}
