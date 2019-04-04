//
// Created by authetic on 2019/4/2.
//

/*
 * 删除链表的某个结点
 */

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

void deleteNode(Node** head, Node* toBeDeleted) {
    if (!head || !toBeDeleted) return;
    if (toBeDeleted->next != nullptr) {
        Node* next = toBeDeleted->next;
        toBeDeleted->value = next->value;
        toBeDeleted->next = next->next;
        delete next;
        next = nullptr;
    } else if (toBeDeleted == *head) {
        delete *head;
    } else {
        Node* preNode = *head;
        while(preNode != toBeDeleted) {
            preNode = preNode->next;
        }
        preNode->next = toBeDeleted->next;
        delete toBeDeleted;
    }
}