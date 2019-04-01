//
// Created by authetic on 2019/4/1.
//

/*
 * 机器人最多能走多少步，也是基本回溯问题
 * keys：弄清回溯得本质，什么时候需要回调？
 */

#include <iostream>
using namespace std;

int getNum(int row, int col) {
    int ans = 0;
    while (row != 0) {
        ans += row % 10;
        row /= 10;
    }
    while (col != 0) {
        ans += col % 10;
        col /= 10;
    }
    return ans;
}

bool check(int threshold, int row, int col, int rows, int cols,
            bool visited[]) {
    if (row >= 0 && row < rows && col < cols && !visited[row*cols + cols]
        && getNum(row, col) <= threshold) {
        return true;
    }
    return false;
}

int movingCountCore(int threshold, int row, int col, int rows, int cols,
                    bool visited[]) {
    int count = 0;
    if (check(threshold, row, col, rows, cols, visited)) {
        visited[row*cols + col] = true;
        count = 1 + movingCountCore(threshold, row-1, col, rows, cols,
                                    visited)
                    +movingCountCore(threshold, row+1, col, rows, cols,
                                     visited)
                    +movingCountCore(threshold, row, col-1, rows, cols,
                                    visited)
                    +movingCountCore(threshold, row, col+1, rows, cols,
                                    visited);
    }
    return count;
}

int movingCount(int threshold, int rows, int cols) {
    if (threshold < 0 || rows <= 0 || cols <= 0) {
        return 0;
    }
    bool visited[rows*cols];
    fill(visited, visited+rows*cols, 0);
    int count = movingCountCore(threshold, 0, 0, rows, cols, visited);
    return count;
}