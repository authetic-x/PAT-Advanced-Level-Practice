//
// Created by authetic on 2019/4/1.
//

/*
 * 剪绳子，动态规划或者贪心
 */

#include <iostream>
#include <cmath>
using namespace std;

int MaxCutting_dp(int len) {
    if (len <= 0) return 0;
    if (len < 1) return 0;
    if (len <= 2) return 1;
    if (len == 3) return 2;
    int product[len+1];
    product[1] = 1;
    product[2] = 1;
    product[3] = 2;
    for (int i = 4; i <= len; i ++ ) {
        int max = 0;
        for (int j = 1; j <= i/2; j ++ ) {
            if (product[j] + product[i-j] > max) {
                max = product[j] + product[i-j];
            }
        }
        product[i] = max;
    }
    return product[len];
}

int MaxCutting_greed(int len) {
    if (len < 2) return 0;
    if (len == 2) return 1;
    if (len == 3) return 2;
    int timeOf3 = len / 3;
    if (len - timeOf3*3 == 1) {
        return (int)pow(3, timeOf3) + 4;
    } else {
        return (int)pow(3, timeOf3) + (len - timeOf3*3) / 2;
    }
}