//
// Created by authetic on 2019/4/2.
//

/*
 * 给出一个数n，输出从1到n位数的所有数字
 * keys: 考虑到n会很大，所以要用char数组来存储，
 * 利用递归依次输出全排列即可，注意剔除前面的0
 */

#include <iostream>
using namespace std;

void PrintNum(char num[], int n) {
    bool isZero = true;
    for (int i = 0; i < n; i ++ ) {
        if (num[i] != 0) isZero = false;
        if (!isZero) {
            printf("%c", num[i]);
        }
    }
    printf("\n");
}

void PrintDigitCore(int n, char num[], int index) {
    if (index == n-1) {
        PrintNum(num, n);
        return;
    }
    for (int i = 0; i < 10; i ++ ) {
        index ++;
        num[index] = i + '0';
        PrintDigitCore(n, num, index);
    }
}

void PrintDigit(int n) {
    if (n <= 0) return ;
    char num[n+1];
    for (int i = 0; i < 10; i ++ ) {
        num[0] = '0' + i;
        PrintDigitCore(n, num, 0);
    }
}