//
// Created by authetic on 2018/8/30.
/*
 * 火星数字和地球数字转换
 * key: 数据量小，直接列举。如果根据字符串输入来判断，代价太大。
 * 注意进制间的转换，13进制和十进制。另外getline()与cin >> 输入同时用
 * 会报错，需用scanf("%d%*c", &n)输入！
 */
//

#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

string unitDigit[13] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string tenDigit[13] = {"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};

string numtoStr[175];
map<string, int> strtoNum;

void init() {
    for (int i=0; i<13; i++) {
        numtoStr[i] = unitDigit[i];
        strtoNum[unitDigit[i]] = i;
        numtoStr[i*13] = tenDigit[i];
        strtoNum[tenDigit[i]] = i*13;
    }
    for (int i=1; i<13; i++) {
        for (int j=1; j<13; j++) {
            string s = tenDigit[i] + " " + unitDigit[j];
            numtoStr[i*13+j] = s;
            strtoNum[s] = i*13+j;
        }
    }
}

int main() {
    init();
    int n;
    scanf("%d%*c", &n);
    while (n--) {
        string str;
        getline(cin, str);
        if (str[0]>='0' && str[0]<='9') {
            int num=0;
            for (int i=0; i<str.length(); i++) {
                num = num*10 + (str[i]-'0');
            }
            cout << numtoStr[num] << endl;
        } else {
            cout << strtoNum[str] << endl;
        }
    }
    return 0;
}