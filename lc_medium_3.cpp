// #lc-medium-3

#include "markers.h"

#include <algorithm>
#include <vector>

// Passed 596 test cases on LC.
int nth_ugly_num(int n);

int main()
{
    __BEGIN

    std::cout << nth_ugly_num(10) << std::endl;
    std::cout << nth_ugly_num(1) << std::endl;

    __END
}

int nth_ugly_num(int n)
{
    if (n < 1) return 0;
    if (n == 1) return 1;

    int f2 = 0, f3 = 0, f5 = 0;
    std::vector<int> ugly_numbers(n);
    ugly_numbers[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        ugly_numbers[i] = std::min<int>(ugly_numbers[f2] * 2, std::min<int>(ugly_numbers[f3] * 3, ugly_numbers[f5] * 5));
        if (ugly_numbers[i] == ugly_numbers[f2] * 2) ++f2;
        if (ugly_numbers[i] == ugly_numbers[f3] * 3) ++f3;
        if (ugly_numbers[i] == ugly_numbers[f5] * 5) ++f5;
    }

    return ugly_numbers[n-1];
}
