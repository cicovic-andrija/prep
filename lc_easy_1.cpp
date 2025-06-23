// LEETCODE.md#lc-easy-1

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

static std::pair<int, int> run_brute_force(std::vector<int> arr, int target);
static std::pair<int, int> run_map(std::vector<int> arr, int target);

int main()
{
    std::cout << "__begin_main" << std::endl;

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

    std::cout << "__end_main" << std::endl;
    return 0;
}

static constexpr std::pair<int, int> not_found()
{
    return std::make_pair(-1, -1);
}

// O(n^2)
static std::pair<int, int> run_brute_force(std::vector<int> arr, int target)
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
static std::pair<int, int> run_map(std::vector<int> arr, int target)
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
