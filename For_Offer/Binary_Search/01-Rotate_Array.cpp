//
// Created by authetic on 2019/4/1.
//

/*
 * 旋转数组，将一段排序的数组的前一部分移到后面，求数组的最小值
 * keys: 二分法，Two Pointers，理解旋转数组的性质就可以快速
 * 缩小搜索空间，注意特例，如三点值相等时!
 */

#include <iostream>
#include <exception>
using namespace std;

int minInorder(int a[], int index1, int index2) {
    int res = a[index1];
    for (int i = index1+1; i <= index2; i ++ ) {
        if (res > a[i]) {
            res = a[i];
        }
    }
    return res;
}

int Min(int a[], int len) {
    if (a == nullptr || len <= 0) {
        // throw new exception('Invalid paras');
    }
    int index1 = 0, index2 = len-1;
    int midIndex = index1;
    while (a[index1] >= a[index2]) {
        if (index2 - index1 == 1) {
            midIndex = index2;
            break;
        }
        midIndex = (index1 + index2) / 2;
        if (a[index1] == a[index2] && a[index1] == a[midIndex]) {
            return minInorder(a, index1, index2);
        }
        if (a[midIndex] >= a[index1]) {
            index1 = midIndex;
        }
        if (a[midIndex] <= a[index2]) {
            index2 = midIndex;
        }
    }
    return a[midIndex];
}
