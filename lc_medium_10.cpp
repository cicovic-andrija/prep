// #lc-medium-10

#include "markers.h"

struct Node {
    int val;
    Node *next;
    Node *rand;
    Node(int v): val(v), next(nullptr), rand(nullptr) {}
};

// Passed 19 test cases on LC.
Node *clone_list(Node *head);

int main()
{
    __BEGIN

    // Too lazy to write test cases locally.

    __END
}

Node *clone_list(Node *head)
{
    if (!head) return nullptr;

    // first, merge two lists: X -> Y -> X -> Y ...
    // where Y are nodes of the new list (clone)
    Node *node = head;
    while (node) {
        Node *clone = new Node(node->val);
        clone->next = node->next;
        node->next = clone;
        node = clone->next;
    }

    Node *head_clone = head->next;

    // second, assign random pointers in Y nodes
    node = head;
    while (node) {
        Node *clone = node->next;
        if (node->rand) clone->rand = node->rand->next;
        node = clone->next;
    }

    // third, untangle the two lists
    node = head;
    while (node) {
        Node *clone = node->next;
        node->next = clone->next;
        node = node->next;
        if (node) {
            clone->next = node->next;
        }
    }

    return head_clone;
}
