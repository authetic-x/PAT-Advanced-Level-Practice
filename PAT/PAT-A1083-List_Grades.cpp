//
// Created by authetic on 2018/12/25.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 100;

struct Student {
    string name, id;
    int grade;
};

bool cmp(Student a, Student b) {
    return a.grade > b.grade;
}

int main() {
    int n, g1, g2;
    cin >> n;
    Student s[n];
    int num = 0;
    for (int i = 0; i < n; i ++ ) {
        cin >> s[i].name >> s[i].id >> s[i].grade;
    }
    cin >> g1 >> g2;
    for (int i = 0; i < n; i ++ ) {
        if (s[i].grade < g1 || s[i].grade > g2) {
            s[i].grade = -1;
        } else {
            num ++;
        }
    }
    if (num == 0) {
        cout << "NONE";
        return 0;
    }
    sort(s, s + n, cmp);
    for (int i = 0; i < num; i ++ ) {
        cout << s[i].name << " " << s[i].id << endl;
    }
    return 0;
}