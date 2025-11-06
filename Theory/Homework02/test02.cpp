#include <cstring>
#include <iostream>
using namespace std;
/**
 * ClassName: test02
 * Description: 
 * 
 * 利用C的库函数strlen,strcpy(或stmcpy)写一个算法void StrDelete(char *S,int i,m)，删除串S中从位置i
 * 开始的连续的m个字符。若i>=strlen(S)，则没有字符被删除;
 * 若i+m>=strlen(S)，则将S中从位置i开始直至末尾的字符均被删去。
 * @Author Liang-ht
 * @Create 2025-11-02 17:57:14
 */
 void StrDelete(char *S,int i,int m){
    int len = strlen(S);
    if(i>=len){
        return;
    }
    if(i+m>=len){
        S[i] = '\0';
        return;
    }
    strcpy(S+i, S+i+m);
 }
int main() {
    char s1[100] = "Hello World";
    StrDelete(s1, 5, 1);  // 删除位置5的字符（空格）
    cout << "删除位置5的字符后: " << s1 << endl;

    cout << "按回车键退出" << endl;
    cin.get();
    return 0;
}