//
// Created by authetic on 2018/10/25.
/*
 * Give N strings, output the number of different strings.
 * ANS: Put every string into a hash num and sort, answer is
 * the number of different nums.
 */
//

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;   //1e9+7
const int p = 10000019;  //le7+19

vector<int> ans;

long long strFunc(string s) {
    long long H = 0;
    for (int i = 0; i < s.length(); i ++ ) {
        H = (H * p + s[i] - 'a') % MOD;
    }
    return H;
}

int main() {
    string str;
    while (getline(cin, str), str != "#") {
        long long id = strFunc(str);
        ans.push_back(id);
    }
    sort(ans.begin(), ans.end());
    int count = 0;
    for (int i = 0; i < ans.size(); i ++ ) {
        if (i == 0 || ans[i] != ans[i-1]) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}