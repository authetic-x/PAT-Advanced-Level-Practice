//
// Created by authetic on 2018/9/20.
/*
 * 堆排序
 * Note: 没有想象中的复杂，堆是一个完全二叉树，根结点最大，
 * 每次排序就是将最大的点移到最后，然后将根结点替换为剩下的最大值即可！
 */
//

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;

int n;
int a[maxn],origin[maxn],changed[maxn];

bool isSame(int a[], int b[]) {
    for (int i=1; i<=n; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void showArray(int a[]) {
    for (int i=1; i<=n; i++) {
        printf("%d", a[i]);
        if (i<n) printf(" ");
    }
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

bool Insertion() {
    bool flag = false;
    for (int i=2; i<=n; i++) {
        if (i!=2 && isSame(a,changed)) flag = true;
        sort(a+1, a+i+1);
        if (flag) return true;
    }
    return false;
}

void downAdjust(int low, int high) {
    int i=low,j;
    j = i*2;
    while (j <= high) {
        if (j+1<=high && a[j+1]>a[j]) {
            j = j+1;
        }
        if (a[j]>a[i]) {
            swap(a[i],a[j]);
            i = j;
            j = i*2;
        } else {
            break;
        }
    }
}

void heapSort() {
    for (int i=n/2; i>=1; i--) {
        downAdjust(i,n);
    }
    bool flag = false;
    for (int i=n; i>1; i--) {
        if (i!=n && isSame(a, changed)) flag = true;
        swap(a[1],a[i]);
        downAdjust(1,i-1);
        if (flag) {
            showArray(a);
            return;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d", &origin[i]);
        a[i] = origin[i];
    }
    for (int i=1; i<=n; i++) {
        scanf("%d", &changed[i]);
    }
    if (Insertion()) {
        printf("Insertion Sort\n");
        showArray(a);
    } else {
        for (int i=1; i<=n ;i++) {
            a[i] = origin[i];
        }
        printf("Heap Sort\n");
        heapSort();
    }
    return 0;
}