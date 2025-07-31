// #my-medium-3

#include "markers.h"

#include <algorithm>
#include <tuple>
#include <stack>

void hanoi_recursive(int n, char from, char to, char aux);
void hanoi_iterative_v1(int n, char from, char to, char aux);
void hanoi_iterative_v2(int n, char from, char to, char aux);
void hanoi_iterative_final(int n, char from, char to, char aux);

int main()
{
    __BEGIN

    std::cout << "--- recursive ---" << std::endl;
    hanoi_recursive(3, 'A', 'B', 'C');
    std::cout << "--- iterative (v1) ---" << std::endl;
    hanoi_iterative_v1(3, 'A', 'B', 'C');
    std::cout << "--- iterative (v2) ---" << std::endl;
    hanoi_iterative_v2(3, 'A', 'B', 'C');
    std::cout << "--- iterative (simple) ---" << std::endl;
    hanoi_iterative_final(4, 'A', 'B', 'C');

    __END
}

void hanoi_recursive(int n, char from, char to, char aux)
{
    if (n == 1) {
        std::cout << "move disk 1 from " << from << " to " << to << std::endl;
        return;
    }

    hanoi_recursive(n-1, from, aux, to);
    std::cout << "move disk " << n << " from " << from << " to " << to << std::endl;
    hanoi_recursive(n-1, aux, to, from);
}

void hanoi_iterative_v1(int n, char from, char to, char aux)
{
    std::stack<std::tuple<int, char, char, char, int>> s;
    std::tuple<int, char, char, char, int> ar;
    auto pop_top = [&s]() -> decltype(ar) { auto t = s.top(); s.pop(); return t; };
entry:
    if (n == 1)
    {
        std::cout << "move disk 1 from " << from << " to " << to << std::endl;
        if (s.empty()) return;
        ar = pop_top();
        n = std::get<0>(ar);
        from = std::get<1>(ar);
        to = std::get<2>(ar);
        aux = std::get<3>(ar);
        if (std::get<4>(ar) == 1) goto first_return;
        else goto second_return;
    }
    ar = { n, from, to, aux, 1 };
    s.push(ar);
    n = n-1;
    std::swap(to, aux);
    goto entry;
first_return:
    std::cout << "move disk " << n << " from " << from << " to " << to << std::endl;
    ar = { n, from, to, aux, 2 };
    s.push(ar);
    n = n-1;
    std::swap(from, aux);
    goto entry;
second_return:
    if (s.empty()) return;
    ar = pop_top();
    n = std::get<0>(ar);
    from = std::get<1>(ar);
    to = std::get<2>(ar);
    aux = std::get<3>(ar);
    if (std::get<4>(ar) == 1) goto first_return;
    else goto second_return;
}

void hanoi_iterative_v2(int n, char from, char to, char aux)
{
    std::stack<std::tuple<int, char, char, char>> s;
    std::tuple<int, char, char, char> ar;
entry:
    if (n == 1)
    {
        std::cout << "move disk 1 from " << from << " to " << to << std::endl;
        if (s.empty()) return;
        std::tuple<int, char, char, char> ar = s.top();
        s.pop();
        n = std::get<0>(ar);
        from = std::get<1>(ar);
        to = std::get<2>(ar);
        aux = std::get<3>(ar);
        goto first_return;
    }
    ar = { n, from, to, aux };
    s.push(ar);
    n = n-1;
    std::swap(to, aux);
    goto entry;
first_return:
    std::cout << "move disk " << n << " from " << from << " to " << to << std::endl;
    n = n-1;
    std::swap(from, aux);
    goto entry;
}

void hanoi_iterative_final(int n, char from, char to, char aux)
{
    std::stack<std::tuple<int, char, char, char>> s;
    std::tuple<int, char, char, char> ar;
    while (true)
    {
        while (n != 1) {
            ar = { n, from, to, aux };
            s.push(ar);
            n = n-1;
            std::swap(to, aux);
        }
        std::cout << "move disk 1 from " << from << " to " << to << std::endl;
        if (s.empty()) return;
        ar = s.top();
        s.pop();
        n = std::get<0>(ar);
        from = std::get<1>(ar);
        to = std::get<2>(ar);
        aux = std::get<3>(ar);
        std::cout << "move disk " << n << " from " << from << " to " << to << std::endl;
        n = n-1;
        std::swap(from, aux);
    }
}
