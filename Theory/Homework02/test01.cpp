#include <iostream>
#include <string>
#include <vector>
using namespace std;
/**
 * ClassName: test01
 * Description:
 *
 *  2.设字符串S="aabaabaabaac", P="aabaac",
 *   试求:    给出 S 和 P 的 next值。
 * @Author Liang-ht
 * @Create 2025-11-02 17:58:22
 */

void findSNext(string str, vector<int> &next);

int main() {
  string s = "aabaabaabaac";
  vector<int> sNext;
  string p = "aabaac";
  vector<int> pNext;

  findSNext(s, sNext);
  cout << "字符串S：" << s << endl;
  cout << "S的next数组：";
  for (int i = 0; i < sNext.size(); i++) {
    cout << sNext[i] << " ";
  }
  cout << endl;

  findSNext(p, pNext);
  cout << "字符串P：" << p << endl;
  cout << "P的next数组：";
  for (int i = 0; i < pNext.size(); i++) {
    cout << pNext[i] << " ";
  }
  cout << endl;
  cout << "按回车键退出" << endl;
  cin.get();
  return 0;
}

void findSNext(string str, vector<int> &next) {
  int len = str.length();
  next.resize(len);
  next[0] = -1;
  int i = 0, j = -1;
  while (i < len - 1) {
    if (j == -1 || str[i] == str[j]) {
      i++, j++;
      next[i] = j;
    } else {
      j = next[j];
    }
  }
}