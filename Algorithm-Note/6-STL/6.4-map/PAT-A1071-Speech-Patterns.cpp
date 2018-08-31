//
// Created by authetic on 2018/8/31.
/*
 * 统计单词的个数
 * map基本运用，注意换单词的大小写
 */
//

#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string, int> count;

bool judge(char c) {          //判断字符是否合法
    if ((c>='0'&&c<='9') || (c>='a'&&c<='z') || (c>='A'&&c<='Z')) {
        return true;
    }
    return false;
}

int main() {
    string str;
    getline(cin, str);
    int index=0, len=str.length();
    while(index<len) {
        string word;
        while (index<len && judge(str[index])) {
            if (str[index]>='A'&&str[index]<='Z') {
                str[index] += 32;
            }
            word += str[index];
            index++;
        }
        if (word!="") {
            if (count.find(word)!=count.end()) count[word]++;
            else count[word]=1;
        }
        while (index<len && !judge(str[index])) {
            index++;
        }
    }
    string ans;
    int max=0;
    for (map<string, int>::iterator it=count.begin(); it!=count.end(); it++) {
        if (it->second > max) {
            max = it->second;
            ans = it->first;
        } else if(it->second == max) {
            ans = (ans < it->first) ? ans : it->first;
        }
    }
    cout << ans << " " << max << endl;
    return 0;
}