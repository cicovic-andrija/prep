// #lc-easy-4

#include "markers.h"

// Passed 1013 test cases on LC.
bool is_ugly(int n);

int main()
{
    __BEGIN

    std::cout << is_ugly(6) << std::endl; // true
    std::cout << is_ugly(1) << std::endl; // true
    std::cout << is_ugly(14) << std::endl; // false
    std::cout << is_ugly(0) << std::endl; // false
    std::cout << is_ugly(-1) << std::endl; // false

    __END
}

bool is_ugly(int n)
{
    if (n < 1) return false;

    while ((n & 0x1) == 0) n >>= 1; // while (n % 2 == 0) n /= 2;
    while (n % 3 == 0) n /= 3;
    while (n % 5 == 0) n /= 5;

    return n == 1;
}
