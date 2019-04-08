//
// Created by authetic on 2019/4/8.
//

#include <stdio.h>
#include <stdlib.h>

/*
 * 堆栈实现中缀表达式转后缀表达式的步骤
 * 1. 碰到运算数直接输出
 * 2. 碰到运算符与栈顶元素比较，若优先级大
 *    则入栈，优先级小输出栈顶元素直到找到
 *    一个比自己优先级小的为止
 * 3. 左括号直接入栈，右括号依次弹出左括号
 *    上的运算符
 */

typedef int ElementType;

// 链式存储的栈，Top在链表的首部
struct SNode {
    ElementType data;
    SNode* Next;
};

typedef SNode* Stack;

Stack createStack() {
    Stack s;
    s = (Stack)malloc(sizeof(SNode));
    s->Next = nullptr;
    return s;
}

int isEmpty(Stack PtrS) {
    return (PtrS->Next == nullptr);
}

void Push(Stack PtrS, ElementType item) {
    Stack tmp = (Stack)malloc(sizeof(SNode));
    tmp->data = item;
    tmp->Next = PtrS->Next;
    PtrS->Next = tmp;
}

ElementType Pop(Stack PtrS) {
    Stack FirstCell;
    ElementType TopElem;
    if (isEmpty(PtrS)) {
        printf("Empty Stack!");
        return NULL;
    } else {
        FirstCell = PtrS->Next;
        PtrS->Next = FirstCell->Next;
        TopElem = FirstCell->data;
        free(FirstCell);
        return TopElem;
    }
}