//
// Created by authetic on 2019/4/1.
//

/*
 * 对于类似员工年龄的特殊排序，数据大小范围较小
 * 可以选择空间换时间，实现复杂度为O(n)的排序
 */

#include <iostream>
using namespace std;

void sort(int ages[], int len) {
    if (ages == nullptr || len <= 0) return ;
    int oldest = 99;
    int timeOfAges[oldest+1];
    fill(timeOfAges, timeOfAges+oldest+1, 0);

    for (int i = 0; i < len; i ++ ) {
        int age = ages[i];
        timeOfAges[age]++;
    }
    int index = 0;
    for (int i = 0; i <= oldest; i ++ ) {
        for (int j = 0; j < timeOfAges[i]; j ++ ) {
            ages[index++] = i;
        }
    }
}