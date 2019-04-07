//
// Created by authetic on 2019/4/7.
//

/*
 * 顺序表的基本结构和操作集
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElementType;

struct LNode {
    ElementType data[MAXSIZE];
    int last;
};

typedef LNode *List;

List create() {
    List PtrL = (List)malloc(sizeof(LNode));
    PtrL->last = -1;
    return PtrL;
}

int find(ElementType n, List PtrL) {
    int i = 0;
    while (i <= PtrL->last && PtrL->data[i] != n) {
        i ++;
    }
    if (i > PtrL->last) return -1;
    return i;
}

void insert(ElementType n, int i, List PtrL) {
    if (PtrL->last == MAXSIZE-1) {
        printf("Full Size!");
        return;
    }
    // 这里i老师设置的有点奇怪，不是数组下标，而是下标+1
    // i - 1 < 0 || i - 1 > PtrL->last+1
    if (i < 1 || i > PtrL->last + 2) {
        printf("Invalid Position!");
        return;
    }
    for (int j = PtrL->last; j >= i-1; j -- ) {
        PtrL->data[j+1] = PtrL->data[j];
    }
    PtrL->data[i-1] = n;
    PtrL->last++;
}

void Delete(int i, List PtrL) {
    if (i > PtrL->last+1 || i < 1) {
        printf("Invalid Position!");
        return;
    }
    for (int j = i-1; j < PtrL->last; j ++ ) {
        PtrL->data[j] = PtrL->data[j+1];
    }
    PtrL->last--;
}