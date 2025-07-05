// #lc-hard-3

#include "markers.h"

#include <vector>

// Passed 99 test cases on LC.
int largest_rectangle(std::vector<int> &heights);
int largest_rectangle(std::vector<int> &&heights) { return largest_rectangle(heights); }

int main()
{
    __BEGIN

    std::cout << largest_rectangle({2, 1, 5, 6, 2, 3}) << std::endl; // 10
    std::cout << largest_rectangle({2, 4}) << std::endl; // 4
    std::cout << largest_rectangle({4, 2, 0, 3, 2, 5}) << std::endl; // 6

    __END
}

int largest_rectangle(std::vector<int> &heights)
{
    int max_area = 0;
    int n = heights.size();
    int prev_height = 0;
    for (int i = 0; i < n; ++i, prev_height = heights[i-1])
    {
        int rec_h = heights[i];
        while (rec_h)
        {
            if (prev_height >= rec_h) break;

            int j = i + 1;
            while (j < n && heights[j] >= rec_h) {
                ++j;
            }

            std::cout << "starting from i=" << i << " found rectangle " << j-i << "x" << rec_h << std::endl;
            if ((j-i) * rec_h > max_area) {
                max_area = (j-i) * rec_h;
            }

            rec_h = (j == n || rec_h == 1) ? 0 : heights[j];
        }
    }

    return max_area;
}
