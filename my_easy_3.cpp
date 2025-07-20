// #my-easy-3

#include "markers.h"

#include <algorithm>
#include <vector>

bool binary_search(std::vector<int> &&arr, int key);

int main()
{
    __BEGIN

    std::cout << binary_search({3, 7, -1, 0, 15, 22, 8, 6, 11, -4}, 15) << std::endl; // true
    std::cout << binary_search({25, 30, -5, -15, -10, 15, 20, 0, 5, 10}, -10) << std::endl; // true
    std::cout << binary_search({1, 11, 5, 19, 3, 17, 13, 9, 15, 7}, 4) << std::endl; // false
    std::cout << binary_search({6, 12, 18, 4, 2, 14, 10, 20, 8, 16}, 16) << std::endl; // true
    std::cout << binary_search({-10, -100, -20, -90, -60, -40, -30, -70, -50, -80}, -60) << std::endl; // true
    std::cout << binary_search({42}, 42) << std::endl; // true
    std::cout << binary_search({}, -60) << std::endl; // false

    __END
}

bool binary_search(std::vector<int> &&arr, int key)
{
    std::sort(arr.begin(), arr.end());
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return true;
        }
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}
