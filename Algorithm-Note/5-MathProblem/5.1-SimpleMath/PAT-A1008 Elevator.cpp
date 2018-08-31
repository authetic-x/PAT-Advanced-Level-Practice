//
// Created by authetic on 2018/8/23.
//

#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    int pos=0,ans=0;
    for (int i=0; i<n; i++) {
        int tar;
        scanf("%d", &tar);
        if (tar-pos>0) {
            ans += (tar-pos)*6;
            ans += 5;
            pos = tar;
        } else if (tar-pos<0) {
            ans += (pos-tar)*4;
            ans += 5;
            pos = tar;
        } else {
            ans += 5;
        }
    }
    printf("%d\n", ans);
    return 0;
}