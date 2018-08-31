//
// Created by authetic on 2018/8/27.
/*
 * 大数计算问题。
 * key: 心不在焉就没有做题的必要了，这种小错误
 * 总是出现！
 */
//

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

//char str[25];
int hashtable[128] = {0};

int main() {
    string s,str="";
    cin >> s;
    int len = (int)s.length();
    int carry = 0;
    for (int i=len-1; i>=0; i--) {
        hashtable[s[i]]++;
        int temp = s[i]-'0';
        int a = temp*2 + carry;
        char b = (char)(a%10) + '0';
        str += b;
        carry = a/10;
    }
    if (carry!=0) str += ((char)carry + '0');
    if (str.length()!=s.length()) {
        cout << "No" << endl;
        reverse(str.begin(), str.end());
        cout << str << endl;
    } else {
        for (int i=0; i<str.length()-1; i++) {
            if (hashtable[str[i]]<=0) {
                cout << "No" << endl;
                reverse(str.begin(), str.end());
                cout << str << endl;
                return 0;
            }
            hashtable[str[i]]--;
        }
        cout << "Yes" << endl;
        reverse(str.begin(), str.end());
        cout << str << endl;
    }
    return 0;
}