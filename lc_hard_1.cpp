// #lc-hard-1

#include "markers.h"

#include <vector>
#include <utility>

// Passed 324 test cases on LC.
int run(std::vector<int> arr);

int main()
{
    __BEGIN

    std::cout << "result: " << run({0, 0, 0}) << std::endl; // 0
    std::cout << "result: " << run({0, 1, 0}) << std::endl; // 0
    std::cout << "result: " << run({}) << std::endl; // 0
    std::cout << "result: " << run({2, 3, 4, 7}) << std::endl; // 0
    std::cout << "result: " << run({7, 5, 2, 0, 0}) << std::endl; // 0

    //        X
    //    X   XX X
    // _X_XX_XXXXXX
    std::cout << "result: " << run({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}) << std::endl; // 6


    //         X X
    //        XX XX
    //       XXX XX
    //      XXXX XX
    //   X  XXXX XX
    // _XX_XXXXX_XXX
    std::cout << "result: " << run({0, 1, 2, 0, 1, 3, 4, 5, 6, 0, 6, 5, 1}) << std::endl; // 9

    // X_XX
    std::cout << "result: " << run({1, 0, 1, 1}) << std::endl; // 1

    // XX_X
    std::cout << "result: " << run({1, 1, 0, 1}) << std::endl; // 1

    // X    X X
    // X  X XXX
    // XX XXXXX
    // XX_XXXXX
    std::cout << "result: " << run ({4, 2, 0, 3, 2, 4, 3, 4}) << std::endl; // 10

    __END
}

bool find_next_local_maximum(const std::vector<int> &arr, int &pos, int &height, const int start = 0)
{
    for (std::vector<int>::size_type i = start; i < arr.size(); ++i) {
        if ((i == 0 || arr[i-1] <= arr[i]) && (i == arr.size()-1 || arr[i+1] < arr[i])) {
            pos = i;
            height = arr[i];
            std::cout << "local max: pos " << pos << " height " << height << std::endl;
            return true;
        }
    }
    return false;
}

int run(std::vector<int> arr)
{
    int left_local_max, right_local_max;
    int left_height, right_height;
    int total = 0;
    int prev_total = 0;

    while (find_next_local_maximum(arr, left_local_max, left_height)) {
        prev_total = total;
        while (find_next_local_maximum(arr, right_local_max, right_height, left_local_max+1)) {
            int trapped_max = left_height < right_height ? left_height : right_height;
            for (int i = left_local_max + 1; i < right_local_max; ++i) {
                if (arr[i] < trapped_max) {
                    total += trapped_max - arr[i];
                    arr[i] = trapped_max;
                }
            }
            left_local_max = right_local_max;
            left_height = right_height;
        }
        if (total == prev_total) {
            break;
        }
        // for (int i = 0; i < arr.size(); ++i) {
        //     std::cout << arr[i] << " ";
        // }
        // std::cout << std::endl;
    }

    return total;
}
