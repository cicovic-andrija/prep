// #lc-hard-4

#include "markers.h"
#include "list_node.h"

// Passed 62 test cases on LC.
ListNode *reverse_k_groups(ListNode *head, int k);

int main()
{
    __BEGIN

    ListNode *result = reverse_k_groups(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))), 2);
    print_list(result); std::cout << std::endl;

    result = reverse_k_groups(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))), 3);
    print_list(result); std::cout << std::endl;

    result = reverse_k_groups(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))), 1);
    print_list(result); std::cout << std::endl;

    result = reverse_k_groups(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))), 7);
    print_list(result); std::cout << std::endl;

    __END
}

ListNode *reverse_k_groups(ListNode *head, const int k)
{
    if (!head || k < 2) return head;

    ListNode *end = head;
    int t = k;
    while (--t > 0 && end != nullptr) end = end->next;
    if (t || !end) return head; // list is not long enough

    ListNode *left = head;
    ListNode *right = head->next;
    head->next = reverse_k_groups(end->next, k);
    do {
        ListNode *next_right = right->next;
        right->next = left;
        left = right;
        right = next_right;
    } while (left != end);

    return end;
}
