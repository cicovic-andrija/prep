// #lc-easy-2

#include "markers.h"
#include "list_node.h"

// Passed 208 test cases on LC.
ListNode *run(ListNode *head_1, ListNode *head_2);

int main()
{
    __BEGIN

    print_list(run(
        new ListNode(1, new ListNode(2, new ListNode(4))),
        new ListNode(1, new ListNode(3, new ListNode(4)))
    ));
    std::cout << std::endl;

    print_list(run(nullptr, new ListNode(2, new ListNode(4))));
    std::cout << std::endl;

    print_list(run(new ListNode(1, new ListNode(3)), nullptr));
    std::cout << std::endl;

    print_list(run(nullptr, nullptr));
    std::cout << std::endl;

    __END
}

ListNode *run(ListNode *head_1, ListNode *head_2)
{
    if (!head_1) return head_2;
    if (!head_2) return head_1;

    ListNode *r_head = head_1->val <= head_2->val ? head_1 : head_2;
    ListNode *r_tail = r_head;
    if (r_head == head_1) {
        head_1 = head_1->next;
    } else {
        head_2 = head_2->next;
    }

    while (head_1 && head_2)
    {
        r_tail = r_tail->next = head_1->val <= head_2->val ? head_1 : head_2;
        if (r_tail == head_1) {
            head_1 = head_1->next;
        } else {
            head_2 = head_2->next;
        }
    }

    while (head_1)
    {
        r_tail = r_tail->next = head_1;
        head_1 = head_1->next;
    }

    while (head_2)
    {
        r_tail = r_tail->next = head_2;
        head_2 = head_2->next;
    }

    return r_head;
}
