//
// Created by authetic on 2018/8/22.
//

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int arr[maxn],leftMax[maxn],rightMin[maxn],ans[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    leftMax[0] = 0;
    for (int i=1; i<n; i++) {
        leftMax[i] = max(leftMax[i-1], arr[i-1]);
    }
    rightMin[n-1] = 1000000001;
    for (int i=n-2; i>=0; i--) {
        rightMin[i] = min(rightMin[i+1], arr[i+1]);
    }
    int count=0;
    for (int i=0; i<n; i++) {
        if (arr[i]>leftMax[i] && arr[i]<rightMin[i]) {
            ans[count++] = arr[i];
        }
    }
    printf("%d\n", count);
    for (int i=0; i<count; i++) {
        printf("%d", ans[i]);
        if (i<count-1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}