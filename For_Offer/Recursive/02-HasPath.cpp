//
// Created by authetic on 2019/4/1.
//

/*
 * (!)回溯的应用，给出一个字符二维矩阵和一个字符串数组，判断字符
 * 数组中的路径是否在存在于矩阵中
 * keys: 本身时简单的递归，但参数比较多，需要注意递归边界的
 * 判断以及回溯时标记值得还原！
 */

#include <iostream>
using namespace std;

bool hasPathCore(char matrix[], int rows, int cols, char str[],
                 int row, int col, int& lenPath, bool visited[]) {
    if (str[lenPath] == '\0') return true;
    bool hasPath = false;
    if (row < rows && row >= 0 && col >= 0 && col < cols) {
        if (matrix[row*cols + col] == str[lenPath] &&
            !visited[row*cols + col]) {
            lenPath ++;
            visited[row*cols + col] = true;
            hasPath = hasPathCore(matrix, rows, cols, str,
                                  row - 1, col, lenPath, visited)
                      || hasPathCore(matrix, rows, cols, str,
                                     row + 1, col, lenPath, visited)
                      || hasPathCore(matrix, rows, cols, str,
                                     row, col - 1, lenPath, visited)
                      || hasPathCore(matrix, rows, cols, str,
                                     row, col + 1, lenPath, visited);
            if (!hasPath) {
                lenPath --;
                visited[row*cols + col] = false;
            }
        }
    }
    return hasPath;
}

bool hasPath(char matrix[], int rows, int cols, char str[]) {
    if (matrix == nullptr || rows < 0 || cols < 0 || str == nullptr) {
        return false;
    }
    bool visited[rows * cols];
    fill(visited, visited+rows*cols, 0);
    int lenPath = 0;
    for (int i = 0; i < rows; i ++ ) {
        for (int j = 0; j < cols; j ++ ) {
            if (hasPathCore(matrix, rows, cols, str, i, j,
                    lenPath, visited)) {
                return true;
            }
        }
    }
    return false;
}