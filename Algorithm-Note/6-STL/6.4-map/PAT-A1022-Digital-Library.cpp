//
// Created by authetic on 2018/8/31.
/*
 * 根据各种书籍信息查询书籍编号
 * map+set的运用，题目本身不难，声明多个map分开存储
 * 注意scanf+cin输入时，要处理换行符！
 */
//

#include <cstdio>
#include <iostream>
#include <set>
#include <map>
using namespace std;

map<string, set<int>> mTitle,mAuthor,mKey,mPub,mYear;

void query(map<string,set<int>> &mp, string &str) {
    if (mp.find(str)==mp.end()) printf("Not Found\n");
    else {
        for (set<int>::iterator it=mp[str].begin(); it!=mp[str].end(); it++) {
            printf("%07d\n", *it);
        }
    }
}

int main() {
    int n,m,id;
    string title,author,key,pub,year;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &id);
        char c = getchar();
        getline(cin, title);
        mTitle[title].insert(id);
        getline(cin, author);
        mAuthor[author].insert(id);
        while (cin >> key) {
            mKey[key].insert(id);
            c = getchar();
            if (c=='\n') break;
        }
        getline(cin ,pub);
        mPub[pub].insert(id);
        getline(cin, year);
        mYear[year].insert(id);
    }
    scanf("%d", &m);
    string temp;
    int type;
    for (int i=0; i<m; i++) {
        scanf("%d: ", &type);
        getline(cin, temp);
        cout << type << ": " << temp << endl;
        if (type==1) query(mTitle, temp);
        else if(type==2) query(mAuthor, temp);
        else if (type==3) query(mKey, temp);
        else if(type==4) query(mPub, temp);
        else query(mYear, temp);
    }
    return 0;
}