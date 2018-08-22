//
// Created by authetic on 2018/8/19.
/*
 * 求数列中可组成完美数列的最大长度，max <= min*p
 * key: 先排序，再从第一个数开始找第一个大于min*p的数的位置（二分法）
 * 即可得出不同长度数列满足条件的最大值，再比较即可！
 */
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int maxn = 100010;
int a[maxn];

int binarySearch(int left, int right, ll p) {
    if (a[right]<=p) return right+1;
    int mid;
    while (left<right) {
        mid = (left+right)/2;
        if (a[mid]<=p) {
            left = mid+1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    int n,p;
    scanf("%d %d", &n, &p);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    int ans = 1;
    for (int i=0; i<n; i++) {
        int temp = binarySearch(i,n-1,(ll)a[i]*p);
        ans = max(ans, temp-i);
    }
    printf("%d\n", ans);
    return 0;
}
