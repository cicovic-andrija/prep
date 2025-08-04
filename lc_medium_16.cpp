// #lc-medium-16

#include "markers.h"

#include <algorithm>
#include <memory> // std::hash
#include <unordered_set>
#include <stack>
#include <functional>
#include <vector>
using std::vector;

// Passed 49 test cases on LC.
int num_islands(vector<vector<char>>& grid);

int main()
{
    __BEGIN

    vector<vector<char>> grid_1 = {
        { '1', '1', '1', '1', '0' },
        { '1', '1', '0', '1', '1' },
        { '1', '1', '0', '0', '0' },
        { '0', '0', '0', '0', '0' },
    };

    vector<vector<char>> grid_2 = {
        { '1', '1', '0', '0', '0' },
        { '1', '1', '0', '0', '0' },
        { '0', '0', '1', '0', '0' },
        { '0', '0', '0', '1', '1' },
    };

    std::cout << num_islands(grid_1) << std::endl;
    std::cout << num_islands(grid_2) << std::endl;

    __END
}

struct pair_hash {
    template <typename T1, typename T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const {
        return std::hash<T1>()(p.first) ^ (std::hash<T2>()(p.second) << 1);
    }
};

struct pair_equal {
    template <typename T1, typename T2>
    bool operator()(const std::pair<T1, T2>& a, const std::pair<T1, T2>& b) const {
        return a.first == b.first && a.second == b.second;
    }
};

int num_islands(vector<vector<char>>& grid)
{
    if (grid.empty()) return 0;
    int m = grid.size();
    if (grid[0].empty()) return 0;
    int n = grid[0].size();

    // intentionally verbose (C++ practice)
    std::unordered_set<std::pair<int, int>, pair_hash, pair_equal> visited;
    std::function<bool(std::pair<int, int>&&)> is_visited =
        [&visited](std::pair<int, int>&& p) { return visited.find(p) != visited.end(); };

    int total = 0;
    std::stack<std::pair<int, int>> s;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '0' || is_visited({i, j})) continue;

            // explore this island
            ++total;

            int ti = i, tj = j;
            s.push({i, j});
            while (!s.empty())
            {
                i = s.top().first;
                j = s.top().second;
                s.pop();
                visited.insert({i, j});

                if (i > 0 && grid[i-1][j] == '1' && !is_visited({i-1, j})) {
                    s.push({i, j}); // need to come back to this one to explore other neighbors
                    s.push({i-1, j});
                    continue;
                }

                if (j > 0 && grid[i][j-1] == '1' && !is_visited({i, j-1})) {
                    s.push({i, j});
                    s.push({i, j-1});
                    continue;
                }

                if (i < m-1 && grid[i+1][j] == '1' && !is_visited({i+1, j})) {
                    s.push({i, j});
                    s.push({i+1, j});
                    continue;
                }

                if (j < n-1 && grid[i][j+1] == '1' && !is_visited({i, j+1})) {
                    s.push({i, j+1});
                }
            }

            i = ti;
            j = tj;
        }
    }

    return total;
}
