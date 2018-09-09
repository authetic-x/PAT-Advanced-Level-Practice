//
// Created by authetic on 2018/9/5.
/*
 * 实现一个简单的计算器
 * 栈和队列的运用，有点麻烦，主要是中缀表达式转后缀表达式的思想，
 * 保持高优先级运算符在前，将后缀表达式存在队列中，然后从队首顺序
 * 判断，数入栈，运算符先计算，再将结果入栈，最后栈中的值即为结果！
 */
//

#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <stack>
using namespace std;

struct node {
    double num;
    char op;
    bool flag;
};

stack<node> s;
queue<node> q;
map<char, int> op;
string str;

void change() {
    double num;
    node temp;
    for (int i=0; i<str.length();) {
        if (str[i]>='0' && str[i]<='9') {
            temp.flag = true;
            temp.num = str[i++] - '0';
            while (i<str.length()&&str[i]>='0'&&str[i]<='9') {
                temp.num = temp.num*10 + (str[i]-'0');
                i++;
            }
            q.push(temp);
        } else {
            temp.flag = false;
            temp.op = str[i];
            //要保证乘除号的优先级就要<=, 否则会扎堆
            if (!s.empty()&&op[str[i]]<=op[s.top().op]) {
                q.push(s.top());
                s.pop();
            }
            s.push(temp);
        }
        i++;
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

double cal() {
    double temp1,temp2;
    node cur,temp;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur.flag) s.push(cur);
        else {
            temp2 = s.top().num;
            s.pop();
            temp1 = s.top().num;
            s.pop();
            temp.flag = true;
            if (cur.op=='+') temp.num = temp1+temp2;
            else if (cur.op=='-') temp.num = temp1-temp2;
            else if (cur.op=='*') temp.num = temp1*temp2;
            else temp.num = temp1/temp2;
            s.push(temp);
        }
    }
    return s.top().num;
}

int main(){
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    while (getline(cin, str), str!="0") {
        for (string::iterator it=str.end(); it!=str.begin(); it--) {
            if (*it == ' ') str.erase(it);
        }
        while (!s.empty()) s.pop();
        change();
        printf("%.2f\n", cal());
    }
    return 0;
}