#ifndef PREP_LIST_NODE_H
#define PREP_LIST_NODE_H

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(): val(0), next(nullptr) {}
    ListNode(int v): val(v), next(nullptr) {}
    ListNode(int v, ListNode *n): val(v), next(n) {}
};

void print_list(ListNode *head)
{
    if (!head) {
        std::cout << "(the list is empty)";
        return;
    } else {
        std::cout << head->val;
        if (head->next) {
            std::cout << " -> ";
            print_list(head->next);
        }
    }
}

#endif // PREP_LIST_NODE_H
