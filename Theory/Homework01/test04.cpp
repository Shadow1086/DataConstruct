#include <iostream>
using namespace std;

// 功能描述：
// 线性表中有 n 个元素,每个元素是一个字符,现存于向量R[n]中,
// 试写一算法,使R中的字符按字母字符、数字字符和其他字符的顺序排列。
// 要求利用原来的存储空间,元素移动次数最小。

#define MAXSIZE 100
typedef char Element;

typedef struct {
  Element *elem;
  int length;
} SqList;

void sort(SqList &L) {
  // left是字母区，right是其他字符
  int i = 0, left = -1, right = L.length;
  for (i; i < right; i++) {
    // 是数字
    if (L.elem[i] >= '0' && L.elem[i] <= '9') {
    } else if (L.elem[i] >= 'a' && L.elem[i] <= 'z' ||
               L.elem[i] >= 'A' && L.elem[i] <= 'Z') {
      // 是字母
      left++;
      Element temp = L.elem[left];
      L.elem[left] = L.elem[i];
      L.elem[i] = temp;
    } else {
      // 是其他字符
      --right;
      Element temp = L.elem[right];
      L.elem[right] = L.elem[i];
      L.elem[i] = temp;
      i--;
    }
  }
}

int main() {
  SqList L;
  L.elem = new char[MAXSIZE];
  L.length = 0;
  char R[] = {'3', 'a', '#', 'b', '5', '@', 'c', '1', 'Z'};
  int n = 9;
  for (int i = 0; i < n; i++) {
    L.elem[i] = R[i];
  }
  L.length = n;

  sort(L);

  cout << "排序后：" << endl;
  for (int i = 0; i < L.length; i++) {
    cout << L.elem[i] << "\t";
  }

  cin.get();
  return 0;
}
