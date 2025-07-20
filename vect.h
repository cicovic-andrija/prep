#ifndef PREP_VECT_H
#define PREP_VECT_H

#include <vector>
#include <iostream>

template<typename T>
void print_vec(const std::vector<T> &v)
{
    for (const T& e : v)
    {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
}

#endif // PREP_VECT_H
