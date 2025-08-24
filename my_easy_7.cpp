// #my-easy-7

#include "markers.h"

#include <algorithm>
#include <vector>
using std::vector;

vector<int> topk(const vector<int>& v, int k);

int main()
{
    __BEGIN

    vector<int> v = { 10, 20, 30, 40, 50 };
    for (int n : topk(v, 3))
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    __END
}

vector<int> topk(const vector<int>& v, int k)
{
    int n = v.size();
    if (v.empty() || k < 1) return {};

    // in the case where k >= n, the returned array is not sorted
    // like in cases where k < n, it's just the copy of input
    if (k >= n) return v;

    vector<int> top(k);
    for (int i = 0; i < n; ++i)
    {
        if (static_cast<int>(top.size()) < k)
        {
            top.push_back(v[i]);
        }
        else if (top[k-1] < v[i])
        {
            top[k-1] = v[i];
        }
        else continue;

        int j = top.size() - 1;
        while (j > 0 && top[j] > top[j-1])
        {
            std::swap(top[j], top[j-1]);
            --j;
        }
    }

    return top;
}
