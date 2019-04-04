//
// Created by authetic on 2019/4/2.
//

/*
 * 实现Power函数的功能
 * keys: 可演化为类似于斐波那契问题求解
 * 注意细节，base为0时，以及exponent为负数时
 *
 * Details determine everything!
 */

#include <iostream>
using namespace std;

double PowerWithUnsignedExponent(double base, int exponent) {
    if (exponent == 0) return 1;
    if (exponent == 1) return base;
    double res = PowerWithUnsignedExponent(base, exponent >> 1);
    res *= res;
    if (exponent % 2 == 1) res *= base;
    return res;
}

double Power(double base, int exponent) {
    if (base == 0) return 0;
    int absExponent = exponent;
    if (exponent < 0) absExponent = -exponent;
    double res = PowerWithUnsignedExponent(base, absExponent);
    if (exponent < 0) {
        return 1 / res;
    }
    return res;
}