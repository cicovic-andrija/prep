// #lc-medium-17

#include "markers.h"

#include <algorithm>
#include <vector>
using std::vector;

// Passed 728 test cases on LC.
int max_area_of_island(vector<vector<int>>& grid);

int main()
{
    __BEGIN

    vector<vector<int>> grid = {
        { 1, 1, 0, 0, 0 },
        { 1, 1, 0, 0, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 0, 1, 1 },
    };

    std::cout << max_area_of_island(grid) << std::endl;

    __END
}

int explore_island(int row, int col, int m, int n, vector<vector<int>>& grid)
{
    if (row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == 0) return 0;

    // mark this cell (island of 1x1) as visited
    grid[row][col] = 0;

    return 1
        + explore_island(row-1, col, m, n, grid)
        + explore_island(row, col-1, m, n, grid)
        + explore_island(row+1, col, m, n, grid)
        + explore_island(row, col+1, m, n, grid);
}

// assumes that grid can be modified
int max_area_of_island(vector<vector<int>>& grid)
{
    if (grid.empty()) return 0;
    int m = grid.size();
    if (grid[0].empty()) return 0;
    int n = grid[0].size();

    int max_area = 0;
    for (int i = 0; i < m*n; ++i) {
        int row = i / n, col = i % n;
        if (grid[row][col] == '0') continue;
        int area = explore_island(row, col, m, n, grid);
        max_area = std::max(area, max_area);
    }

    return max_area;
}
