//
// Created by authetic on 2018/8/16.
//
#include <cstdio>

const int maxn = 100010;
int a[maxn], hashtable[10001] = {0};

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        hashtable[a[i]]++;
    }
    for (int i=0; i<n; i++) {
        if (hashtable[a[i]]==1) {
            printf("%d\n", a[i]);
            return 0;
        }
    }
    printf("None\n");
    return 0;
}