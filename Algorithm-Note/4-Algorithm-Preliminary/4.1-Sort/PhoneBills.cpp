//
// Created by authetic on 2018/8/15.
/*
 * 这道题整整搞了两个小时，虽然看起来不难，但自己写起来真的很容易出错
 * 不过类似排序的题目基本是这个做法！而且这道题目前来看，是所有基础排序
 * 题里最难的一道了！
 */
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1010;
int toll[25];

struct Record {
    char name[25];
    int mon,dd,hh,mm;
    bool status;
}rec[maxn],temp;

bool cmp(Record a, Record b) {
    int s = strcmp(a.name, b.name);
    if (s!=0) return s<0;
    else if(a.mon!=b.mon) return a.mon<b.mon;
    else if(a.dd!=b.dd) return a.dd<b.dd;
    else if(a.hh!=b.hh) return a.hh<b.hh;
    else return a.mm<b.mm;
}
void cac_mon(int on, int off, int &time, int &money) {
    temp = rec[on];
    while (temp.dd<rec[off].dd || temp.hh<rec[off].hh || temp.mm<rec[off].mm) {
        time++;
        money += toll[temp.hh];
        temp.mm++;
        if (temp.mm>=60) {
            temp.mm=0;
            temp.hh++;
            if (temp.hh>=24) {
                temp.hh=0;
                temp.dd++;
            }
        }
    }
}
int main() {
    for (int i=0; i<24; i++) {
        scanf("%d", &toll[i]);
    }
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%s %d:%d:%d:%d", rec[i].name,&rec[i].mon,&rec[i].dd,&rec[i].hh,&rec[i].mm);
        char s[10];
        scanf("%s", s);
        if (strcmp(s, "on-line")==0) {
            rec[i].status = true;
        } else {
            rec[i].status =false;
        }
    }
    sort(rec, rec+n, cmp);
    int on=0,off,next;
    while (on<n) {
        int needPrint=0;
        next = on;
        while (next<n &&(strcmp(rec[on].name, rec[next].name))==0) {
            if (needPrint==0&&rec[next].status) {
                needPrint = 1;
            } else if(!rec[next].status&&needPrint==1) {
                needPrint = 2;
            }
            next++;
        }
        if (needPrint!=2) {
            on = next;
            continue;
        }
        printf("%s %02d\n", rec[on].name, rec[on].mon);
        int Allmoney = 0;
        while(on<next) {
            while (on<next-1&&!(rec[on].status&&!rec[on+1].status)) {
                on++;
            }
            off = on+1;
            if(off==next) {
                on = next;
                break;
            }
            int time=0,money=0;
            cac_mon(on,off,time,money);
            Allmoney += money;
            printf("%02d:%02d:%02d ", rec[on].dd, rec[on].hh, rec[on].mm);
            printf("%02d:%02d:%02d ", rec[off].dd, rec[off].hh, rec[off].mm);
            printf("%d $%.2f\n", time, money/100.0);
            on = off+1;
        }
        printf("Total amount: $%.2f\n", Allmoney/100.0);
    }
    return 0;
}
