//
// Created by authetic on 2019/4/6.
//

#include <stdio.h>
#include <math.h>

const int MAXN = 10000;

int n, res, x;

int main() {
    int a[MAXN];
    for (int i = n-1; n > 0; i -- ) {
        res = a[i-1] + x*a[i];
    }

    // ------Or--------
    for (int i = 0; i < n-1; i ++ ) {
        res += pow(x, i) * a[i];
    }
}