// #my-easy-6

#include "markers.h"
#include "matrix.h"

#include <algorithm>
#include <vector>

std::vector<std::vector<int>> matmul(const std::vector<std::vector<int>>& matrix_a, const std::vector<std::vector<int>>& matrix_b);

int main()
{
    __BEGIN

    // 5x4
    std::vector<std::vector<int>> matrix_a = {
        {3, 7, 1, 4},
        {8, 2, 6, 0},
        {5, 9, 3, 7},
        {4, 1, 8, 2},
        {6, 0, 5, 9}
    };
    print_matrix(matrix_a);

    std::cout << "---" << std::endl;

    // 4x3
    std::vector<std::vector<int>> matrix_b = {
        {2, 8, 5},
        {9, 1, 4},
        {7, 6, 0},
        {3, 2, 9}
    };
    print_matrix(matrix_b);

    std::cout << "---" << std::endl;

    print_matrix(matmul(matrix_a, matrix_b));

    __END
}

std::vector<std::vector<int>> matmul(const std::vector<std::vector<int>>& matrix_a, const std::vector<std::vector<int>>& matrix_b)
{
    if (matrix_a.empty()) return {};
    int m_a = matrix_a.size();
    if (matrix_a[0].empty()) return {};
    int k = matrix_a[0].size();
    if (matrix_b.empty() || static_cast<int>(matrix_b.size()) != k) return {};
    if (matrix_b[0].empty()) return {};
    int n_b = matrix_b[0].size();

    std::vector<std::vector<int>> matrix_c(m_a, std::vector<int>(n_b));

    for (int i = 0; i < m_a; ++i)
    {
        for (int j = 0; j < n_b; ++j)
        {
            int dot_product = 0;
            for (int t = 0; t < k; ++t)
            {
                dot_product += matrix_a[i][t] * matrix_b[t][j];
            }
            matrix_c[i][j] = dot_product;
        }
    }

    return matrix_c;
}
