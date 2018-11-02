//
// Created by authetic on 2018/11/2.
/*
 * 旋转矩阵，有一个运行超时
 */
//

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 10010;

int a[maxn], matrix[maxn][maxn];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i ++ ) {
        scanf("%d", &a[i]);
    }
    if (N == 1) {
        printf("%d\n", a[0]);
        return 0;
    }
    sort(a, a+N, cmp);

    int m, n;
    m = (int)ceil(sqrt(N));
    while (N % m != 0) {
        m ++;
    }
    n = N / m;
    int i=1, j=1, now=0;
    int L=1, R=n, U=1, D=m;

    while (now < N) {
        while (now < N && j < R) {
            matrix[i][j] = a[now++];
            j++;
        }
        while (now < N && i < D) {
            matrix[i][j] = a[now++];
            i++;
        }
        while (now < N && j > L) {
            matrix[i][j] = a[now++];
            j--;
        }
        while (now < N && i > U) {
            matrix[i][j] = a[now++];
            i--;
        }
        L++, U++, R--, D--;
        i++, j++;
        if (now == N-1) {
            matrix[i][j] = a[now];
        }
    }
    for (int i = 1; i <= m; i ++ ) {
        for (int j = 1; j <= n; j ++ ) {
            if (j == n) {
                printf("%d\n", matrix[i][j]);
            } else {
                printf("%d ", matrix[i][j]);
            }
        }
    }
    return 0;
}