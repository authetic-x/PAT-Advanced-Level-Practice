//
// Created by authetic on 2019/4/8.
//

#include <stdio.h>
#include <climits>

#define MAXSIZE 100

typedef int ElementType;

struct SNode {
    ElementType data[MAXSIZE];
    // Top = -1
    int Top;
};

typedef SNode* Stack;

void Push(Stack PtrS, ElementType item) {
    if (PtrS->Top == MAXSIZE-1) {
        printf("Full Stack!");
        return;
    }
    PtrS->data[++(PtrS->Top)] = item;
}

ElementType Pop(Stack PtrS) {
    if (PtrS->Top == -1) {
        printf("Empty Stack!");
        return INT_MAX;
    }
    return PtrS->data[(PtrS->Top)--];
}

struct SNode2 {
    ElementType data[MAXSIZE];
    // Top1 = -1, Top2 = MAXSIZE;
    int Top1, Top2;
};

typedef SNode2* DStack;

void DPush(DStack PtrS, ElementType item, int tag) {
    if (PtrS->Top2 - PtrS->Top1 == 1) {
        printf("Full Stack");
        return;
    }
    if (tag == 1) {
        PtrS->data[++(PtrS->Top1)] = item;
    } else {
        PtrS->data[--(PtrS->Top2)] = item;
    }
}

ElementType DPop(DStack PtrS, int tag) {
    if (tag == 1) {
        if (PtrS->Top1 == -1) {
            printf("Left Stack is full!");
            return NULL;
        } else {
            return PtrS->data[(PtrS->Top1)--];
        }
    } else {
        if (PtrS->Top2 == MAXSIZE) {
            printf("Right Stack is full!");
            return NULL;
        } else {
            return PtrS->data[(PtrS->Top2)++];
        }
    }
}