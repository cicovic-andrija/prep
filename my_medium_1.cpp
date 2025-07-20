// #my-medium-1

#include "markers.h"
#include "matrix.h"

#include <algorithm>
#include <utility>

using IntMatrix = std::vector<std::vector<int>>;

// Assume matrix is NxN.
void rotate_clockwise(IntMatrix &m);

// Assume matrix is NxN.
void rotate_counter_clockwise(IntMatrix &m);

int main()
{
    __BEGIN

    IntMatrix m = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    print_matrix(m);
    std::cout << "------" << std::endl;
    rotate_clockwise(m);
    print_matrix(m);
    std::cout << "------" << std::endl;
    rotate_counter_clockwise(m);
    rotate_counter_clockwise(m);
    print_matrix(m);

    __END
}

void revers_rows(IntMatrix &m) {
    for (auto& row : m) {
        std::reverse(row.begin(), row.end());
    }
}

void rotate_clockwise(IntMatrix &m)
{
    int n = m.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            std::swap(m[i][j], m[j][i]);
        }
    }

    revers_rows(m);
}

void rotate_counter_clockwise(IntMatrix &m)
{
    int n = m.size();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            std::swap(m[i][j], m[n-1-j][n-1-i]);
        }
    }

    revers_rows(m);
}
