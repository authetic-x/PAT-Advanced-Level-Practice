//
// Created by authetic on 2018/8/23.
/*
 * 求给出数字从1-n数字1出现的个数。
 * 很麻烦的一道题，需要分类讨论，中间容易出错
 * 不过分类之后过程很简单
 */
//

#include <cstdio>

int main() {
    int n,a=1,ans=0;
    scanf("%d", &n);
    while (n/a!=0) {
        int left = n / (a*10);
        int now = n/a % 10;
        int right = n % a;
        if (now==0) ans += left*a;
        else if (now==1) ans += left*a + right+1;
        else ans += (left+1)*a;
        a = a*10;
    }
    printf("%d\n", ans);
    return 0;
}