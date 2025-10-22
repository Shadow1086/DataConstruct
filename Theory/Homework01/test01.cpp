#include <iostream>
using namespace std;

// 设线性表存放在向量A[arrsize]的前elenum个分量中,且递增有序。
//  试写一算法,将x插入到线性表的适当位置上,以保持线性表的有序性,
//  并且分析算法的时间复杂度。

int main() {
  int A[100];
  int elenum = 5;
  for (int i = 0; i < elenum; i++) {
    A[i] = i + 1;
  }
  cout << "请输入您插入的数：";
  int num;
  cin >> num;
  cin.get();

  int index = -1;
  for (int i = 0; i < elenum; i++) {
    if (num <= A[i]) {
      index = i;
      break;
    }
  }
  //   cout << "index= " << index << endl;
  if ((index == -1) && num >= A[elenum - 1]) {
    index = elenum;
    A[index] = num;
  } else {
    A[elenum] = 0;
    for (int i = elenum; i >= index; i--) {
      int temp = A[i - 1];
      A[i - 1] = A[i];
      A[i] = temp;
    }
  }
  cout << "插入后的数列：" << endl;
  for (int i = 0; i <= elenum; i++) {
    cout << A[i] << "\t";
  }
  getchar();
  return 0;
}
