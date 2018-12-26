//
// Created by authetic on 2018/12/26.
/*
 * 题目花里胡哨，一开始没看懂，
 * getline函数前面的scanf需要加上\n换行，不然会吞一个换行符
 */
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d\n", &n);
    string ans;
    for (int i = 0; i < n; i ++ ) {
        string s;
        getline(cin, s);
        int len = s.length();
        reverse(s.begin(), s.end());
        if (i == 0) {
            ans = s;
        } else {
            int anslen = ans.length();
            int minlen = min(anslen, len);
            for (int j = 0; j < minlen; j ++ ) {
                if (ans[j] != s[j]) {
                    ans = ans.substr(0, j);
                    break;
                }
            }
        }
    }
    reverse(ans.begin(), ans.end());
    if (ans.length() == 0) cout << "nai";
    else cout << ans;
    return 0;
}