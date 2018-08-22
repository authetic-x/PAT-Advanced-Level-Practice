//
// Created by authetic on 2018/8/20.
/*
 * 给出一个确定的进制数，判断并求出题目给出的另一个数转换多少进制
 * 才能与前一个数相等。
 * 利用二分法找进制数问题，处理过程稍微复杂，主要是越界问题，写的
 * 很不习惯，硬生生的折腾了两个半小时，最后还没有全对，下面的code
 * 在PAT上测试有一个是错的，实在找不出来了！！！事实证明写的还是太
 * 少了。
 */
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
int map[256];
char n1[20],n2[20];
int radix, target;

void init() {
    for (char c='0'; c<='9'; c++) {
        map[c] = c - '0';
    }
    for (char c='a'; c<='z'; c++) {
        map[c] = c - 'a' + 10;
    }
}
ll convert2ten(char s[], ll radix) {
    ll ans = 0;
    for (int i=0; s[i]!='\0'; i++) {
        ans = ans*radix + map[s[i]];
    }
    return ans;
}
ll findLargeDigit(char s[]) {
   ll ans=0;
   for (int i=0; s[i]!='\0'; i++) {
       if (map[s[i]] > ans) {
           ans = map[s[i]];
       }
   }
   return ans + 1;
}
int cmp (ll tar, char s[], ll radix) {        //检测转换过程中是否越界
    ll ans = 0;
    for (int i=0; s[i]!='\0'; i++) {
        ans = ans*radix + map[s[i]];
        if (ans > tar) {
            return 1;
        }
    }
    if (ans==tar) {
        return 0;
    } else if (ans>tar){
        return 1;
    } else {
        return -1;
    }
}
ll binarySearch(char s[], ll left, ll right, ll x) {
    ll mid;
    while (left<=right) {
        mid = (left+right) / 2;
        int flag = cmp(x,s,mid);
        if (flag==0) return mid;
        else if (flag>0) right = mid-1;
        else left = mid+1;
    }
    return -1;
}

int main() {
    scanf("%s %s %d %d", n1 ,n2, &target, &radix);
    init();
    if (target==2) {
        char temp[20];
        strcpy(temp, n1);
        strcpy(n1, n2);
        strcpy(n2, temp);
    }
    ll tar = convert2ten(n1, radix);     //将n1转换为十进制
    ll low = findLargeDigit(n2);         //找到n2最低进制
    ll high = (tar>low) ? tar+1:low+1;
    ll ans = binarySearch(n2, low, high, tar);
    if (ans!=-1) {
        printf("%lld\n", ans);
    } else {
        printf("Impossible\n");
    }
}
