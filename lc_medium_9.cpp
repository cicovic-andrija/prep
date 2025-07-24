// #lc-medium-9

#include "markers.h"

#include <vector>

// Passed 39 test cases on LC.
int can_circle(std::vector<int>&& gas, std::vector<int>&& cost);

int main()
{
    __BEGIN

    std::cout << can_circle({ 1, 2, 3, 4, 5 }, { 3, 4, 5, 1, 2 }) << std::endl;
    std::cout << can_circle({ 2, 3, 4 }, { 3, 4, 3 }) << std::endl;

    __END
}

int can_circle(std::vector<int>&& gas, std::vector<int>&& cost)
{
    if (gas.size() != cost.size() || gas.size() < 1) {
        return -1;
    }

    int n = gas.size();
    int total = 0;
    for (int i = 0; i < n; ++i) {
        total += gas[i] - cost[i];
    }
    // this is a little hard to prove, but is intuitively correct
    if (total < 0) {
        return -1;
    }

    // there exists a solution
    int start = 0, i = start, stations_left = n, tank = 0;
    while (stations_left) {
        tank += gas[i] - cost[i];
        if (tank < 0) {
            start = (i + 1) % n; // 0 should never happen again if there is a solution
            i = start;
            stations_left = n;
            tank = 0;
            continue;
        }
        i = (i + 1) % n;
        --stations_left;
    }

    return start;
}
