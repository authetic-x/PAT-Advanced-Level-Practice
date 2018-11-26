//
// Created by authetic on 2018/11/26.
//

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int R, G, B;

string translate(int n) {
    string s;
    if (n == 0) {
        s = "00";
        return s;
    }
    while (n != 0) {
        if (n % 13 >= 10) {
            s += 'A' + (n % 13 - 10);
        } else {
            s += '0' + (n % 13);
        }
        n /= 13;
    }
    reverse(s.begin(), s.end());
    if (s.size() == 1) {
        s = '0' + s;
    }
    return s;
}

int main() {
    cin >> R >> G >> B;

    cout << "#" << translate(R) << translate(G) << translate(B);
    return 0;
}