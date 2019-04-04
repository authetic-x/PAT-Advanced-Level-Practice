//
// Created by authetic on 2019/4/2.
//

/*
 * (!!)模拟正则表达式的匹配
 * keys: 先分析再写代码，理解递归的意义，递归边界和递归式
 */

#include <iostream>
using namespace std;

bool matchCore(char* str, char* pattern) {
    if (*str == '\0' && *pattern == '\0') return true;
    if (*str != '\0' && *pattern == '\0') return false;
    if (*(pattern + 1) == '*') {
        if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
            return matchCore(str+1, pattern)
                    || matchCore(str, pattern+2);
        }
        return matchCore(str, pattern+2);
    }
    if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
        return matchCore(str+1, pattern+1);
    }
    return false;
}

bool match(char *str, char *pattern) {
    if (str == nullptr || pattern == nullptr) return false;
    return matchCore(str, pattern);
}