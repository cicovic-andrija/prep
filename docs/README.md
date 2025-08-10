# Coding interview prep

## Problems

| DOCUMENT | DESCRIPTION |
| -------- | ----------- |
| [`docs/PROBLEMS.md`](/docs/PROBLEMS.md) | Problem statements. |
| [`old_c/README.md`](/old_c/README.md) | Usage instructions for my old C interview prep platform. |

## Solutions

| FILE NAME (FORMAT) | DESCRIPTION |
| ------------------ | ----------- |
| `lc_{diff}_{num}.cpp` | Solution for `lc-{diff}-{num}` in `docs/PROBLEMS.md`. |
| `my_{diff}_{num}.cpp` | Solution for `my-{diff}-{num}` in `docs/PROBLEMS.md`. |
| `misc_*.cpp` | Misc. programs / C++ experiments. |
| `*.cpp`, `*.h` | Utility functions and classes. |

## Plan

### 1. Presentation

- Write your CV.
- Update your LinkedIn and GitHub profiles with latest information. Make sure it is consistent with the CV.

### 2. Preparation Plan

#### 2.1. Coding + Algorithms

- Main Task #1 - Solve a set of ~50 LeetCode questions, with easy/medium/hard distribution of ~10/25/15.
  - Good resource: _Cracking the Coding Interview_ book.
- Main Task #2 - Cover the most common algorithms/patterns/topics:
  - Conversion of recursive algorithms to iterative algorithms.
    - [Tower of Hanoi](/docs/PROBLEMS.md#my-medium-3)
    - [Binary Tree Operations](/docs/PROBLEMS.md#my-easy-5)
    - [Letter Combinations of a Phone Number](/docs/PROBLEMS.md#lc-medium-15)
  - Various sorting algorithms.
    - [Sorting (I)](/docs/PROBLEMS.md#my-easy-2)
    - [Sorting (II)](/docs/PROBLEMS.md#my-medium-2)
  - Search/selection algorithms.
    - [Simple Binary Search](/docs/PROBLEMS.md#my-easy-3)
    - [Ship Packages Within D Days](/docs/PROBLEMS.md#lc-medium-8)
    - [Quickselect](/docs/PROBLEMS.md#my-medium-4)
  - Backtracking.
    - [N-Queens](/docs/PROBLEMS.md#lc-hard-6)
  - Binary heap buildout.
    - [Sorting (II)](/docs/PROBLEMS.md#my-medium-2) (heap sort)
    - [Generic Min-K Values](/docs/PROBLEMS.md#my-hard-2)
  - Matrix operations (multiplication, rotation, transposition, ...).
    - [Matrix Rotation](/docs/PROBLEMS.md#my-medium-1)
  - Linked list operations.
    - [Merge Two Sorted Lists](/docs/PROBLEMS.md#lc-easy-2)
    - [Floyd's Cycle Detection](/docs/PROBLEMS.md#my-easy-4)
    - [Add Two Numbers](/docs/PROBLEMS.md#lc-medium-1)
    - [Merge k Sorted Lists](/docs/PROBLEMS.md#lc-hard-2)
    - [List Clone With A Random Pointer](/docs/PROBLEMS.md#lc-medium-10)
    - [Reverse Nodes in k-Groups](/docs/PROBLEMS.md#lc-hard-4)
  - Problems dealing with strings.
    - [Valid Brackets](/docs/PROBLEMS.md#lc-easy-3)
    - [Simplify Path](/docs/PROBLEMS.md#lc-medium-7)
    - [Reverse Words](/docs/PROBLEMS.md#lc-medium-13)
    - [Longest Palindrome](/docs/PROBLEMS.md#lc-medium-11)
  - Binary tree operations (traversal, lookup, inversion, ...).
    - [Binary Tree Operations](/docs/PROBLEMS.md#my-easy-5)
  - Graphs - DFS, BFS, Dijkstra and topological sorting (Kahn).
    - [Dijkstra and Kahn](/docs/PROBLEMS.md#my-hard-1)
  - Trie tree/map problems.
    - [Longest Word in Dictionary](/docs/PROBLEMS.md#lc-medium-18)
  - Matrix/grid operations ("island" search).
    - [Island Perimeter](/docs/PROBLEMS.md#lc-easy-5)
    - [Number of Islands](/docs/PROBLEMS.md#lc-medium-16)
    - [Max Area of Island](/docs/PROBLEMS.md#lc-medium-17)
  - Dynamic programming.
    - [Longest Palindrome](/docs/PROBLEMS.md#lc-medium-11)
    - [Longest Common Subsequence](/docs/PROBLEMS.md#lc-medium-12)
  - Greedy algorithms.
    - [Candy](/docs/PROBLEMS.md#lc-hard-7)
  - Divide-and-conquer algorithms.
    - [Merge k Sorted Lists](/docs/PROBLEMS.md#lc-hard-2)
    - [Median of Two Sorted Arrays](/docs/PROBLEMS.md#lc-hard-5)
- Side Task #1 - C++
  - Go over syntax to catch up on forgotten details.
  - Research most commonly used APIs and data structures from STL.
  - Review the C++ concurrency model.
  - Review C++ I/O (stream) APIs.
  - Review C++ functional programming model.
- Side Task #2 - Explore other common patterns:
  - Two heaps - use two heaps to track median or balance elements in a stream.
  - Sliding window median - calculate median in a sliding window.
  - Scheduling - manage tasks or intervals using a heap for efficient scheduling.
