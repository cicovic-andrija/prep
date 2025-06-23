# nav

- [lc-easy-1](#lc-easy-1)
- [lc-medium-1](#lc-medium-1)

# lc-easy-1

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.

# lc-medium-1

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list. You may assume the two numbers do not contain any leading zero, except the number 0 itself. Example: 2->4->3 (number 342), 5->6->4 (number 465) should return a linked list 7->0->8 (342 + 465 = 807).

```cpp
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
```
