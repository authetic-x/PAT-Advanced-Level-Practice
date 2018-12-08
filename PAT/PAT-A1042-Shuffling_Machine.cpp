//
// Created by authetic on 2018/11/30.
/*
 * 题目都没看懂就开始做，我也是够菜！
 */
//

#include <cstdio>
using namespace std;

int start[55], end[55], scan[55];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < 55; i ++ ) {
        scanf("%d", &scan[i]);
        end[i] = i;
    }

    for (int i = 0; i < n; i ++ ) {
        for (int j = 1; j < 55; j ++ ) {
            start[j] = end[j];
        }
        for (int k = 1; k < 55; k ++ ) {
            end[scan[k]] = start[k];
        }
    }
    char c[6] = {"SHCDJ"};
    for (int i = 1; i < 55; i ++ ) {
        end[i] = end[i] - 1;
        printf("%c%d", c[end[i] / 13], end[i] % 13 + 1);
        if (i != 54) printf(" ");
    }
    return 0;
}