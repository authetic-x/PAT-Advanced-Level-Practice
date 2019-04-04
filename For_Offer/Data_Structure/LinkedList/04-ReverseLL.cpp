//
// Created by authetic on 2019/4/3.
//

/*
 * 反转链表
 * 我的做法是递归反转
 */

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

Node* newHead = nullptr;

void ReverseCore(Node* node, Node* preNode) {
    if (node->next != nullptr) {
        ReverseCore(node->next, node);
    } else {
        newHead->value = node->value;
        newHead->next = preNode;
    }
    node->next = preNode;
}

Node* Reverse(Node* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) return head;

    ReverseCore(head->next, head);
    head->next = nullptr;
    return newHead;
}