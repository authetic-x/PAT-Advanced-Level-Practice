//
// Created by authetic on 2018/8/26.
/*
 * 算术运算
 * key: 一道很麻烦的简单题，再处理正负数时出现了一个错误
 * 很难找，求最大公倍数的函数没有取绝对值，导致得出来的可能是
 * 负数！
 */
//

#include <cstdio>
#include <cstdlib>
using namespace std;

struct Fration {
    long long up;
    long long down;
}f1,f2;

long long gcd(long long a, long long b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}

Fration reduction(Fration a) {
    if (a.down<0) {
        a.up = -a.up;
        a.down = -a.down;
    }
    if (a.up==0) {
        a.down = 1;
    } else {
        long long d = gcd(abs(a.up), abs(a.down));
        a.up /= d;
        a.down /= d;
    }
    return a;
}
Fration add(Fration a, Fration b) {
    Fration result;
    result.up = a.up*b.down + b.up*a.down;
    result.down = a.down*b.down;
    return reduction(result);
}
Fration difference(Fration a, Fration b) {
    Fration result;
    result.up = a.up*b.down - b.up*a.down;
    result.down = a.down*b.down;
    return reduction(result);
}
Fration product(Fration a, Fration b) {
    Fration result;
    result.up = a.up*b.up;
    result.down = a.down*b.down;
    return reduction(result);
}
void showResult(Fration a) {
    a = reduction(a);
    if (a.up<0) printf("(");
    if (a.down==1) printf("%lld", a.up);
    else {
        if (abs(a.up)>a.down) {
            printf("%lld %lld/%lld", a.up/a.down,abs(a.up)%a.down,a.down);
        } else {
            printf("%lld/%lld", a.up, a.down);
        }
    }
    if (a.up<0) printf(")");
}
Fration quotient(Fration a, Fration b) {
    Fration result;
    result.up = a.up*b.down;
    result.down = a.down*b.up;
    return reduction(result);
}

int main() {
    scanf("%lld/%lld", &f1.up, &f1.down);
    scanf("%lld/%lld", &f2.up, &f2.down);

    showResult(f1);
    printf(" + ");
    showResult(f2);
    printf(" = ");
    showResult(add(f1,f2));
    printf("\n");

    showResult(f1);
    printf(" - ");
    showResult(f2);
    printf(" = ");
    showResult(difference(f1,f2));
    printf("\n");

    showResult(f1);
    printf(" * ");
    showResult(f2);
    printf(" = ");
    showResult(product(f1,f2));
    printf("\n");

    showResult(f1);
    printf(" / ");
    showResult(f2);
    printf(" = ");
    if (f2.up==0) printf("Inf\n");
    else {
        showResult(quotient(f1,f2));
        printf("\n");
    }
    return 0;
}