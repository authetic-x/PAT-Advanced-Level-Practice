//
// Created by authetic on 2018/10/25.
/*
 * 给出两个字符串，求公共字串最大长度
 * 给每个字符串的子串转换hash，最后比较得出最大值，
 * 时间复杂度O(n*n+m*m), 只能承受长度不超过1000的字符串
 */
//

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1010; // Longest length
const long long MOD = 1000000009;
const long long P = 10000019;

long long powP[maxn], H1[maxn] = {0}, H2[maxn] = {0};
vector<pair<int, int>> pair1, pair2;

void init(int len) {
    powP[0] = 1;
    for (int i = 1; i <= len; i ++ ) {
        powP[i] = (powP[i-1] * P) % MOD;
    }
}

void calH(long long H[], string &str) {
    H[0] = str[0];
    for (int i = 1; i < str.length(); i ++ ) {
        H[i] = (H[i-1] * P + str[i]) %MOD;
    }
}

long long calSubstringH(long long H[], int i, int j) {
    if (i == 0) return H[j];
    return ((H[j] - H[i-1] * powP[j-i+1]) % MOD + MOD) % MOD;
}

void calSubH(long long H[], int len, vector<pair<int, int>>& pair) {
    for (int i = 0; i < len; i ++ ) {
        for (int j = 0; j < len; j ++ ) {
            int hashValue = calSubstringH(H, i ,j);
            pair.push_back(make_pair(hashValue, j-i+1));
        }
    }
}

int getMax() {
    int ans = 0;
    for (int i = 0; i < pair1.size(); i ++ ) {
        for (int j = 0; j < pair2.size(); j ++ ) {
            if (pair1[i].first == pair2[i].first) {
                ans = max(ans, pair1[i].second);
            }
        }
    }
    return ans;
}

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    init(max(str1.length(), str2.length()));
    calH(H1, str1);
    calH(H2, str2);
    calSubH(H1, str1.length(), pair1);
    calSubH(H2, str2.length(), pair2);
    cout << getMax() << endl;
    return 0;
}