// #my-medium-2

#include "markers.h"
#include "vect.h"

std::vector<int>&& quick_sort(std::vector<int> &&v);
std::vector<int>&& heap_sort(std::vector<int> &&v);
void test_all(std::vector<int>&& (*sort_func)(std::vector<int> &&));

int main()
{
    __BEGIN

    // alt to below: decltype(&quick_sort) all_sort_funcs[] = { quick_sort, heap_sort };
    std::vector<int>&& (*all_sort_funcs[])(std::vector<int> &&) = { quick_sort, heap_sort };
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

// O(Nlog(N))
// pivot is the middle element
std::vector<int>&& quick_sort(std::vector<int> &&v)
{
    void quick_sort_internal(std::vector<int> &, int low, int high);

    quick_sort_internal(v, 0, static_cast<int>(v.size()) - 1);
    return std::move(v);
}

void quick_sort_internal(std::vector<int> &v, int low, int high)
{
    int partition(std::vector<int> &, int low, int high);

    if (low < high) {
        int pi = partition(v, low, high);
        quick_sort_internal(v, low, pi - 1);
        quick_sort_internal(v, pi + 1, high);
    }
}

int partition(std::vector<int> &part, int low, int high)
{
    int mid = low + (high - low) / 2;
    int pivot = part[mid];

    // temporarily move pivot to the end
    std::swap(part[mid], part[high]);

    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (part[j] < pivot) {
            ++i;
            std::swap(part[i], part[j]);
        }
    }

    // swap pivot back to the pivot position
    // small optimization - avoid the swap in case pivot is the largest element
    if (i + 1 != high)
    {
        std::swap(part[i + 1], part[high]);
    }

    return i + 1;
}

std::vector<int>&& heap_sort(std::vector<int> &&v)
{
    void heapify(std::vector<int> &, int size, int root);

    int n = v.size();

    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(v, n, i);
    }

    for (int i = n - 1; i > 0; --i) {
        std::swap(v[0], v[i]);

        // the swap disturbed the heap
        // propagate the value at [0] to its correct place
        // (fix the heap, which is now of size i)
        heapify(v, i, 0);
    }

    return std::move(v);
}

// builds the max-heap
void heapify(std::vector<int> &v, int n, int i)
{
    int root = i;
    int left = 2 * i + 1;
    int right = left + 1;

    if (left < n && v[left] > v[root]) {
        root = left;
    }

    if (right < n && v[right] > v[root]) {
        root = right;
    }

    if (root != i) {
        std::swap(v[root], v[i]);
        heapify(v, n, root);
    }
}
