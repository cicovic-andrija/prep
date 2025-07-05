// #lc-easy-1

#include "markers.h"

#include <vector>
#include <utility>
#include <unordered_map>

// Passed 63 test cases on LC.
std::pair<int, int> run_brute_force(std::vector<int> arr, int target);
std::pair<int, int> run_map(std::vector<int> arr, int target);

int main()
{
    __BEGIN

    auto result = run_brute_force({2, 7, 11, 15}, 9);
    std::cout << "(" << result.first << ", " << result.second << ")" << std::endl;

    result = run_map({2, 7, 11, 15}, 9);
    std::cout << "(" << result.first << ", " << result.second << ")" << std::endl;

    result = run_map({3, 2, 4}, 6);
    std::cout << "(" << result.first << ", " << result.second << ")" << std::endl;

    result = run_map({3, 3}, 6);
    std::cout << "(" << result.first << ", " << result.second << ")" << std::endl;

    result = run_map({1, 3}, 6);
    std::cout << "(" << result.first << ", " << result.second << ")" << std::endl;

    __END
}

constexpr std::pair<int, int> not_found()
{
    return std::make_pair(-1, -1);
}

// O(n^2)
std::pair<int, int> run_brute_force(std::vector<int> arr, int target)
{
    int n = arr.size();
    if (n < 2)
        return not_found();

    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (arr[i] + arr[j] == target)
                return std::make_pair(i, j);

    return not_found();
}

// O(n)
std::pair<int, int> run_map(std::vector<int> arr, int target)
{
    int n = arr.size();
    if (n < 2)
        return not_found();

    std::unordered_map<int, int> complements = {
        {target - arr[0], 0},
    };

    decltype(complements)::iterator result;
    for (int i = 1; i < n; ++i)
        if ((result = complements.find(arr[i])) != complements.end())
            return std::make_pair(result->second, i);
        else
            complements[target - arr[i]] = i;

    return not_found();
}
