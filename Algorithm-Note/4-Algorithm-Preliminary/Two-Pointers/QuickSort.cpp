//
// Created by authetic on 2018/8/21.
/*
 * 快速排序
 */
//

#include <cstdio>
#include <cstdlib>
#include <ctime>

const int maxn = 100010;
int a[maxn];

int position(int a[], int left, int right) {
    int temp = a[left];
    while (left<right) {
        while (left<right && a[right]>temp) right--;
        a[left] = a[right];
        while (left<right && a[left]<=temp) left++;
        a[right] = a[left];
    }
    a[left] = temp;
    return left;
}
void QuickSort(int a[], int left, int right) {
    if (left<right) {
        int pos = position(a,left,right);
        QuickSort(a, left, pos-1);
        QuickSort(a, pos+1, right);
    }
}