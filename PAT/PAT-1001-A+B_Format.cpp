//
// Created by authetic on 2018/11/4.
//

#include <iostream>
#include <cstring>

using namespace std;

void myanswer(int num) {
    if (num < 0) {
        printf("-");
        num = -num;
    }
    char s[20];
    int count = 0, k = 0;
    while (num != 0) {
        s[k++] = num % 10 + '0';
        num /= 10;
        count ++;
        if (count != 0 && count % 3 == 0) {
            if (num != 0) s[k++] = ',';
        }
    }
    for (int i = strlen(s)-1; i >= 0; i --) {
        printf("%c", s[i]);
    }
}

void goodans(int num) {
    if (num < 0) {
        printf("-");
        num = -num;
    }
    int ans[10], k = 0;
    while (num / 1000) {
        ans[k++] = num % 1000;
        num /= 1000;
    }
    printf("%d", num);
    for (int i = k-1; i >= 0; i -- ) {
        printf(",%d", ans[i]);
    }
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    myanswer(a+b);
}