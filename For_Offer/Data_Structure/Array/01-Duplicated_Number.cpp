//
// Created by authetic on 2019/3/31.
//

/*
 * 判断一个大小为n，数据范围为0-n-1的数组中是否有重复数字，
 * 如果有，随机返回一个
 * 1. 先排序，然后遍历，时间复杂度O(n*lgn)
 * 2. 设置一个大小为n的hash，时间复杂度O(n)，增加了空间复杂度
 * 3. 利用0-n-1数据范围的性质，将数据还原到本身的下标位置，复杂度O(n)
 */

#include <iostream>
using namespace std;

bool duplicate(int a[], int len, int *duplication) {
    if (a == nullptr || len < 0) return false;
    for (int i = 0; i < len; i ++ ) {
        if (a[i] < 0 || a[i] >= len) return false;
    }

    for (int i = 0; i < len; i ++ ) {
        while (a[i] != i) {
            if (a[i] == a[a[i]]) {
                *duplication = a[i];
                return true;
            }
            int tmp = a[i];
            a[i] = a[a[i]];
            a[a[i]] = tmp;
        }
    }
    return false;
}

int main() {
    int a[3], b;
    for (int i = 0; i < 3; i ++ ) cin >> a[i];
    bool ans = duplicate(a, 3, &b);
    cout << b;
    return 0;
}