//
// Created by authetic on 2019/3/31.
//

/*
 * 返回一个大小为n+1，数据范围为1-n的数组中的重复数字，
 * 要求不能改动数组
 * 1. 使用hash，时间复杂度O(n)，空间复杂度O(n)
 * 2. 二分法，判断一段区间内数字出现的次数是否大于区间长度，时间复杂度O(n*lgn)
 * PS: 针对不同需求采用不同方法，追求时间效率或者空间效率
 */

#include <iostream>
using namespace std;


int get_count(const int a[], int len, int st, int ed) {
    if (a == nullptr) return 0;
    int count = 0;
    for (int i = 0; i < len; i ++ ) {
        if (a[i] >= st && a[i] <= ed) count ++;
    }
    return count;
}

int get_duplication(const int a[], int len) {
    if (a == nullptr || len <= 0) return -1;
    int start = 1, end = len-1;
    while (start < end) {
        int middle = 1 + (end-start) / 2;
        int count = get_count(a, len, start, middle);
        if (end == start) {
            if (count > 1) return start;
            else break;
        }
        if (count > (middle-start)+1) {
            end = middle;
        } else {
            start = middle + 1;
        }
    }
    return -1;
}