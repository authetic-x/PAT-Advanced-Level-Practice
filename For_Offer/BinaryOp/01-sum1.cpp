//
// Created by authetic on 2019/4/1.
//

/*
 * 求出整数二进制形式中1的个数
 * 位运算的基本操作，注意二进制的性质
 */

#include <iostream>
using namespace std;

// 当n为负数时，右移左边不断加1，程序陷入死循环
int numberOf1_crude(int n) {
    int count = 0;
    while (n) {
        if (n & 1) count ++;
        n = n >> 1;
    }
    return count;
}

int numberOf1_better(int n) {
    int count = 0, flag = 1;
    while (flag) {
        if (n & flag) {
            count ++;
        }
        flag = flag << 1;
    }
    return count;
}

int numberOf1_best(int n) {
    int count = 0;
    while (n) {
        count ++;
        n = (n-1) & n;
    }
    return n;
}