//
// Created by authetic on 2019/3/31.
//

/*
 * (!)将字符串中的空格替换为"%20"
 * keys: 暴力解法时间复杂度为O(n^2)不可取，复杂度为O(n)做法是
 * 先遍历字符串，求出空格的个数，计算出字符串数组扩展后的长度，设置
 * 两个指针分别指向原数组末尾下标(注意'\0'字符)，扩展后数组末尾下标，
 * 从后向前遍历，依次替换即可，注意结束条件！
 *
 * Details determine anything!
 */

#include <iostream>
using namespace std;

void Replace_Blank(char string[], int len) {
    if (string == nullptr || len < 0) return;
    int original_len = 0;
    int nums_blank = 0;
    int i = 0;
    while (string[i] != '\0') {
        original_len ++;
        if (string[i] == ' ') {
            nums_blank ++;
        }
        i++;
    }
    int new_len = original_len + nums_blank * 2;
    if (new_len > len) return;
    int index_origin = original_len;
    int index_new = new_len;
    while (index_origin >= 0 && index_new > index_origin) {
        if (string[index_origin] != ' ') {
            string[index_new--] = string[index_origin--];
        } else {
            string[index_new--] = '0';
            string[index_new--] = '2';
            string[index_new--] = '%';
            index_origin--;
        }
    }
}

int main() {
    char s[30] = "hello miyi!";
    Replace_Blank(s, 30);
    printf("%s", s);
    return 0;
}