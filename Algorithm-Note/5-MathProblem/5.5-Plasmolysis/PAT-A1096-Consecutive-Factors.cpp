//
// Created by authetic on 2018/8/27.
//

#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);
    int k= (int)sqrt(n), ansl=0, anslen=0;
    for (int i=2; i<=k; i++) {
        ll temp=1;
        int j=i;
        while (1) {
            temp *= j;
            if (n%temp!=0) break;
            if (j-i+1 > anslen) {
                anslen = j-i+1;
                ansl = i;
            }
            j++;
        }
    }
    if (anslen==0) {
        printf("1\n%d\n", n);
        return 0;
    }
    printf("%d\n", anslen);
    for (int i=ansl; i<ansl+anslen-1; i++) {
        printf("%d*", i);
    }
    printf("%d\n", ansl+anslen-1);
    return 0;
}