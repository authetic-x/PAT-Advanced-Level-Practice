//
// Created by authetic on 2018/8/22.
//

#include <iostream>
#include <string>
using namespace std;

int mod = 1000000007;

int main() {
    string str;
    cin >> str;
    int len = str.length();
    int leftNumP[len] = {0};
    for (int i=0; i<len; i++) {
        if (i>0) {
            leftNumP[i] = leftNumP[i-1];
        }
        if (str[i]=='P') {
            leftNumP[i]++;
        }
    }
    int ans=0,rightNumT=0;
    for (int i=len-1; i>=0; i--) {
        if (str[i]=='T') {
            rightNumT++;
        } else if (str[i]=='A') {
            ans = (ans+leftNumP[i]*rightNumT)%mod;
        }
    }
    printf("%d\n", ans);
    return 0;
}