//
// Created by authetic on 2019/4/17.
//

/*
 * 堆：采用完全二叉树的结构存储，任何结点的值都大于其子树中所有结点的值
 */

#include <stdio.h>
#include <stdlib.h>
#include <climits>

typedef int ElementType;

const int MaxData = 0;

struct HeapStruct {
    ElementType *Elements;
    int Size;
    int Capacity;
};

typedef struct HeapStruct *MaxHeap;

MaxHeap Create(int MaxSize) {
    // malloc 工作机制？
    auto H = (MaxHeap)malloc(sizeof(struct HeapStruct));
    H->Elements = (ElementType*)malloc((MaxSize+1)*sizeof(ElementType));
    H->Size = 0;
    H->Capacity = MaxSize;
    // 设置哨兵
    H->Elements[0] = INT_MAX;
    return H;
}

// 堆的插入，时间复杂度O(log n)
void Insert(MaxHeap H, ElementType item) {
    if (H->Size == H->Capacity) {
        printf("Heap is full!");
        return;
    }
    int i = ++H->Size;
    // i等于0时有哨兵检测，自动结束循环
    for (; H->Elements[i/2] < item; i/=2) {
        H->Elements[i] = H->Elements[i/2];
    }
    H->Elements[i] = item;
}

// 删除堆顶元素
ElementType DeleteMax(MaxHeap H) {
    int parent, child;
    ElementType MaxItem, tmp;
    if (H->Size == 0) {
        printf("Heap is empty!");
        return INT_MIN;
    }
    MaxItem = H->Elements[1];
    tmp = H->Elements[H->Size--];
    for (parent = 1; parent*2 <= H->Size; parent = child) {
        child = parent*2;
        if (child != H->Size && H->Elements[child] < H->Elements[child+1]) {
            child++;
        }
        if (tmp >= H->Elements[child]) break;
        else H->Elements[parent] = H->Elements[child];
    }
    H->Elements[parent] = tmp;
    return MaxItem;
}