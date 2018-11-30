//
// Created by authetic on 2018/11/30.
//

#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;

    int len = str.length();
    int n1 = (len + 2) / 3;
    int n2 = len - 2 * n1;

    for (int i = 0, j = len-1; i < n1 - 1; i ++, j --) {
        cout << str[i];
        for (int k = 0; k < n2; k ++ ) {
            cout << " ";
        }
        cout << str[j] << endl;
    }
    for (int i = n1 - 1; i <= n1 + n2; i ++ ) {
        cout << str[i];
    }
    return 0;
}