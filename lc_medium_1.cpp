// #lc-medium-1

#include "markers.h"
#include "list_node.h"

// Passed 1569 test cases on LC.
ListNode *run(ListNode *head_1, ListNode *head_2);

int main()
{
    __BEGIN

    ListNode *result = run(
        new ListNode(2, new ListNode(4, new ListNode(3))),
        new ListNode(5, new ListNode(6, new ListNode(4)))
    );
    print_list(result);
    std::cout << std::endl;

    result = run(
        new ListNode(9, new ListNode(9, new ListNode(9))),
        new ListNode(1)
    );
    print_list(result);
    std::cout << std::endl;

    result = run(
        new ListNode(9, new ListNode(9, new ListNode(9))),
        new ListNode(0)
    );
    print_list(result);
    std::cout << std::endl;

    result = run(
        new ListNode(0),
        new ListNode(0)
    );
    print_list(result);
    std::cout << std::endl;

    __END
}

ListNode *run(ListNode *node_1, ListNode *node_2)
{
    if (!node_1 || !node_2) return nullptr;

    ListNode *head = nullptr;
    ListNode *current = new ListNode(0);;
    int carry = 0;
    while (node_1 || node_2)
    {
        if (!head) {
            head = current;
        } else {
            current->next = new ListNode(0);
            current = current->next;
        }

        int sum = (node_1 ? node_1->val : 0) + (node_2 ? node_2->val : 0) + carry;
        current->val = sum % 10;
        carry = sum / 10;

        if (node_1) node_1 = node_1->next;
        if (node_2) node_2 = node_2->next;
    }

    if (carry) {
        current->next = new ListNode(1);
    }

    return head;
}
