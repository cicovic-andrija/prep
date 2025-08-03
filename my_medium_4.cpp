// #my-medium-4

#include "markers.h"

#include <algorithm>
#include <vector>
using std::vector;

int quickselect(vector<int> &v, int low, int high, int target_index);
int kth_smallest(vector<int>& v, int k);
int kth_largest(vector<int>& v, int k);

int main()
{
    __BEGIN

    vector<int> v = { 7, 10, 4, 3, 20, 15, 88 };
    std::cout << kth_smallest(v, 3) << std::endl;
    std::cout << kth_largest(v, 1) << std::endl;

    __END
}

int quickselect(vector<int> &v, int low, int high, int target_index)
{
    int partition(vector<int> &v, int low, int high);

    if (low == high) return v[low];

    int pivot = partition(v, low, high);
    if (pivot == target_index)
        return v[target_index];
    if (pivot < target_index)
        return quickselect(v, pivot+1, high, target_index);
    else
        return quickselect(v, low, pivot-1, target_index);
}

int partition(vector<int> &v, int low, int high)
{
    int mid = low + (high - low) / 2;
    int pivot_val = v[mid];

    // temporarily swap pivot value to the end
    std::swap(v[mid], v[high]);
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (v[j] < pivot_val) {
            ++i;
            std::swap(v[i], v[j]);
        }
    }
    if (i + 1 != high) {
        std::swap(v[i+1], v[high]); // swap back
    }
    return i+1;
}

int kth_smallest(vector<int>& v, int k)
{
    int n = v.size();
    if (k > n || k < 1) return -1;
    return quickselect(v, 0, n-1, k-1);
}

int kth_largest(vector<int>& v, int k)
{
    int n = v.size();
    if (k > n || k < 1) return -1;
    return quickselect(v, 0, n-1, n-k);
}
