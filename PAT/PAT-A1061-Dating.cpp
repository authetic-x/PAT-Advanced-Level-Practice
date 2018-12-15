//
// Created by authetic on 2018/12/12.
//

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    int min1 = min(s1.length(), s2.length());
    int min2 = min(s3.length(), s4.length());
    char t[2];
    int pos, j;
    for (int i=0; i < min1; i++) {
        if (s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G') {
            j = i+1;
            t[0] = s1[i];
            break;
        }
    }
    for (int i = j; i < min1; i ++ ) {
        if (s1[i] == s2[i] && ((s1[i] >= 'A' && s1[i] <= 'N') || isdigit(s1[i]))) {
            t[1] = s1[i];
            break;
        }
    }
    for (int i = 0; i < min2; i ++ ) {
        if (s3[i] == s4[i] && isalpha(s3[i])) {
            pos = i;
            break;
        }
    }
    int m = t[1] - '0';
    if (!isdigit(t[1])) m = t[1] - 'A' + 10;
    cout << week[t[0] - 'A'];
    printf(" %02d:%02d\n", m, pos);
    return 0;
}