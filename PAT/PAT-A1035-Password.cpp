//
// Created by authetic on 2018/11/30.
//

#include <iostream>
#include <string>

using namespace std;

const int maxn = 1010;

struct Team {
    string username, password;
    bool isModify = false;
}team[maxn];

bool modify(string &s) {
    string str = s;
    for (int i = 0; i < s.length(); i ++ ) {
        if (s[i] == '1') s[i] = '@';
        else if (s[i] == '0') s[i] = '%';
        else if (s[i] == 'l') s[i] = 'L';
        else if (s[i] == 'O') s[i] = 'o';
    }
    if (str != s) return true;
    return false;
}

int main() {
    int n, m_count = 0;
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        cin >> team[i].username >> team[i].password;
        if (modify(team[i].password)) {
            m_count++;
            team[i].isModify = true;
        }
    }
    if (m_count) {
        cout << m_count << endl;
        for (int i = 0; i < n; i ++ ) {
            if (team[i].isModify) {
                cout << team[i].username << " " << team[i].password << endl;
            }
        }
    } else {
        if (n == 1) {
            cout << "There is 1 account and no account is modified" << endl;
        } else {
            printf("There are %d accounts and no account is modified", n);
        }
    }
    return 0;
}