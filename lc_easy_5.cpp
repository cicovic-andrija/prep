// #lc-easy-5

#include "markers.h"

#include <algorithm>
#include <unordered_set>
#include <stack>
#include <vector>
using std::vector;
using std::unordered_set;
using std::stack;

// Passed 5833 test cases on LC.
int island_perimeter(vector<vector<int>>& grid);
int island_perimeter_recursive(vector<vector<int>>& grid);

int main()
{
    __BEGIN

    vector<vector<int>> grid = {
        { 0, 1, 0, 0 },
        { 1, 1, 1, 0 },
        { 0, 1, 0, 0 },
        { 1, 1, 0, 0 },
    };
    std::cout << island_perimeter_recursive(grid) << std::endl;

    grid = { { 1 } };
    std::cout << island_perimeter_recursive(grid) << std::endl;

    grid = { { 1, 1 }, { 1, 1 } };
    std::cout << island_perimeter_recursive(grid) << std::endl;

    __END
}

int recruse_island(vector<vector<int>>& grid, int m, int n, int i, int j)
{
    if (i < 0 || i > m-1 || j < 0 || j > n-1 || grid[i][j] != 1) return 0;

    int perimeter = 0;
    if (i == 0 || grid[i-1][j] == 0) ++perimeter;
    if (i == m-1 || grid[i+1][j] == 0) ++perimeter;
    if (j == 0 || grid[i][j-1] == 0) ++perimeter;
    if (j == n-1 || grid[i][j+1] == 0) ++perimeter;

    grid[i][j] = -1; // mark this cell as visited

    return perimeter
        + recruse_island(grid, m, n, i-1, j)
        + recruse_island(grid, m, n, i+1, j)
        + recruse_island(grid, m, n, i, j-1)
        + recruse_island(grid, m, n, i, j+1);
}

int island_perimeter_recursive(vector<vector<int>>& grid)
{
    int m = grid.size();
    if (m == 0) return 0;
    int n = grid[0].size();
    if (n == 0) return 0;

    for (int i = 0; i < m*n; ++i) {
        if (grid[i/n][i%n] == 1) {
            return recruse_island(grid, m, n, i/n, i%n);
        }
    }

    return 0;
}

int explore_island(vector<vector<int>>& grid, int m, int n, int row, int col)
{
    unordered_set<int> visited;
    stack<int> unvisited;
    auto is_visited = [&visited](int pos) ->bool { return visited.find(pos) != visited.end(); };
    auto encode = [n](int i, int j) ->int { return i*n + j; };
    auto decode = [n](int x, int& i, int& j) { i = x/n; j = x%n; };

    int perimeter = 0;
    unvisited.push(encode(row, col));
    while (!unvisited.empty()) {
        int x = unvisited.top();
        unvisited.pop();
        if (is_visited(x)) continue; // some cells may be added to the unvisited stack more than once
        visited.insert(x);
        int i, j;
        decode(x, i, j);
        if (i == 0 || grid[i-1][j] == 0) ++perimeter;
        if (i == m-1 || grid[i+1][j] == 0) ++perimeter;
        if (j == 0 || grid[i][j-1] == 0) ++perimeter;
        if (j == n-1 || grid[i][j+1] == 0) ++perimeter;

        if (i > 0 && grid[i-1][j] == 1 && !is_visited(encode(i-1, j))) unvisited.push(encode(i-1, j));
        if (i < m-1 && grid[i+1][j] == 1 && !is_visited(encode(i+1, j))) unvisited.push(encode(i+1, j));
        if (j > 0 && grid[i][j-1] == 1 && !is_visited(encode(i, j-1))) unvisited.push(encode(i, j-1));
        if (j < n-1 && grid[i][j+1] == 1 && !is_visited(encode(i, j+1))) unvisited.push(encode(i, j+1));
    }

    return perimeter;
}

int island_perimeter(vector<vector<int>>& grid)
{
    int m = grid.size();
    if (m == 0) return 0;
    int n = grid[0].size();
    if (n == 0) return 0;

    for (int i = 0; i < m*n; ++i) {
        if (grid[i/n][i%n] == 1) {
            return explore_island(grid, m, n, i/n, i%n);
        }
    }

    return 0;
}
