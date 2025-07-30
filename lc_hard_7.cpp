// #lc-hard-7

#include "markers.h"

#include <algorithm>
#include <vector>
using std::vector;

// Passed 49 test cases on LC.
int allocate_candy_optimized(vector<int> &&ratings);
int allocate_candy_slightly_optimized(vector<int> &&ratings);
int allocate_candy_brute_force(vector<int> &&ratings);

int main()
{
    __BEGIN

    std::cout << allocate_candy_brute_force({ 1, 0, 2 }) << std::endl; // 5
    std::cout << allocate_candy_brute_force({ 1, 2, 2 }) << std::endl; // 4
    std::cout << allocate_candy_slightly_optimized({ 1, 3, 2, 2, 1 }) << std::endl; // 7
    std::cout << allocate_candy_slightly_optimized({ 1, 2, 87, 87, 87, 2, 1 }) << std::endl; // 13
    std::cout << allocate_candy_slightly_optimized({ 1, 6, 10, 8, 7, 3, 2 }) << std::endl; // 18
    std::cout << allocate_candy_optimized({ 0, 1, 2, 5, 3, 2, 7 }) << std::endl; // 15
    std::cout << allocate_candy_optimized({ 1, 2, 3, 4, 2, 1 }) << std::endl; // 13

    __END
}

int allocate_candy_optimized(vector<int> &&ratings)
{
    int n = ratings.size();
    if (n < 2) return n;

    int candy = n, i = 1;
    while (i < n) {
        if (ratings[i] == ratings[i-1]) {
            ++i;
            continue;
        }

        int peak = 0; // "ascending"
        while (ratings[i] > ratings[i-1]) {
            ++peak;
            candy += peak;
            ++i;
            if (i == n) return candy;
        }

        int valley = 0; // "descending"
        while (i < n && ratings[i] < ratings[i-1]) {
            ++valley;
            candy += valley;
            ++i;
        }
        candy -= std::min(peak, valley);
    }

    return candy;
}

int allocate_candy_slightly_optimized(vector<int> &&ratings)
{
    int n = ratings.size();
    vector<int> candy(n, 0);

    auto left_rating = [&ratings](int i) -> int {
        return i == 0 ? ratings[0] : ratings[i-1];
    };
    auto right_rating = [&ratings, n](int i) -> int {
        return i == n - 1 ? ratings[n-1] : ratings[i+1];
    };

    int children_left = n;
    for (int i = 0; i < n; ++i) {
        if (ratings[i] <= left_rating(i) && ratings[i] <= right_rating(i)) {
            candy[i] = 1;
            --children_left;
        }
    }

    while (children_left) {
        for (int i = 0; i < n; ++i) {
            if (candy[i]) continue;
            if (ratings[i] > left_rating(i) && ratings[i] > right_rating(i)) {
                if (candy[i-1] && candy[i+1]) {
                    candy[i] = std::max(candy[i-1], candy[i+1]) + 1;
                    --children_left;
                }
            }
            else if (ratings[i] > left_rating(i)) {
                if (candy[i-1]) {
                    candy[i] = candy[i-1] + 1;
                    --children_left;
                }
            }
            else if (ratings[i] > right_rating(i)) {
                if (candy[i+1] > 0) {
                    candy[i] = candy[i+1] + 1;
                    --children_left;
                }
            }
        }
    }

    int total_min = 0;
    std::for_each(candy.begin(), candy.end(), [&total_min](int num){ total_min += num; });
    return total_min;
}

int allocate_candy_brute_force(vector<int> &&ratings)
{
    int n = ratings.size();
    auto left_rating = [&ratings](int i) -> int {
        return i == 0 ? ratings[0] : ratings[i-1];
    };
    auto right_rating = [&ratings, n](int i) -> int {
        return i == n - 1 ? ratings[n-1] : ratings[i+1];
    };

    vector<int> candy(n, 1);
    bool one_more = true;
    while (one_more) {
        one_more = false;
        for (int i = 0; i < n; ++i) {
            if (ratings[i] > left_rating(i) && ratings[i] > right_rating(i)) {
                candy[i] = std::max(candy[i-1], candy[i+1]) + 1;
            } else if (ratings[i] > left_rating(i) && !(candy[i] > candy[i-1])) {
                candy[i] = candy[i-1] + 1;
                one_more = true;
            } else if (ratings[i] > right_rating(i) && !(candy[i] > candy[i+1])) {
                candy[i] = candy[i+1] + 1;
                one_more = true;
            }
        }
    }

    int total_min = 0;
    std::for_each(candy.begin(), candy.end(), [&total_min](int num){ total_min += num; });
    return total_min;
}
