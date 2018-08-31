//
// Created by authetic on 2018/8/23.
/*
 * 数字黑洞
 */
//

#include <cstdio>
#include <algorithm>
using namespace std;

int num[4];

bool cmp(int a, int b) {
    return a>b;
}
void num2array(int n, int num[]) {
    for (int i=0; i<4; i++) {
        num[i] = n%10;
        n = n/10;
    }
}
int array2num(int num[]) {
    int n=0;
    for (int i=0; i<4; i++) {
        n =  n*10 + num[i];
    }
    return n;
}

int main() {
    int n;
    scanf("%d", &n);
    num2array(n, num);
    sort(num, num+4);
    int a = array2num(num);
    sort(num, num+4, cmp);
    int b = array2num(num);
    while (b-a!=6174 && b-a!=0) {
        printf("%04d - %04d = %04d\n", b, a, b-a);
        num2array(b-a, num);
        sort(num, num+4);
        a = array2num(num);
        sort(num, num+4, cmp);
        b = array2num(num);
    }
    printf("%04d - %04d = %04d\n", b, a, b-a);
    return 0;
}