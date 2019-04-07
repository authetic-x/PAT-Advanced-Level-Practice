//
// Created by authetic on 2019/4/7.
//

/*
 * 链表的基本结构和操作集
 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct LNode {
    ElementType data;
    List next;
};

typedef LNode *List;

List PtrL;

int length(List PtrL) {
    List p = PtrL;
    int j = 0;
    while (p) {
        p = p->next;
        j ++;
    }
    return j;
}

List FindKth(int k, List PtrL) {
    List p = PtrL;
    int i = 1;
    while (p != nullptr && i < k) {
        p = p->next;
        i ++;
    }
    if (i == k) return p;
    else return nullptr;
}

List Find(ElementType X, List PtrL) {
    List p = PtrL;
    while (p != nullptr && p->data != X) {
        p = p->next;
    }
    return p;
}

List insert(ElementType X, int i, List PtrL) {
    if (i == 1) {
        List s = (List)malloc(sizeof(LNode));
        s->data = X;
        s->next = PtrL;
        return s;
    }
    List p = FindKth(i-1, PtrL);
    if (p == nullptr) {
        printf("Invalid Position");
        return nullptr;
    } else {
        List s = (List)malloc(sizeof(LNode));
        s->data = X;
        s->next = p->next;
        p->next = s->next;
        return PtrL;
    }
}

List Delete(int i, List PtrL) {
    List p, s;
    if (i == 1) {
        s = PtrL;
        if (PtrL != nullptr) {
            PtrL = PtrL->next;
        } else {
            return nullptr;
        }
        free(s);
        return PtrL;
    }
    p = FindKth(i-1, PtrL);
    if (p == nullptr || p->next == nullptr) {
        printf("Invalid Position");
        return nullptr;
    }
    s = p->next;
    p->next = s->next;
    free(s);
    return PtrL;
}