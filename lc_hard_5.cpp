// #lc-hard-5

#include "markers.h"

#include <algorithm>
#include <vector>
#include <stdexcept>
#include <limits>

constexpr int pos_infinity = std::numeric_limits<int>::max();
constexpr int neg_infinity = std::numeric_limits<int>::min();

// Looked up the solution online. This is O(log(m+n))??
double two_sorted_arrays_median(const std::vector<int> &nums1, const std::vector<int> &nums2);

// Passed 2096 test cases on LC.
// O((m+n)/2)
double two_sorted_arrays_median_simple(const std::vector<int> &nums1, const std::vector<int> &nums2);

int main()
{
    __BEGIN

    std::vector<int> nums1 = { 1, 2 };
    std::vector<int> nums2 = { 3, 4 };

    std::cout << two_sorted_arrays_median(nums1, nums2) << std::endl;
    std::cout << two_sorted_arrays_median_simple(nums1, nums2) << std::endl;

    __END
}

double two_sorted_arrays_median_simple(const std::vector<int> &nums1, const std::vector<int> &nums2)
{
    double median(const std::vector<int> &);

    int n1 = nums1.size();
    int n2 = nums2.size();

    if (n1 == 0) return median(nums2);
    if (n2 == 0) return median(nums1);

    int curr, prev;
    for (int i1 = 0, i2 = 0, i = 0; i <= (n1 + n2) / 2; ++i) {
        prev = curr;
        if (i1 == n1) curr = nums2[i2++];
        else if (i2 == n2) curr = nums1[i1++];
        else if (nums1[i1] < nums2[i2]) curr = nums1[i1++];
        else curr = nums2[i2++];
    }

    return ((n1 + n2) & 1) ? curr : (curr + prev) / 2.0;
}

double two_sorted_arrays_median(const std::vector<int> &nums1, const std::vector<int> &nums2)
{
    double median(const std::vector<int> &);

    int n1 = nums1.size();
    int n2 = nums2.size();

    if (n1 == 0) return median(nums2);
    if (n2 == 0) return median(nums1);
    if (n1 > n2) return two_sorted_arrays_median(nums2, nums1); // make sure nums1 is smaller

    int n = n1 + n2;
    int left = (n1 + n2 + 1) / 2; // left part of the combined array
    int low = 0, high = n1;
    while (low <= high) {
        int mid1 = (low + high) / 2; // cut nums1 in half
        int mid2 = left - mid1; // cut nums2 so left part is complement to left part of nums1
        int l1 = neg_infinity, l2 = neg_infinity, r1 = pos_infinity, r2 = pos_infinity;

        if (mid1 < n1) r1 = nums1[mid1];
        if (mid2 < n2) r2 = nums2[mid2];
        if (mid1 - 1 >= 0) l1 = nums1[mid1-1];
        if (mid2 - 1 >= 0) l2 = nums2[mid2-1];

        if (l1 <= r2 && l2 <= r1) {
            // two arrays are now correctly partitioned
            if (n & 1) {
                return std::max(l1, l2);
            } else {
                return (std::max(l1, l2) + std::min(r1, r2)) / 2.0;
            }
        }
        else if (l1 > r2) {
            high = mid1 - 1; // move towards left side of nums1
        } else {
            low = mid1 + 1; // move towards right side of nums1
        }
    }

    throw std::invalid_argument("vector were not sorted");
}

double median(const std::vector<int> &v)
{
    int n = v.size();
    if (n == 0) throw std::invalid_argument("vector cannot be empty");
    if (n & 1) return v[n/2];
    return (v[n/2] + v[n/2-1]) / 2;
}
