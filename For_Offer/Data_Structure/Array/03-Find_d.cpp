//
// Created by authetic on 2019/3/31.
//

/*
 * 给出一个每一行，每一列都是递增的二维数组，判断给出的数字是否在
 * 数组中出现过
 * Keys: 从右上角或者左下角判断，每次可以剔除一行或者一列
 */

#include <iostream>
using namespace std;

bool find(int a[], int rows, int columns, int target) {
    bool found = false;
    if (a != nullptr && rows > 0 && columns > 0) {
        int row = 0;
        int column = columns - 1;
        while (row < rows && column >= 0) {
            if (a[row * columns + column] == target) {
                found = true;
                break;
            }
            if (a[row * columns + column] > target) {
                column --;
            } else {
                row ++;
            }
        }
    }
    return found;
}