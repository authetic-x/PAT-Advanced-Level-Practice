//
// Created by authetic on 2018/8/18.
//

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
int coupon[MAXN],product[MAXN];

int main() {
    int nc,np;
    scanf("%d", &nc);
    for (int i=0; i<nc; i++) {
        scanf("%d", &coupon[i]);
    }
    scanf("%d", &np);
    for (int i=0; i<np; i++) {
        scanf("%d", &product[i]);
    }
    sort(coupon, coupon+nc);
    sort(product, product+np);
    int ans=0;
    for (int i=0; i<nc&&i<np&&coupon[i]<=0&&product[i]<=0; i++) {
        ans += coupon[i] * product[i];
    }
    for (int i=nc-1,j=np-1; i>=0&&j>=0&&coupon[i]>0&&product[j]>0; i--,j--) {
        ans += coupon[i] * product[j];
    }
    printf("%d\n", ans);
    return 0;
}
