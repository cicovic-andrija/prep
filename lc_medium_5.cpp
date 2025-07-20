// #lc-medium-5

#include "markers.h"
#include "vect.h"

#include <utility>

// Passed 89 test cases on LC.
void sort_colors(std::vector<int> &nums);

int main()
{
    __BEGIN

    std::vector<int> colors = {2, 0, 2, 1, 1, 0};
    sort_colors(colors);
    print_vec(colors);

    colors = {1};
    sort_colors(colors);
    print_vec(colors);

    colors = {0, 2, 0, 2, 0, 2, 0};
    sort_colors(colors);
    print_vec(colors);

    __END
}

// The Dutch National Flag algorithm.
void sort_colors(std::vector<int> &nums)
{
    if (nums.empty()) return;

    int low = 0;
    int high = nums.size() - 1;
    int curr = low;
    while (curr <= high) {
        if (nums[curr] == 0) {
            std::swap(nums[curr++], nums[low++]);
        } else if (nums[curr] == 2) {
            std::swap(nums[curr], nums[high--]);
        } else { // 1
            ++curr;
        }
    }
}
