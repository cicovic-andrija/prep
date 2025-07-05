// #lc-hard-2

#include "markers.h"
#include "list_node.h"

#include <vector>

// Passed 134 test cases on LC.
ListNode *merge_k(std::vector<ListNode*> &heads);

int main()
{
    __BEGIN

    // Too lazy to write test cases locally.

    __END
}

ListNode *merge_k(std::vector<ListNode *> &heads)
{
    ListNode *merge_two(ListNode *, ListNode *);

    int n = heads.size();
    if (n == 0) return nullptr;

    int interval = 1;
    while (interval < n)
    {
        for (int i = 0; i < n - interval; i += 2 * interval) {
            heads[i] = merge_two(heads[i], heads[i + interval]);
        }

        interval <<= 1;
    }

    return heads[0];
}

ListNode *merge_two(ListNode *head_1, ListNode *head_2)
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
