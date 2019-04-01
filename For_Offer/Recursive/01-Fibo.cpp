//
// Created by authetic on 2019/4/1.
//

/*
 * 斐波那契数列的应用
 * 1. 青蛙跳台
 * 2. 小矩形覆盖大矩形的方案
 */

#include <iostream>
using namespace std;

// 这种方案包含大量重复计算，效率较低
int Fibo_recur(int n) {
    if (n <= 0) return 0;
    if (n <= 1) return 1;
    return Fibo_recur(n-1) + Fibo_recur(n-2);
}

int Fibo_better(int n) {
    if (n <= 0) return 0;
    if (n <= 1) return 1;
    int miniOne = 0, miniTwo = 1;
    int res = 0;
    for (int i = 2; i <= n; i ++ ) {
        res = miniOne + miniTwo;
        miniOne = miniTwo;
        miniTwo = res;
    }
    return res;
}