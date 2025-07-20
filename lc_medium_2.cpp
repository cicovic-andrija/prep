// #lc-medium-2

#include "markers.h"

// Passed 500 test cases on LC.
int run(int n);
int run_faster(int n);

int main()
{
    __BEGIN

    std::cout << run_faster(3) << std::endl; // 0
    std::cout << run_faster(5) << std::endl; // 1
    std::cout << run_faster(0) << std::endl; // 0
    std::cout << run_faster(14) << std::endl; // 2
    std::cout << run_faster(7) << std::endl; // 1
    std::cout << run_faster(20) << std::endl; // 4
    std::cout << run_faster(-1) << std::endl; // 0
    std::cout << run_faster(30) << std::endl; // 7

    __END
}

int run_faster(int n)
{
    int trailing_zeroes = 0;

    // 5, 25, 125 (each power contributes an additional 0).
    for (int i = 5; n / i; i *= 5) {
        trailing_zeroes += n / i;
    }

    return trailing_zeroes;
}

int run(int n)
{
    int trailing_zeroes = 0;
    while (n > 0) {
        if (n % 5 == 0) {
            int k = n;
            while (k % 5 == 0) {
                ++trailing_zeroes;
                k /= 5;
            }
        }
        --n;
    }
    return trailing_zeroes;
}
