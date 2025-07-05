# Problems



| State | Name | Link to problem | Link to solution |
| ----- | ---- | --------------- | ---------------- |
| ✅ | Two Sum | [lc-easy-1](#lc-easy-1) | [lc_easy_1.cpp](/lc_easy_1.cpp) |
| ✅ | Merge Two Sorted Lists | [lc-easy-2](#lc-easy-2) | [lc_easy_2.cpp](/lc_easy_2.cpp) |
| ✅ | Valid Brackets | [lc-easy-3](#lc-easy-3) | [lc_easy_3.cpp](/lc_easy_3.cpp) |
| ✅ | Add Two Numbers | [lc-medium-1](#lc-medium-1) | [lc_medium_1.cpp](/lc_medium_1.cpp) |
| ✅ | Trapping Rain Water | [lc-hard-1](#lc-hard-1) | [lc_hard_1.cpp](/lc_hard_1.cpp) |
| ✅ | Merge k Sorted Lists | [lc-hard-2](#lc-hard-2) | [lc_hard_2.cpp](/lc_hard_2.cpp) |
| ✅ | Largest Rectangle in Histogram | [lc-hard-3](#lc-hard-3) | [lc_hard_3.cpp](/lc_hard_3.cpp) |
| ✅ | Happy Who? | [my-easy-1](#my-easy-1) | [my_easy_1.cpp](/my_easy_1.cpp) |
| ❌ | Persistent K/V Store | [my-hard-1](#my-hard-1) | [my_hard_1.cpp](/my_hard_1.cpp) |

# lc-easy-1

Given an array of integers and an integer target, return indices of the two numbers such that they add up to target. You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.

# lc-easy-2

You are given the heads of two sorted linked lists of integers (ascending). Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists. Return the head of the merged linked list. Use definitions from [list_node.h](/list_node.h).

# lc-easy-3

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. An input string is valid if (1) open brackets are closed by the same type of brackets, (2) open brackets are closed in the correct order, and (3) every closed bracket has a corresponding open bracket of the same type.

# lc-medium-1

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list. You may assume the two numbers do not contain any leading zero, except the number 0 itself. Example: 2 > 4 > 3 (number 342), 5 > 6 > 4 (number 465) should return a linked list 7 > 0 > 8 (342 + 465 = 807). Use definitions from [list_node.h](/list_node.h).

# lc-hard-1

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example: input: 0,1,0,2,1,0,1,3,2,1,2,1 output: 6

![lc-hard-1-img](/docs/img/lc-hard-1.png)

# lc-hard-2

You are given an array of k linked lists, where each linked list is sorted in ascending order. Merge all the linked lists into one sorted linked list and return it. Use definitions from [list_node.h](/list_node.h).

# lc-hard-3

Given an array of integers representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

![lc-hard-3-img](/docs/img/lc-hard-3.jpg)

# my-easy-1

Given a positive integer k, determine whether k is a happy number. Any number that reduces to one when you take the sum of the square of its digits and continue iterating until it yields 1, is a happy number.

# my-hard-1

Implement a persistent key/value store.
