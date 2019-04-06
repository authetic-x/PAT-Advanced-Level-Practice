//
// Created by authetic on 2019/4/6.
//

/*
 * 连续最大子序列的两种实现方法
 * 分治和Online_Solve，其中分治实现的麻烦一点
 * 第一次还是没有写对，果然太菜！=_=
 */

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 10000;

int a[MAXN], n;

// -----时间复杂度O(n*log(n))-----
int Divide_Conquer(int l, int r) {
    if (l == r) return a[l];
    int mid = (l + r) / 2;
    // 左边部分最大子序列
    int left = Divide_Conquer(l, mid);
    int right = Divide_Conquer(mid+1, r);
    int i = mid-1, j = mid+2;
    // 交叉部分最大子序列
    int maxCross = a[mid] + a[mid+1];
    int thisSum = 0;
    while (i >= l) {
        thisSum += a[i];
        if (thisSum + maxCross > maxCross) {
            maxCross = thisSum + maxCross;
        }
        i --;
    }
    thisSum = 0;
    while (j <= r) {
        thisSum += a[j];
        if (thisSum + maxCross > maxCross) {
            maxCross = thisSum + maxCross;
        }
        j ++;
    }
    return max(maxCross, max(left, right));
}

// -----时间复杂度O(n)-----
int online_solve() {
    int maxSum = 0, thisSum = 0;
    for (int i = 0; i < n; i ++ ) {
        thisSum += a[i];
        if (thisSum > maxSum ) maxSum = thisSum;
        else if (thisSum < 0) thisSum = 0;
    }
    return maxSum;
}

int main() {
    n = 5;
    for (int i = 0; i < 5; i ++ ) {
        cin >> a[i];
    }
    int res1 = Divide_Conquer(0, 4);
    int res2 = online_solve();
    cout << "DC: " << res1 << "  Online: " << res2;
    return 0;
}