//
// Created by authetic on 2018/12/28.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 10010;

struct Man {
    string name;
    int h;
}man[maxn];

bool cmp(Man a, Man b) {
    if (a.h != b.h) {
        return a.h > b.h;
    }
    return a.name < b.name;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i ++ ) {
        cin >> man[i].name >> man[i].h;
    }
    sort(man, man + n, cmp);
    int cnt = 0;
    int m;
    for (int i = 0; i < k; i ++ ) {
        vector<string> s(n/k + k);
        if (i ==0 ) {
            m = n / k + n % k;
        } else {
            m = n / k;
        }
        int index = m / 2 + 1;
        // 最高的站中间
        s[index] = man[cnt++].name;
        bool left = true;
        for (int j = 1; j < m; j ++) {
            if (left) {
                index = index - j;
                s[index] = man[cnt++].name;
                left = false;
            } else {
                index = index + j;
                s[index] = man[cnt++].name;
                left = true;
            }
        }
        for (int j = 1; j <= m; j ++ ) {
            cout << s[j];
            if (j != m) cout << " ";
            else cout << endl;
        }
    }
    return 0;
}