//
// Created by authetic on 2019/4/8.
//

#include <stdio.h>
#include <stdlib.h>

/*
 * 用链表存储的队列都直接指向队首和
 * 队尾，操作比较方便！
 */

typedef int ElementType;

struct Node {
    ElementType data;
    Node* next;
};

struct QNode {
    Node* front;
    Node* rear;
};

typedef QNode* Queue;

void addQ(Queue PtrQ, ElementType item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = nullptr;
    PtrQ->rear->next = newNode;
    PtrQ->rear = newNode;
}

ElementType deleteQ(Queue PtrQ) {
    if (PtrQ->front == nullptr) {
        printf("Empty Queue!");
        return NULL;
    }
    Node* firstCell = PtrQ->front;
    if (PtrQ->front == PtrQ->rear) {
        PtrQ->front = PtrQ->rear = nullptr;
    } else {
        PtrQ->front = PtrQ->front->next;
    }
    ElementType firstElem = firstCell->data;
    free(firstCell);
    return firstElem;
}