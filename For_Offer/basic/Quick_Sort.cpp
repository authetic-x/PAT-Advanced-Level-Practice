//
// Created by authetic on 2019/3/31.
//

#include <iostream>
using namespace std;

int partion(int a[], int st, int ed) {
    int i =st, j = ed, tmp = a[st];
    while (i < j) {
        while (i < j && a[j] >= tmp) {
            j --;
        }
        if (i < j) {
            a[i] = a[j];
            i++;
        }
        while (i < j && a[i] < tmp) {
            i ++;
        }
        if (i < j) {
            a[j] = a[i];
            j --;
        }
    }
    a[i] = tmp;
    return i;
}

void QuickSort(int a[], int l, int r) {
    if (l < r) {
        int m = partion(a, l, r);
        QuickSort(a, l, m-1);
        QuickSort(a, m+1, r);
    }
}

int main() {
    int a[10];
    for (int i = 0; i < 5; i ++) cin >> a[i];
    QuickSort(a, 0, 4);
    for (int i = 0; i < 5; i ++ ) cout << a[i] << ' ';
    return 0;
}