//
// Created by authetic on 2018/8/21.
/*
 * 将两个有序数组合并输出中位数。
 * 题目不难，坑多，最后测试有一个内存超限。。
 */
//

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 2000010;
int a[maxn];

int main() {
    int m,n;
    scanf("%d", &m);
    for (int i=0; i<m; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &n);
    for (int i=m; i<m+n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a+m+n);
    if ((m+n)%2==0) {
        printf("%d\n", a[(m+n)/2-1]);
    } else {
        printf("%d\n", a[(m+n)/2]);
    }
    return 0;
}