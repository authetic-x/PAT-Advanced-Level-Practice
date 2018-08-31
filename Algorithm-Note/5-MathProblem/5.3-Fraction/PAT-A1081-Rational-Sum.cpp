//
// Created by authetic on 2018/8/26.
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
        long long d = gcd(a.up, a.down);
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
void showResult(Fration a) {
    a = reduction(a);
    if (a.down==1) printf("%lld\n", a.up);
    else if (abs(a.up)>a.down) {
        printf("%lld %lld/%lld\n", a.up/a.down,abs(a.up)%a.down,a.down);
    } else {
        printf("%lld/%lld\n", a.up, a.down);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    if (n>0) {
        scanf("%lld/%lld", &f1.up, &f1.down);
    }
    for (int i=1; i<n; i++) {
        scanf("%lld/%lld", &f2.up, &f2.down);
        f1 = add(f1,f2);
    }
    showResult(f1);
    return 0;
}