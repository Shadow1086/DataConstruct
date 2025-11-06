#include <iostream>
#include <cstring>
using namespace std;
/**
 * FileName: test03
 * Description: 
 * 作业二第一题
 * 利用C的库函数 strlen、strcpy 和 strcat 写一个算法 void StrInsert(char *s,char *t,int i),
 * 将串t插入到s的第i个位置上。若i大于s的长度，则插入不执行。
 * @Author Liang-ht
 * @Create 2025-11-04 23:43:45
 */

void StrInsert(char *s,char *t,int i){
    int len_s = strlen(s);
    if(i>len_s){
        return; //如果i大于s的长度，不执行
    }
    //创建临时字符串保存s的后半部分
    char temp[1000];
    strcpy(temp,s+1);

    s[i] = '\0';
    strcat(s,t);
    strcat(s, temp);
}

int main() {
    char s[100] = "Hello World";  // 确保有足够空间
    char ch[] = "nice ";
    
    cout << "插入前: " << s << endl;
    StrInsert(s, ch, 6);  // 在第6个位置（'W'的位置）插入
    cout << "插入后: " << s << endl;
    
    cout << "按回车键退出" << endl;
    cin.get();
    return 0;
}
