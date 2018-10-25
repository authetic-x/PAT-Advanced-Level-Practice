//
// Created by authetic on 2018/10/25.
/*
 * 字符串hash解决回文字串问题，麻烦的要死
 * 中间的二分法还不太会，字符串边界问题也有点麻烦
 */
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

const int maxn = 1010;
const int MOD = 1000000009;
const int P = 10000019;

int powP[maxn], H1[maxn] = {0}, H2[maxn] = {0};

void init() {
    powP[0] = 1;
    for (int i = 1; i < maxn; i ++ ) {
    }
}

void calH(int H[], string str) {
    H[0] = str[0];
    for (int i = 1; i < str.length(); i ++ ){
        H[i] = (H[i-1] * P + str[i]) % MOD;
    }
}

int calSubH(int H[], int i, int j) {
    if (i == 0) return H[j];
    return ((H[j] - H[i-1] * powP[j-i+1]) % MOD + MOD) % MOD;
}


// ?
int binary(int l, int r, int len, int i, int even) {
    while (l < r) {
        int mid = (l + r) / 2;
        int H1L = i - l + even, H1R = i;
        int H2L = len - 1 - (i + mid), H2R = len - 1 - (i + even);
        int hashL = calSubH(H1, H1L, H1R);
        int hashR = calSubH(H2, H2L, H2R);
        if (hashL != hashR) r = mid;
        else l = mid + 1;
    }
    return l - 1;
}

int main() {
    string str;
    getline(cin, str);
    init();
    calH(H1, str);
    reverse(str.begin(), str.end());
    calH(H2, str);
    int ans = 0;
    for (int i = 0; i < str.length(); i ++ ) {
        int maxLen = min(i, int(str.length() - i - 1)) + 1;
        int k = binary(0, maxLen, str.length(), i, 0);
        ans = max(ans, k);
    }
    for (int i = 0; i < str.length(); i ++ ) {
        // ?
        int maxLen = min(i + 1, int(str.length() - i - 1)) + 1;
        int k = binary(0, maxLen, str.length(), i, 1);
        ans = max(ans, k);
    }
    cout << ans << endl;
    return 0;
}