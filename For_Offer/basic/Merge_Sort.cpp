//
// Created by authetic on 2019/3/31.
//

#include <iostream>
using namespace std;

const int SIZE = 5;

void merge(int a[], int l, int m, int r) {
    int temp[SIZE];
    int i = l, j = m+1, k = 0;
    while (i <= m && j <= r) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }
    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];
    for (i = l, j = 0; j < k; i ++, j ++ ) {
        a[i] = temp[j];
    }
}

void MergeSort(int a[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        MergeSort(a, l, mid);
        MergeSort(a, mid+1, r);
        merge(a, l, mid, r);
    }
}

int main() {
    int a[SIZE];
    for (int i = 0; i < SIZE; i ++ ) cin >> a[i];
    MergeSort(a, 0, 4);
    for (int i = 0; i < SIZE; i ++ ) cout << a[i] << " ";
    return 0;
}