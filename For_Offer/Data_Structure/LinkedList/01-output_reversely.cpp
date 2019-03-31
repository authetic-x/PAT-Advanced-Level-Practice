//
// Created by authetic on 2019/3/31.
//

/*
 * 从后到前输出链表的两种方式，本质都是递归
 */

#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int value;
    Node *next;
};

void output_stack(Node* head) {
    stack<Node*> nodes;
    Node* node = head;
    while (node != nullptr) {
        nodes.push(node);
        node = node->next;
    }
    while(!nodes.empty()) {
        node = nodes.top();
        cout << node->value << " ";
        nodes.pop();
    }
}

void output_recursive(Node* head) {
    if (head != nullptr) {
        if (head->next != nullptr) {
            output_recursive(head->next);
        }
        cout << head->value << " ";
    }
}