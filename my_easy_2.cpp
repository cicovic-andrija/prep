// #my-easy-2

#include <utility>

#include "markers.h"
#include "vect.h"

std::vector<int>&& selection_sort(std::vector<int> &&v);
std::vector<int>&& insertion_sort(std::vector<int> &&v);
std::vector<int>&& bubble_sort(std::vector<int> &&v);
void test_all(std::vector<int>&& (*sort_func)(std::vector<int> &&));

int main()
{
    __BEGIN

    // alt to below: decltype(&selection_sort) all_sort_funcs[] = { selection_sort, insertion_sort, bubble_sort };
    std::vector<int>&& (*all_sort_funcs[])(std::vector<int> &&) = { selection_sort, insertion_sort, bubble_sort };
    for (auto func : all_sort_funcs)
    {
        test_all(func);
        std::cout << "---" << std::endl;
    }

    __END
}

void test_all(std::vector<int>&& (*sort_func)(std::vector<int> &&))
{
    print_vec<int>(sort_func({ 23, -45, 67, 89, -10, 3, 0, -99, 56, 72, -33, 18, -5, 42, 90 }));
    print_vec<int>(sort_func({ -76, 54, 11, 8, -25, 0, 100, -100, 37, -1, 2, 66, -8, 91, -42 }));
    print_vec<int>(sort_func({ 45, -17, -39, 3, 88, 27, -60, 74, -84, 59, 14, -20, 6, 0, -2 }));
    print_vec<int>(sort_func({ -3, 19, -47, 33, 71, -99, 65, -21, 22, 84, -12, 7, 46, -64, 9 }));
    print_vec(sort_func({ 13, -57, 49, -40, 76, -6, 32, -18, 4, 80, -77, 95, -9, 25, 1 }));
    print_vec(sort_func({ 42 }));
    print_vec(sort_func({}));
}

std::vector<int>&& selection_sort(std::vector<int> &&v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        if (min != i) {
            std::swap(v[i], v[min]);
        }
    }

    return std::move(v);
}

std::vector<int>&& insertion_sort(std::vector<int> &&v)
{
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        int j = i - 1;
        int val = v[i];
        while (j >= 0 && v[j] > val) {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = val;
    }

    return std::move(v);
}

std::vector<int>&& bubble_sort(std::vector<int> &&v)
{
    int n = v.size();
    bool swapped = false;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (v[j + 1] < v[j]) {
                std::swap(v[j + 1], v[j]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    return std::move(v);
}
