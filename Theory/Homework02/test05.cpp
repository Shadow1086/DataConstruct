#include <iostream>
using namespace std;
/**
 * FileName: test05
 * Description: 
 * 
 * 11.假设稀疏矩阵只存放其非0元素的行号、列号和数值,以一维数组顺次存放,用行号为 -1 作为结束标志。
 * 例如,如下所示的稀疏矩阵M（5行9列，每行9个元素）:
 * M = [1  0  0  0 10  0  0 0  0]
 *     [0  0  0  0  0  0  0 0  0]
 *     [0  0  0  0  0  0  0 0  5]
 *     [0  0  0  0  0  0  0  0 0]
 *     [0  0  0  0  0  0  0  0 0]
 * 
 * 则存在一维数组D中: D[0]=1, D[1]=1, D[2]=1, D[3]=1, D[4]=5, D[5]=-1
 * 
 * 现在有两个稀疏矩阵A和B，都采用上述方法存储，都是m行n列，分别存储在数组A和B中。
 * 编写算法计算矩阵加法C=A+B，结果C也存储在数组C中。
 * 
 * @Author Liang-ht
 * @Create 2025-11-06 18:57:22
 */

/**
 * 将稀疏矩阵存储到一维数组中
 * 存储格式：行号、列号、值，行号、列号、值，...，-1（结束标志）
 * 
 * @param matrix 二维矩阵
 * @param rows 矩阵行数
 * @param cols 矩阵列数
 * @param D 一维数组（输出参数）
 * @return 返回数组D中元素的个数（包括结束标志-1）
 */
int storeSparseMatrix(int** matrix, int rows, int cols, int* D) {
    int index = 0;
    
    // 遍历矩阵，找到所有非零元素
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                D[index++] = i;      // 行号
                D[index++] = j;      // 列号
                D[index++] = matrix[i][j];  // 值
            }
        }
    }
    
    // 添加结束标志：行号为-1
    D[index++] = -1;
    
    return index;  // 返回数组长度
}

/**
 * 从一维数组中恢复稀疏矩阵
 * 
 * @param D 一维数组
 * @param rows 矩阵行数
 * @param cols 矩阵列数
 * @param matrix 二维矩阵（输出参数）
 */
void restoreSparseMatrix(int* D, int rows, int cols, int** matrix) {
    // 初始化矩阵为全0
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }
    
    // 从一维数组中恢复非零元素
    int index = 0;
    while (D[index] != -1) {
        int row = D[index++];
        int col = D[index++];
        int value = D[index++];
        matrix[row][col] = value;
    }
}

/**
 * 打印一维数组
 */
void printArray(int* arr, int size) {
    cout << "一维数组D: ";
    for (int i = 0; i < size; i++) {
        cout << "D[" << i << "]=" << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

/**
 * 打印矩阵
 */
void printMatrix(int** matrix, int rows, int cols) {
    cout << "矩阵M (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "[";
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j];
            if (j < cols - 1) {
                cout << "  ";
            }
        }
        cout << "]" << endl;
    }
}

int main() {
    // 创建测试矩阵M：5x9（每行9个元素）
    
    const int ROWS = 5;
    const int COLS = 9;
    
    // 动态分配矩阵内存
    int** matrix = new int*[ROWS];
    for (int i = 0; i < ROWS; i++) {
        matrix[i] = new int[COLS];
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = 0;
        }
    }
    
    // 设置非零元素
    matrix[0][0] = 1;   // 第0行第0列 = 1
    matrix[0][4] = 10;  // 第0行第4列 = 10
    matrix[2][8] = 5;   // 第2行第8列 = 5（最后一列）
    
    // 打印原始矩阵
    cout << "原始稀疏矩阵" << endl;
    printMatrix(matrix, ROWS, COLS);
    cout << endl;
    
    // 存储到一维数组
    // 最多需要存储：非零元素个数*3 + 1（结束标志）
    // 这里最多3个非零元素，所以需要10个位置
    int D[10];
    int size = storeSparseMatrix(matrix, ROWS, COLS, D);
    
    // 打印一维数组
    cout << "存储到一维数组" << endl;
    printArray(D, size);
    cout << endl;
    
    // 验证：从一维数组恢复矩阵
    int** restoredMatrix = new int*[ROWS];
    for (int i = 0; i < ROWS; i++) {
        restoredMatrix[i] = new int[COLS];
    }
    
    restoreSparseMatrix(D, ROWS, COLS, restoredMatrix);
    
    cout << "从一维数组恢复的矩阵" << endl;
    printMatrix(restoredMatrix, ROWS, COLS);
    cout << endl;
    
    // 验证恢复是否正确
    bool isCorrect = true;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] != restoredMatrix[i][j]) {
                isCorrect = false;
                break;
            }
        }
        if (!isCorrect) break;
    }
    
    if (isCorrect) {
        cout << "成功" << endl;
    } else {
        cout << "失败" << endl;
    }
    
    // 释放内存
    for (int i = 0; i < ROWS; i++) {
        delete[] matrix[i];
        delete[] restoredMatrix[i];
    }
    delete[] matrix;
    delete[] restoredMatrix;
    
    cout << "\n按回车键退出" << endl;
    cin.get();
    return 0;
}