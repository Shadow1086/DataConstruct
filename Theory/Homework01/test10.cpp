#include <iostream>
#include <stack>
using namespace std;

// 功能描述：
// 称正读和反读都相同的字符序列为“回文”,
// 例如, "abeddcba” "qwerewq”是回文，“ashgash”不是回文。
// 试写一个算法判断读入的一个以‘@’为结束符的字符序列是否为回文。

bool isPalindrome() {
  stack<char> s;
  string str = "";
  char ch;

  cout << "请输入字符（以@结尾）" << endl;

  while (cin >> ch && ch != '@') {
    str += ch;
    s.push(ch);
  }

  for (int i = 0; i < str.length(); i++) {
    if (str[i] != s.top()) {
      return false;
    }
    s.pop();
  }
  return true;
}

int main() {
  if (isPalindrome()) {
    cout << "是回文！" << endl;
  } else {
    cout << "不是回文！" << endl;
  }

  cout << "按回车键退出..." << endl;
  cin.get();
  cin.get();
  return 0;
}
