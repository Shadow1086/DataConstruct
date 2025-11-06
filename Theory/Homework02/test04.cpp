#include <iostream>
using namespace std;
/**
 * FileName: test04
 * Description: 
 * 
 * 5.假设稀疏矩阵A和B(具有相同的大小mxn)都采用三元组表存储，编写一个算法计算C=A+B，要求C也采用三元组表存储。
 * @Author Liang-ht
 * @Create 2025-11-06 18:55:03
 */

// 三元组结构：存储非零元素的行号、列号和值
struct Triple {
    int row;    // 行号
    int col;    // 列号
    int value;  // 值
};

// 稀疏矩阵结构：采用三元组表存储
struct SparseMatrix {
    int rows;        // 矩阵行数
    int cols;        // 矩阵列数
    int numNonZero;  // 非零元素个数
    Triple* data;     // 三元组数组
    int capacity;     // 数组容量
    
    // 构造函数
    SparseMatrix(int m, int n, int capacity = 100) {
        this->rows = m;
        this->cols = n;
        this->numNonZero = 0;
        this->capacity = capacity;
        this->data = new Triple[capacity];
    }
    
    // 析构函数
    ~SparseMatrix() {
        delete[] data;
    }
    
    // 添加一个三元组
    void addTriple(int row, int col, int value) {
        if (value == 0) return; // 不存储零元素
        if (numNonZero >= capacity) {
            // 扩容
            capacity *= 2;
            Triple* newData = new Triple[capacity];
            for (int i = 0; i < numNonZero; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[numNonZero].row = row;
        data[numNonZero].col = col;
        data[numNonZero].value = value;
        numNonZero++;
    }
    
    // 打印矩阵（以三元组形式）
    void print() {
        cout << "稀疏矩阵（" << rows << "x" << cols << "），非零元素个数：" << numNonZero << endl;
        cout << "三元组表：" << endl;
        cout << "行\t列\t值" << endl;
        for (int i = 0; i < numNonZero; i++) {
            cout << data[i].row << "\t" << data[i].col << "\t" << data[i].value << endl;
        }
    }
    
    // 打印完整矩阵（用于验证）
    void printFullMatrix() {
        // 创建完整矩阵并初始化为0
        int** matrix = new int*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = 0;
            }
        }
        
        // 填充非零元素
        for (int i = 0; i < numNonZero; i++) {
            matrix[data[i].row][data[i].col] = data[i].value;
        }
        
        // 打印
        cout << "完整矩阵：" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
        
        // 释放内存
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
};

/**
 * 稀疏矩阵加法算法：C = A + B
 * 时间复杂度：O(A.numNonZero + B.numNonZero)
 */
SparseMatrix* addSparseMatrix(SparseMatrix& A, SparseMatrix& B) {
    // 检查矩阵大小是否相同
    if (A.rows != B.rows || A.cols != B.cols) {
        cout << "错误：矩阵大小不匹配！" << endl;
        return nullptr;
    }
    
    // 创建结果矩阵
    SparseMatrix* C = new SparseMatrix(A.rows, A.cols, A.numNonZero + B.numNonZero);
    
    int i = 0, j = 0; // i指向A的三元组，j指向B的三元组
    
    // 归并两个三元组表
    while (i < A.numNonZero && j < B.numNonZero) {
        // 比较当前两个三元组的位置
        if (A.data[i].row < B.data[j].row || 
            (A.data[i].row == B.data[j].row && A.data[i].col < B.data[j].col)) {
            // A的元素位置在前，直接加入C
            C->addTriple(A.data[i].row, A.data[i].col, A.data[i].value);
            i++;
        }
        else if (A.data[i].row > B.data[j].row || 
                 (A.data[i].row == B.data[j].row && A.data[i].col > B.data[j].col)) {
            // B的元素位置在前，直接加入C
            C->addTriple(B.data[j].row, B.data[j].col, B.data[j].value);
            j++;
        }
        else {
            // 位置相同，值相加
            int sum = A.data[i].value + B.data[j].value;
            if (sum != 0) { // 如果和不为0，才加入结果
                C->addTriple(A.data[i].row, A.data[i].col, sum);
            }
            i++;
            j++;
        }
    }
    
    // 将剩余的三元组加入结果
    while (i < A.numNonZero) {
        C->addTriple(A.data[i].row, A.data[i].col, A.data[i].value);
        i++;
    }
    
    while (j < B.numNonZero) {
        C->addTriple(B.data[j].row, B.data[j].col, B.data[j].value);
        j++;
    }
    
    return C;
}

int main() {
    // 创建测试矩阵A：3x4
    // A = [1  0  3  0]
    //     [0  0  0  0]
    //     [0  2  0  4]
    SparseMatrix A(3, 4);
    A.addTriple(0, 0, 1);
    A.addTriple(0, 2, 3);
    A.addTriple(2, 1, 2);
    A.addTriple(2, 3, 4);
    
    // 创建测试矩阵B：3x4
    // B = [2  0  1  0]
    //     [0  3  0  0]
    //     [0  1  0  2]
    SparseMatrix B(3, 4);
    B.addTriple(0, 0, 2);
    B.addTriple(0, 2, 1);
    B.addTriple(1, 1, 3);
    B.addTriple(2, 1, 1);
    B.addTriple(2, 3, 2);
    
    // 打印矩阵A和B
    cout << " 矩阵A " << endl;
    A.print();
    A.printFullMatrix();
    cout << endl;
    
    cout << "矩阵B" << endl;
    B.print();
    B.printFullMatrix();
    cout << endl;
    
    // 计算C = A + B
    SparseMatrix* C = addSparseMatrix(A, B);
    
    if (C != nullptr) {
        cout << "矩阵C = A + B" << endl;
        C->print();
        C->printFullMatrix();
        
        // 验证：C应该是
        // [3  0  4  0]
        // [0  3  0  0]
        // [0  3  0  6]
        
        delete C;
    }
    
    cout << "\n按回车键退出" << endl;
    cin.get();
    return 0;
}