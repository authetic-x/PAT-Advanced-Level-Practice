//
// Created by authetic on 2018/11/23.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

double bet[3][3];
char str[3] = {'W', 'T', 'L'};

int main() {
    int g[3] = {0}; // 存储每个游戏的最大利率下标
    for (int i = 0; i < 3; i ++ ) {
        for (int j = 0; j < 3; j ++ ) {
            scanf("%lf", &bet[i][j]);
            if (bet[i][j] > bet[i][g[i]]) {
                g[i] = j;
            }
        }
    }
    double ans = 1;
    for (int i = 0; i < 3; i ++ ) {
        printf("%c ", str[g[i]]);
        ans *= bet[i][g[i]];
    }
    printf("%.2f\n", (ans * 0.65 - 1) * 2);
    return 0;
}