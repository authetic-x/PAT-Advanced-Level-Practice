//
// Created by authetic on 2018/8/18.
/*
 * 将一串连续的数字，利用与0交换来进行排序，求最小交换次数
 * key: 利用数组来存储每个数字的位置，将0的位置与当前位置的
 * 数字进行交换，0回到原位在特殊处理即可！
 */
//
#include <cstdio>

const int MAXN = 100010;
int pos[MAXN];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    scanf("%d", &n);
    int left = n-1;
    for (int i=0; i<n; i++) {
        int num;
        scanf("%d", &num);
        pos[num] = i;
        if (num==i && i!=0) {
            left--;
        }
    }
    int k=1,ans=0;
    while (left>0) {
        if (pos[0]==0) {            //当0回到原位，找一位没有回到原位的数交换
            while (k<n) {
                if (pos[k]!=k) {
                    swap(&pos[0], &pos[k]);
                    ans++;
                    break;
                }
                k++;
            }
        }
        while (pos[0]!=0) {
            swap(&pos[0], &pos[pos[0]]);
            ans++;
            left--;
        }
    }
    printf("%d\n", ans);
    return 0;
}
