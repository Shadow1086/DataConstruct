#include <iostream>
#include <cmath>
using namespace std;
/*
题目：一元多项式运算
问题描述：
设计算法实现一元多项式的简单运算。
基本要求：
    （1） 输入并建立多项式;
    （2） 输出多项式;
    （3） 多项式加法
    （4） 多项式减法。
*/

// 多项式节点结构
struct PolyNode {
    double coef;        // 系数
    int exp;            // 指数
    PolyNode* next;     // 指针域
    
    PolyNode(double c = 0, int e = 0) : coef(c), exp(e), next(nullptr) {}
};

// 多项式类
class Polynomial {
private:
    PolyNode* head;     // 头节点
    
public:
    // 构造函数
    Polynomial() {
        head = new PolyNode();  // 创建头节点
    }
    
    // 析构函数
    ~Polynomial() {
        PolyNode* p = head;
        while (p) {
            PolyNode* temp = p;
            p = p->next;
            delete temp;
        }
    }
    
    // 拷贝构造函数
    Polynomial(const Polynomial& other) {
        head = new PolyNode();
        PolyNode* p = other.head->next;
        PolyNode* tail = head;
        
        while (p) {
            PolyNode* newNode = new PolyNode(p->coef, p->exp);
            tail->next = newNode;
            tail = newNode;
            p = p->next;
        }
    }
    
    // 输入并建立多项式
    void create() {
        cout << "请输入多项式的项数: ";
        int n;
        cin >> n;
        cout << n << endl;  // 显示输入的项数
        
        cout << "请输入各项的系数和指数（按指数降序输入）:" << endl;
        cout << "格式：系数 指数（例如：3 2 表示 3x^2）" << endl;
        
        PolyNode* tail = head;
        for (int i = 0; i < n; i++) {
            double coef;
            int exp;
            cout << "第 " << (i + 1) << " 项: ";
            cin >> coef >> exp;
            cout << coef << " " << exp << endl;  // 显示输入的系数和指数
            
            if (coef != 0) {  // 系数为0的项不添加
                PolyNode* newNode = new PolyNode(coef, exp);
                tail->next = newNode;
                tail = newNode;
            }
        }
    }
    
    // 输出多项式
    void display() const {
        PolyNode* p = head->next;
        
        if (!p) {
            cout << "0" << endl;
            return;
        }
        
        bool isFirst = true;
        while (p) {
            // 处理符号
            if (!isFirst) {
                if (p->coef > 0) {
                    cout << " + ";
                } else {
                    cout << " - ";
                }
            } else {
                if (p->coef < 0) {
                    cout << "-";
                }
                isFirst = false;
            }
            
            // 处理系数
            double absCoef = fabs(p->coef);
            if (absCoef != 1 || p->exp == 0) {
                cout << absCoef;
            }
            
            // 处理指数
            if (p->exp != 0) {  // 只要指数不为0就显示x（包括负指数）
                cout << "x";
                if (p->exp != 1) {  // 指数不为1时显示指数（包括负指数）
                    cout << "^" << p->exp;
                }
            }
            
            p = p->next;
        }
        cout << endl;
    }
    
    // 多项式加法
    Polynomial add(const Polynomial& other) const {
        Polynomial result;
        PolyNode* p1 = head->next;
        PolyNode* p2 = other.head->next;
        PolyNode* tail = result.head;
        
        while (p1 && p2) {
            if (p1->exp > p2->exp) {
                // p1的指数大，添加p1的项
                PolyNode* newNode = new PolyNode(p1->coef, p1->exp);
                tail->next = newNode;
                tail = newNode;
                p1 = p1->next;
            } else if (p1->exp < p2->exp) {
                // p2的指数大，添加p2的项
                PolyNode* newNode = new PolyNode(p2->coef, p2->exp);
                tail->next = newNode;
                tail = newNode;
                p2 = p2->next;
            } else {
                // 指数相同，系数相加
                double sumCoef = p1->coef + p2->coef;
                if (sumCoef != 0) {  // 系数和不为0才添加
                    PolyNode* newNode = new PolyNode(sumCoef, p1->exp);
                    tail->next = newNode;
                    tail = newNode;
                }
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        
        // 添加剩余项
        while (p1) {
            PolyNode* newNode = new PolyNode(p1->coef, p1->exp);
            tail->next = newNode;
            tail = newNode;
            p1 = p1->next;
        }
        
        while (p2) {
            PolyNode* newNode = new PolyNode(p2->coef, p2->exp);
            tail->next = newNode;
            tail = newNode;
            p2 = p2->next;
        }
        
        return result;
    }
    
    // 多项式减法
    Polynomial subtract(const Polynomial& other) const {
        Polynomial result;
        PolyNode* p1 = head->next;
        PolyNode* p2 = other.head->next;
        PolyNode* tail = result.head;
        
        while (p1 && p2) {
            if (p1->exp > p2->exp) {
                // p1的指数大，添加p1的项
                PolyNode* newNode = new PolyNode(p1->coef, p1->exp);
                tail->next = newNode;
                tail = newNode;
                p1 = p1->next;
            } else if (p1->exp < p2->exp) {
                // p2的指数大，添加p2的负项
                PolyNode* newNode = new PolyNode(-p2->coef, p2->exp);
                tail->next = newNode;
                tail = newNode;
                p2 = p2->next;
            } else {
                // 指数相同，系数相减
                double diffCoef = p1->coef - p2->coef;
                if (diffCoef != 0) {  // 系数差不为0才添加
                    PolyNode* newNode = new PolyNode(diffCoef, p1->exp);
                    tail->next = newNode;
                    tail = newNode;
                }
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        
        // 添加剩余项
        while (p1) {
            PolyNode* newNode = new PolyNode(p1->coef, p1->exp);
            tail->next = newNode;
            tail = newNode;
            p1 = p1->next;
        }
        
        while (p2) {
            PolyNode* newNode = new PolyNode(-p2->coef, p2->exp);
            tail->next = newNode;
            tail = newNode;
            p2 = p2->next;
        }
        
        return result;
    }
};

int main() {
    Polynomial poly1, poly2;
    
    cout << "========== 一元多项式运算系统 ==========" << endl;
    
    // 输入第一个多项式
    cout << "\n输入第一个多项式:" << endl;
    poly1.create();
    
    // 输入第二个多项式
    cout << "\n输入第二个多项式:" << endl;
    poly2.create();
    
    // 输出多项式

    cout << "多项式1: ";
    poly1.display();
    cout << "多项式2: ";
    poly2.display();
    
    // 选择运算类型
    cout << "\n请选择运算类型:" << endl;
    cout << "1. 加法" << endl;
    cout << "2. 减法" << endl;
    cout << "请输入选择（1或2）: ";
    
    int choice;
    cin >> choice;
    cout << choice << endl;  // 显示用户输入
    
    if (choice == 1) {
        // 多项式加法
        cout << "\n========== 多项式加法 ==========" << endl;
        Polynomial sum = poly1.add(poly2);
        cout << "多项式1 + 多项式2 = ";
        sum.display();
    } else if (choice == 2) {
        // 多项式减法
        cout << "\n========== 多项式减法 ==========" << endl;
        Polynomial diff = poly1.subtract(poly2);
        cout << "多项式1 - 多项式2 = ";
        diff.display();
    } else {
        cout << "\n输入错误！请输入1或2。" << endl;
        return 1;
    }
    
    cout << "\n程序执行完毕！" << endl;
    
    return 0;
}
