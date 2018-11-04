//
// Created by authetic on 2018/11/4.
/*
 * 多项式相加，按格式输出非零项
 * Note: 一开始没全对，非零项这一条件没看懂！
 */
//

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

map<int, double, greater<int>> mp;
int k1, k2;

int main() {
    int ex, k = 0;   // k为多项式中0的个数
    double coe;
    scanf("%d", &k1);
    for (int i = 0; i < k1; i ++ ){
        scanf("%d %lf", &ex, &coe);
        mp[ex] = coe;
    }
    scanf("%d", &k2);
    for (int i = 0; i < k2; i ++ ) {
        scanf("%d %lf", &ex, &coe);
        if (mp.find(ex) != mp.end()) {
            mp[ex] = mp[ex] + coe;
            if (mp[ex] == 0) k++;
        } else {
            mp[ex] = coe;
            if (mp[ex] == 0) k++;
        }
    }
    printf("%d", mp.size()-k);
    for (map<int, double>::iterator it = mp.begin(); it != mp.end(); it++) {
        if (it->second !=0) {
            printf(" %d %.1f", it->first, it->second);
        }
    }
    return 0;
}