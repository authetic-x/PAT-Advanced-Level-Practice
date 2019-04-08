//
// Created by authetic on 2019/4/8.
//

#include <stdio.h>

#define MAXSIZE 100

typedef int Element;

/*
 * 顺序存储的队列front下一个为队首元素
 * rear指向队尾元素。对于循环队列，当
 * front==rear时，表示空队列，表示队列
 * 为满有两种方式：1. 留一个空位，当
 * (rear-(front+1)%MAXSIZE)==1时，
 * 队列已满；2. 设置一个size或者tag
 */

struct QNode {
    Element data[MAXSIZE];
    // front=rear=-1
    int front, rear;
};

typedef QNode* Queue;

void QAdd(Queue PtrQ, Element item) {
    if ((PtrQ->rear+1)%MAXSIZE == PtrQ->front) {
        printf("Full Queue!");
        return;
    }
    PtrQ->rear = (PtrQ->rear+1)%MAXSIZE;
    PtrQ->data[PtrQ->rear] = item;
}

Element deleteQ(Queue PtrQ) {
    if (PtrQ->front == PtrQ->rear) {
        printf("Empty Queue!");
        return NULL;
    }
    PtrQ->front = (PtrQ->front+1)%MAXSIZE;
    return PtrQ->data[PtrQ->front];
}