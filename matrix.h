#ifndef PREP_MATRIX_H
#define PREP_MATRIX_H

#include <iostream>
#include <vector>

template <typename T>
void print_matrix(const std::vector<std::vector<T>> &matrix)
{
    for (const std::vector<T> &row : matrix) {
        for (const T &col : row) {
            std::cout << col << "\t";
        }
        std::cout << std::endl;
    }
}

#endif // PREP_MATRIX_H
