# Problems



| State | Name | Link to problem | Link to solution |
| ----- | ---- | --------------- | ---------------- |
| ✅ | Two Sum | [lc-easy-1](#lc-easy-1) | [lc_easy_1.cpp](/lc_easy_1.cpp) |
| ✅ | Merge Two Sorted Lists | [lc-easy-2](#lc-easy-2) | [lc_easy_2.cpp](/lc_easy_2.cpp) |
| ✅ | Valid Brackets | [lc-easy-3](#lc-easy-3) | [lc_easy_3.cpp](/lc_easy_3.cpp) |
| ✅ | Ugly Number (I) | [lc-easy-4](#lc-easy-4) | [lc_easy_4.cpp](/lc_easy_4.cpp) |
| ✅ | Add Two Numbers | [lc-medium-1](#lc-medium-1) | [lc_medium_1.cpp](/lc_medium_1.cpp) |
| ✅ | Factorial Trailing Zeroes | [lc-medium-2](#lc-medium-2) | [lc_medium_2.cpp](/lc_medium_2.cpp) |
| ✅ | Ugly Number (II) | [lc-medium-3](#lc-medium-3) | [lc_medium_3.cpp](/lc_medium_3.cpp) |
| ✅ | Min. Rectangles to Cover Points | [lc-medium-4](#lc-medium-4) | [lc_medium_4.cpp](/lc_medium_4.cpp) |
| ✅ | Sort Colors | [lc-medium-5](#lc-medium-5) | [lc_medium_5.cpp](/lc_medium_5.cpp) |
| ✅ | Next Permutation | [lc-medium-6](#lc-medium-6) | [lc_medium_6.cpp](/lc_medium_6.cpp) |
| ✅ | Simplify Path | [lc-medium-7](#lc-medium-7) | [lc_medium_7.cpp](/lc_medium_7.cpp) |
| 🐉 | Ship Packages Within D Days | [lc-medium-8](#lc-medium-8) | [lc_medium_8.cpp](/lc_medium_8.cpp) |
| ✅ | Trapping Rain Water | [lc-hard-1](#lc-hard-1) | [lc_hard_1.cpp](/lc_hard_1.cpp) |
| ✅ | Merge k Sorted Lists | [lc-hard-2](#lc-hard-2) | [lc_hard_2.cpp](/lc_hard_2.cpp) |
| ✅ | Largest Rectangle in Histogram | [lc-hard-3](#lc-hard-3) | [lc_hard_3.cpp](/lc_hard_3.cpp) |
| ✅ | Reverse Nodes in k-Groups | [lc-hard-4](#lc-hard-4) | [lc_hard_4.cpp](/lc_hard_4.cpp) |
| 🐉 | Median of Two Sorted Arrays | [lc-hard-5](#lc-hard-5) | [lc_hard_5.cpp](/lc_hard_5.cpp) |
| 🐉 | N-Queens | [lc-hard-6](#lc-hard-6) | [lc_hard_6.cpp](/lc_hard_6.cpp) |
| ✅ | Happy Who? | [my-easy-1](#my-easy-1) | [my_easy_1.cpp](/my_easy_1.cpp) |
| ✅ | Sorting (I) | [my-easy-2](#my-easy-2) | [my_easy_2.cpp](/my_easy_2.cpp) |
| ✅ | Binary Search | [my-easy-3](#my-easy-3) | [my_easy_3.cpp](/my_easy_3.cpp) |
| ✅ | Matrix Rotation | [my-medium-1](#my-medium-1) | [my_medium_1.cpp](/my_medium_1.cpp) |
| ✅ | Sorting (II)  | [my-medium-2](#my-medium-2) | [my_medium_2.cpp](/my_medium_2.cpp) |
| ❌ | Persistent K/V Store | [my-hard-1](#my-hard-1) | [my_hard_1.cpp](/my_hard_1.cpp) |

# lc-easy-1

Given an array of integers and an integer target, return indices of the two numbers such that they add up to target. You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.

# lc-easy-2

You are given the heads of two sorted linked lists of integers (ascending). Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists. Return the head of the merged linked list. Use definitions from [list_node.h](/list_node.h).

# lc-easy-3

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. An input string is valid if (1) open brackets are closed by the same type of brackets, (2) open brackets are closed in the correct order, and (3) every closed bracket has a corresponding open bracket of the same type.

# lc-easy-4

An ugly number is a positive integer which does not have a prime factor other than 2, 3, and 5. Given an integer n, return true if n is an ugly number.

# lc-medium-1

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list. You may assume the two numbers do not contain any leading zero, except the number 0 itself. Example: 2 > 4 > 3 (number 342), 5 > 6 > 4 (number 465) should return a linked list 7 > 0 > 8 (342 + 465 = 807). Use definitions from [list_node.h](/list_node.h).

# lc-medium-2

Given an integer n, return the number of trailing zeroes in n!.

# lc-medium-3

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5. Given an integer n, return the n-th ugly number.

# lc-medium-4

Given a 2D integer array of distinct points (x, y) and an integer w >= 0, cover all the points with rectangles. Each rectangle has its lower end on (x1, 0) and its upper end at (x2, y2), where x1 <= x2, x1 >= 0, x2 >= 0 and y2 >= 0, and the condition x2 - x1 <= w must be satisfied for each rectangle. A point is considered covered by a rectangle if it lies within or on the boundary of the rectangle. Return an integer denoting the minimum number of rectangles needed so that each point is covered by at least one rectangle (a point may be covered by more than one rectangle).

Example: input: points = [[2,1],[1,0],[1,4],[1,8],[3,5],[4,6]], w = 1 output: 2

![lc-medium-4-img](/docs/img/lc-medium-4.png)

# lc-medium-5

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue. Use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

Example: input: nums = [2,0,2,1,1,0] output: [0,0,1,1,2,2]

# lc-medium-6

A permutation of an array of integers is an arrangement of its members into a sequence or linear order. For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]. The next permutation of an array of integers is the next lexicographically greater permutation of its integers. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged to the lowest possible order (i.e., sorted in ascending order). For example, the next permutation of [2,3,1] is [3,1,2], and the next permutation of [3,2,1] is [1,2,3]. Given an array of integers nums, rearrange the array in-place so it contains the next permutation of nums.

# lc-medium-7

You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform this absolute path into its simplified canonical path. The rules of a Unix-style file system are as follows:

- A single period '.' represents the current directory.
- A double period '..' represents the previous/parent directory.
- Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
- Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, '...' and '....' are valid directory or file names.

The simplified canonical path should follow these rules:

- The path must start with a single slash '/'.
- Directories within the path must be separated by exactly one slash '/'.
- The path must not end with a slash '/', unless it is the root directory.
- The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.

Return the simplified canonical path. Assume the given path is valid.

# lc-medium-8

A conveyor belt has packages that must be shipped from one port to another within d days. The i-th package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by array weights). We may not load more weight than the maximum weight capacity of the ship. Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within d days. Note that the cargo must be shipped in the order given.

Example: input: weights = [1,2,3,4,5,6,7,8,9,10], d = 5 output: 15
Example: input: weights = [3,2,2,4,1,4], d = 3 output: 6

# lc-hard-1

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example: input: [0,1,0,2,1,0,1,3,2,1,2,1] output: 6

![lc-hard-1-img](/docs/img/lc-hard-1.png)

# lc-hard-2

You are given an array of k linked lists, where each linked list is sorted in ascending order. Merge all the linked lists into one sorted linked list and return it. Use definitions from [list_node.h](/list_node.h).

# lc-hard-3

Given an array of integers representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

![lc-hard-3-img](/docs/img/lc-hard-3.jpg)

# lc-hard-4

Given the head of a linked list, reverse the nodes of the list, k nodes at a time, and return the modified list. Parameter k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then surplus nodes at the end should remain not reversed. Do not alter the values in the list's nodes. Use definitions from [list_node.h](/list_node.h).

Example: input: 1-2-3-4-5, k = 2 output: 2-1-4-3-5

# my-easy-1

Given a positive integer k, determine whether k is a happy number. Any number that reduces to one when you take the sum of the square of its digits and continue iterating until it yields 1, is a happy number.

# my-easy-2

Implement selection sort, bubble sort and insertion sort.

# my-easy-3

Implement a binary search algorithm.

# my-medium-1

Rotate a given 2D matrix by 90 degrees clock-wise and counterclock-wise.

# my-medium-2

Implement quick sort and heap sort.

# my-hard-1

Implement a persistent key/value store.
