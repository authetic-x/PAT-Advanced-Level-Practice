//
// Created by authetic on 2018/11/1.
/*
 * 树状数组的应用，相当于用hash存储每个数的出现次数
 * 然后求和的过程使用树状数组
 */
//

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

const int maxn = 100010;

#define lowbit(x) ((x)&-(x))

stack<int> s;
int c[maxn];

void update(int x, int v) {
    for (int i = x; i < maxn; i += lowbit(i)) {
        c[i] += v;
    }
}

int getSum(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        sum += c[i];
    }
    return sum;
}

void PeekMedian() {
    int l=1, r=maxn, mid, K = (s.size()+1)/2;
    while (l < r) {
        mid = (l+r)/2;
        if (getSum(mid) >= K) r = mid;
        else l = mid+1;
    }
    printf("%d\n", l);
}

int main() {
    int n, x;
    char str[12];
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) {
        scanf("%s", str);
        if (strcmp(str, "Push") == 0) {
            scanf("%d", &x);
            s.push(x);
            update(x, 1);
        } else if (strcmp(str, "Pop") == 0) {
            if (s.empty()) {
                printf("Invalid\n");
            } else {
                printf("%d\n", s.top());
                update(s.top(), -1);
                s.pop();
            }
        } else if (strcmp(str, "PeekMedian") == 0) {
            if (s.empty()) printf("Invalid\n");
            else {
                PeekMedian();
            }
        }
    }
    return 0;
}
