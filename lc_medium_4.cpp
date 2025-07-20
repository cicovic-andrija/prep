// #lc-medium-4

#include "markers.h"

#include <algorithm>
#include <vector>

// Passed 966 test cases on LC.
int run(std::vector<std::vector<int>> points, int w);

int main()
{
    __BEGIN

    std::cout << run({{2, 1}, {1, 0}, {1, 4}, {1, 8}, {3, 5}, {4, 6}}, 1) << std::endl; // 2
    std::cout << run({{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}}, 2) << std::endl; // 3
    std::cout << run({{2, 3}, {1, 2}}, 0) << std::endl; // 2

    __END
}

int run(std::vector<std::vector<int>> points, int w)
{
    if (points.size() < 1 || w < 0) return 0;

    std::sort(
        points.begin(),
        points.end(),
        [](const std::vector<int> &v1, const std::vector<int> &v2){ return v1[0] < v2[0]; }
    );

    int n = 1;
    int end = points[0][0] + w;
    for (std::size_t i = 1; i < points.size(); ++i) {
        if (points[i][0] <= end) continue;
        ++n;
        end = points[i][0] + w;
    }

    return n;
}
