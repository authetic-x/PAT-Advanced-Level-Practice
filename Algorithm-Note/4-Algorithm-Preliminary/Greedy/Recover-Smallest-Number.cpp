//
// Created by authetic on 2018/8/18.
/*
 * 给出一序列字符串组合出最小数
 * key: 字符串问题优先考虑使用string，
 * 其次注意a+b < b+a 则选a在前这个规律即可！
 */
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10010;
string str[maxn];

bool cmp(string a, string b) {
    return a+b < b+a;
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> str[i];
    }
    sort(str, str+n, cmp);
    string ans;
    for (int i=0; i<n; i++) {
        ans += str[i];
    }
    while (ans.size()!=0 && ans[0]=='0') {
        ans.erase(ans.begin());
    }
    if (ans.size()==0) cout << 0 << endl;
    else cout << ans <<endl;
    return 0;
}

