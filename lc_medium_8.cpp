// #lc-medium-8

#include "markers.h"

#include <vector>

// Passed 88 test cases on LC.
int ship_within_days(std::vector<int> &&weights, int days);

int main()
{
    __BEGIN

    std::cout << ship_within_days({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 5) << std::endl;
    std::cout << ship_within_days({3, 2, 2, 4, 1, 4}, 3) << std::endl;

    __END
}

bool test_capacity(const std::vector<int> &weights, int capacity, int days)
{
    int n = weights.size(), i = 0, cap_left = capacity;
    while (days > 0 && i < n)
    {
        if (weights[i] > capacity) return false; // minor optimization

        if (weights[i] <= cap_left) {
            cap_left -= weights[i];
            ++i;
        } else {
            --days;
            cap_left = capacity;
        }
    }
    return days > 0;
}

int ship_within_days(std::vector<int> &&weights, int days)
{
    // 1 - find any suitable capacity
    int capacity = 0, i = 0, prev_tried_cap;
    do {
        prev_tried_cap = capacity; // capacity is always > prev_tried_cap
        capacity += weights[i++]; // just one possible strategy for trying out different caps
    } while (!test_capacity(weights, capacity, days));

    // 2 - find the minimum suitable capacity
    // a binary search between prev_tried_cap and capacity
    while (prev_tried_cap < capacity)
    {
        int mid = prev_tried_cap + (capacity - prev_tried_cap) / 2;
        if (!test_capacity(weights, mid, days)) {
            prev_tried_cap = mid + 1; // needs +1 for algorithm to end
        } else {                      // can also introduce low and high vars for less confusion
            capacity = mid;
        }
    }

    return capacity;
}
