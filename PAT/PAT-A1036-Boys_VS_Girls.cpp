//
// Created by authetic on 2018/11/30.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string female, male;
    int femaleScore = -1, maleScore = 101, score;
    for (int i = 0; i < n; i ++ ) {
        string name, sex, num;
        cin >> name >> sex >> num;
        scanf("%d", &score);
        if (sex == "M") {
            if (score < maleScore) {
                male = name + " " + num;
                maleScore = score;
            }
        } else if (score > femaleScore) {
            female = name + " " + num;
            femaleScore = score;
        }
    }
    if (femaleScore == -1) {
        cout << "Absent" << endl;
    } else {
        cout << female << endl;
    }
    if (maleScore == 101) {
        cout << "Absent" << endl;
    } else {
        cout << male << endl;
    }
    if (femaleScore == -1 || maleScore == 101) {
        cout << "NA" << endl;
    } else {
        cout << femaleScore - maleScore << endl;
    }
    return 0;
}