//
// Created by authetic on 2018/8/21.
/*
 * 判断是插入排序还是归并排序
 * key: 数组做参数传入时相当于传入指针，不会新开辟空间
 */
//

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;
int arr[maxn],temp[maxn],change[maxn],n;

bool isSame(int a[]) {
    int i=0;
    while (i<n) {
        if(a[i] != change[i]) {
            return false;
        }
        i++;
    }
    return true;
}
void printArray(int a[]) {
    for (int i=0; i<n; i++) {
        printf("%d", a[i]);
        if (i<n-1) printf(" ");
    }
    printf("\n");
}

bool InsertSort(int a[]) {
    bool flag = false;
    for (int i=1; i<n; i++) {
        if (i!=1 && isSame(a)) {
            flag = true;
        }
        int temp=a[i], j=i;
        while (j>0 && temp<a[j-1]) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = temp;
        //printf("hh");
        if (flag) {
            printf("Insertion Sort\n");
            printArray(a);
            return true;
        }
    }
    return false;
}
void MergeSort(int a[]) {
    bool flag = false;
    for (int step=2; step/2<=n; step*=2) {
        if (step!=2 && isSame(a)) {
            flag = true;
        }
        for (int i=0; i<n; i+=step) {
            int temp = (i+step)<n ? i+step : n;
            sort(a+i, a+temp);
        }
        if (flag) {
            printf("Merge Sort\n");
            printArray(a);
            return ;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        temp[i] = arr[i];
    }
    for (int i=0; i<n; i++) {
        scanf("%d", &change[i]);
    }
    if (!InsertSort(temp)) {
        for (int i=0; i<n; i++) {
            temp[i] = arr[i];
        }
        MergeSort(temp);
    }
    return 0;
}