//
// Created by authetic on 2019/4/3.
//

/*
 * 打印链表倒数第K个结点
 */

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

int flag = 0;

void printCore(Node* node, int k) {
    if (node->next != nullptr) {
        printCore(node->next, k);
    }
    flag ++;
    if (flag == k) cout << node->value;
}

void printK(Node* head, int k) {
    if (head == nullptr || k <= 0) return;
    printCore(head, k);
}