//
// Created by authetic on 2018/8/28.
/*
 * 科学计数法，给定最大位数，判断转化后的两数是否相同
 * key: 科学计数法的转化过程确实麻烦，先去0，再根据小于1
 * 大于1分开处理，注意指数的计算，小于1的数的指数可能是负的！
 */
//

#include <iostream>
#include <string>
using namespace std;

int n;

string standForm(string s, int &e) {
    int k=0;
    while (s.length()>0 && s[0]=='0') {
        s.erase(s.begin());
    }
    if (s[0]=='.') {
        s.erase(s.begin());
        while (s[0]=='0'&&s.length()>0) {
            s.erase(s.begin());
            e--;
        }
    } else {
        while (k<s.length()&&s[k]!='.') {
            k++;
            e++;
        }
        if (k<s.length()) {
            s.erase(s.begin()+k);
        }
    }
    if (s.length()==0) {
        e=0;
    }
    int num=0;
    k=0;
    string res;
    while (num<n) {
        if (k<s.length()) res += s[k++];
        else res += '0';
        num++;
    }
    return res;
}

int main() {
    cin >> n;
    string a,b;
    cin >> a >> b;

    int e1=0,e2=0;
    string s1 = standForm(a, e1);
    string s2 = standForm(b, e2);
    if (s1==s2 && e1==e2) {
        cout << "YES 0." << s1 << "*10^" << e1 <<endl;
    } else {
        cout << "NO 0." << s1 << "*10^" << e1 << " 0." << s2 << "*10^" << e2 << endl;
    }
    return 0;
}