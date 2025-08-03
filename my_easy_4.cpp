// #my-easy-4

#include "markers.h"
#include "list_node.h"
#include "vect.h"

#include <algorithm>

bool list_has_cycle(const ListNode *head);
ListNode *list_find_cycle_start(ListNode *head);
bool array_has_cycle(const std::vector<int> &arr);

int main()
{
    __BEGIN

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2, new ListNode(3, new ListNode(4, head)));
    ListNode *no_cycle_head = new ListNode(1, new ListNode (2, new ListNode(3)));

    std::cout << list_has_cycle(head) << std::endl;
    std::cout << list_has_cycle(no_cycle_head) << std::endl;

    std::vector<int> vec_with_cycle = { 1, 2, 3, 4, 2 };
    std::cout << array_has_cycle(vec_with_cycle) << std::endl;

    __END
}

bool list_has_cycle(const ListNode *head)
{
    const ListNode *slow = head;
    const ListNode *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }

    return false;
}

ListNode *list_find_cycle_start(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}

bool array_has_cycle(const std::vector<int> &arr)
{
    int slow = 0;
    int fast = 0;
    int n = arr.size();

    do {
        if (fast >= n || arr[fast] >= n) {
            return false;
        }

        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    return true;
}
