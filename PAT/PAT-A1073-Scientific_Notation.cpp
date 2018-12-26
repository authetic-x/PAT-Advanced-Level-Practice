//
// Created by authetic on 2018/12/23.
/*
 * 自己写的有两个运行超时，柳婼同学的感觉有个地方也有问题，不过测试全过！
 */
//

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    cin >> s;
    int pose;
    if (s[0] == '-') cout << s[0];
    for (int i = 1; i < s.length(); i ++ ) {
        if (s[i] == 'E') {
            pose = i;
            break;
        }
    }
    int after = 0;
    for (int i = pose + 2; i < s.length(); i ++ ) {
        after = (s[i] - '0') + 10 * after;
    }
    if (s[pose + 1] == '-') {
        if (after > 0) {
            cout << "0.";
            for (int i = 1; i < after; i ++ ) {
                cout << "0";
            }
            for (int i = 1; i < pose; i ++ ) {
                if (isdigit(s[i])) cout << s[i];
            }
        } else {
            for (int i = 1; i < pose; i ++ ) {
                if (i == 2) cout << ".";
                if (isdigit(s[i])) cout << s[i];
            }
        }
    } else {
        if (after > pose - 3) {
            if (s[1] != '0') cout << s[1];
            for (int i = 3; i < pose; i ++ ) {
                if (isdigit(s[i])) cout << s[i];
            }
            for (int i = 0; i < after - (pose-3); i ++ ) {
                cout << "0";
            }
        } else {
            if (s[1] != '0') cout << s[1];
            for (int i = 3; i < pose; i ++ ) {
                if (i == after + 3) cout << ".";
                if (isdigit(s[i])) cout << s[i];
            }
        }
    }
    return 0;
}