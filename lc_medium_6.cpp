// #lc-medium-6

#include "markers.h"
#include "vect.h"

#include <algorithm>

using intvec = std::vector<int>;

// Passed 266 test cases on LC.
void next_permutation(intvec& current);

int main()
{
    __BEGIN

    intvec current = { 0, 1, 2, 4, 8 };
    for (int i = 0; i < 120; ++i) {
        next_permutation(current);
        print_vec(current);
    }

    std::cout << "---" << std::endl;

    current = { 5, 1, 1 };
    next_permutation(current);
    print_vec(current);

    __END
}

bool next_subpermutation(intvec& current, int start, int end)
{
    if (start == end) return true;

    bool sorted_asc = next_subpermutation(current, start + 1, end);
    if (!sorted_asc) return false; // subpermutation [start+1..end] is not final, algorithm is done
    if (current[start] >= current[start+1]) return true; // final subpermutation of [start..end]
    int t = end;
    while (t > start) {
        if (current[t] > current[start]) break;
        --t;
    }
    std::swap(current[start], t == start ? current[end] : current[t]);
    std::reverse(current.begin() + start + 1, current.end() /* end is always the same*/);
    return false; // this is not the final subpermutation
}

void next_permutation(intvec& current)
{
    if (current.size() < 2) return;

    bool final = next_subpermutation(current, 0, current.size()-1);
    if (final) {
        std::reverse(current.begin(), current.end());
    }
}
