//
// Created by authetic on 2018/8/20.
/*
 * 给出一串数列，求其中连续部分相加的值等于或最接近于给定的值
 * 输出左端点和右端点。
 * key: 第一次做毫无头绪，笔记上是用数组存储1-n逐项相加的值，
 * 根据sum[j]-sum[i-1]>=s，利用二分法依次找出j的位置，先判断
 * 最接近的值，再用循环输出满足条件的左右端点。Q：对二分法临界值
 * 的问题太过陌生。
 */
//

#include <cstdio>

const int maxn = 100010;

int n,amount,log=100000001;
int sum[maxn];

int binarySearch(int left, int right, int s) {
    int mid;
    while (left<right) {
        mid = (left+right)/2;
        if (sum[mid]>s) {
            right = mid;
        } else {
            left = mid+1;
        }
    }
    return left;
}

int main() {
    scanf("%d %d", &n, &amount);
    sum[0] = 0;
    for (int i=1; i<=n; i++) {
        int temp;
        scanf("%d", &temp);
        sum[i] = sum[i-1]+temp;
    }
    for (int i=1; i<=n; i++) {
        int j = binarySearch(i,n+1,amount+sum[i-1]);
        if (sum[j-1]-sum[i-1]==amount) {
            log = amount;
            break;
        } else if (j<=n && sum[j]-sum[i-1]<log) {
            log = sum[j] - sum[i-1];
        }
    }
    for (int i=1; i<=n; i++) {
        int j = binarySearch(i,n+1,log+sum[i-1]);
        if (sum[j-1]-sum[i-1]==log) {
            printf("%d-%d\n", i, j-1);
        }
    }
    return 0;
}