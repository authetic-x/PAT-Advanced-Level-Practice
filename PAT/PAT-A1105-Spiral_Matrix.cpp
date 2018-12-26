//
// Created by authetic on 2018/12/26.
/*
 * 注意n和m的求法，不能简单平方后再加一
 */
//

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 10010;

int a[maxn], matrix[maxn][maxn];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int N, m, n;
    scanf("%d", &N);
    for (int i = 0; i < N; i ++ ) {
        scanf("%d", &a[i]);
    }
    if (N == 1) {
        printf("%d", a[0]);
        return 0;
    }
    sort(a, a + N, cmp);
    m = (int)ceil(sqrt(N));
    while (N % m != 0) {
        m ++;
    }
    n = N / m;
    int i = 0, j = 0, now = 0;
    int L = 0, R = n-1, U = 0, D = m-1;
    while (now < N) {
        while (j < R && now < N) {
            matrix[i][j++] = a[now++];
        }
        while (i < D && now < N) {
            matrix[i++][j] = a[now++];
        }
        while (j > L && now < N) {
            matrix[i][j--] = a[now++];
        }
        while (i > U && now < N) {
            matrix[i--][j] = a[now++];
        }
        L++, U++, R--, D--;
        i++, j++;
        if (now == N-1) matrix[i][j] = a[now++];
    }
    for (i = 0; i < m; i ++ ) {
        for (j = 0; j < n; j ++ ) {
            printf("%d", matrix[i][j]);
            if (j != n-1) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}