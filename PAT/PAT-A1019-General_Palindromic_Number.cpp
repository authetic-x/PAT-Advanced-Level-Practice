//
// Created by authetic on 2018/11/23.
/*
 * 进制转换回文串判断，没有全对
 */
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, b;
    string s;
    cin >> n >> b;

    if (n == 0) {
        cout << "Yes" << endl;
        cout << "0" << endl;
        return 0;
    }

    while (n != 0) {
        s += (n % b + '0');
        n /= b;
    }
    string str = s;
    reverse(str.begin(), str.end());
    if (s == str) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    for (int i = 0; i < str.length(); i ++ ) {
        cout << str[i];
        if (i != str.length() - 1) cout << " ";
    }
    return 0;
}