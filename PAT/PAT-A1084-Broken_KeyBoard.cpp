//
// Created by authetic on 2018/12/25.
//

#include <iostream>
#include <string>
#include <set>
using namespace std;

set<char> st;

int main() {
    string s, str;
    cin >> s >> str;
    int i = 0, j = 0;
    while (i < s.length() && j < str.length()) {
        if (s[i] != str[j]) {
            char ch;
            if (s[i] >= 'a' && s[i] <= 'z') {
                ch = s[i] - 'a' + 'A';
            } else {
                ch = s[i];
            }
            if (st.find(ch) == st.end()) {
                st.insert(ch);
                cout << ch;
            }
            i++;
        } else {
            i++;
            j++;
        }
    }
    while (i < s.length()) {
        char ch;
        if (s[i] >= 'a' && s[i] <= 'z') {
            ch = s[i] - 'a' + 'A';
        } else {
            ch = s[i];
        }
        if (st.find(ch) == st.end()) {
            st.insert(ch);
            cout << ch;
        }
        i++;
    }
    return 0;
}