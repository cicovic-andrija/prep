// #my-easy-1

#include "markers.h"

#include <set>

static int digisum_squared(int k);
static bool is_happy(int k);

int main()
{
    __BEGIN

    std::cout << is_happy(1) << std::endl;   // true
    std::cout << is_happy(313) << std::endl; // true
    std::cout << is_happy(331) << std::endl; // true
    std::cout << is_happy(367) << std::endl; // true
    std::cout << is_happy(379) << std::endl; // true
    std::cout << is_happy(4) << std::endl; // false
    std::cout << is_happy(0) << std::endl; // false
    std::cout << is_happy(-1) << std::endl; // false

    __END
}

static int digisum_squared(int k)
{
    int sum = 0;
    while (k > 0) {
        sum += (k % 10) * (k % 10);
        k = k / 10;
    }
    return sum;
}

static bool is_happy(int k)
{
    if (k < 1) return false;

    bool happy = false;
    std::set<int> seen;
    while (true) {
        seen.insert(k);
        k = digisum_squared(k);
        if (k == 1) {
            happy = true;
            break;
        }
        if (seen.count(k)) {
            break;
        }
    }

    return happy;
}
