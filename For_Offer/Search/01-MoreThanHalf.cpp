//
// Created by authetic on 2019/4/3.
//

/*
 * 寻找一个数组中出现次数超过数组长度一般的数字
 *
 */

#include <iostream>
using namespace std;

int MoreThanHalfNum(int *nums, int len) {
    if (nums == nullptr || len <= 0) return 0;
    int time = 1, res = nums[0];
    for (int i = 0;i < len; i ++ ) {
        if (time == 0) {
            res = nums[i];
        } else if (res == nums[i]) {
            time ++;
        } else {
            time --;
        };
    }
    return res;
}