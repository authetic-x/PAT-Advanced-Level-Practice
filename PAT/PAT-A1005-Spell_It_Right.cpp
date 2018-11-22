//
// Created by authetic on 2018/11/22.
/*
 * 输入一个整数，各位相加然后用英文输出
 */
//

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

const int maxn = 110;

string str;
int sum;
string number[10] = {"zero", "one", "two", "three", "four",
                     "five", "six", "seven", "eight", "nine"};

int main() {
    cin >> str;

    sum = 0;
    for (int i = 0; i < str.length(); i ++ ) {
        sum += str[i] - '0';
    }

    stringstream ss;
    ss << sum;
    ss >> str;

    for (int i = 0; i < str.length(); i ++ ) {
        cout << number[str[i] - '0'];
        if (i != str.length()-1) cout << ' ';
    }
    return 0;
}