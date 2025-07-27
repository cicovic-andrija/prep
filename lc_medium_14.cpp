// #lc-medium-14

#include "markers.h"

#include <algorithm>
#include <vector>
#include <string>
using std::string, std::vector;

// Passed 8 test cases on LC.
vector<string> generate_parens(int n);

int main()
{
    __BEGIN

    for (string s : generate_parens(3))
    {
        std::cout << s << std::endl;
    }

    for (string s : generate_parens(1))
    {
        std::cout << s << std::endl;
    }

    __END
}

void generate(string prefix, int opens_left, int closes_left, vector<string>& solutions)
{
    if (!opens_left && !closes_left) {
        solutions.push_back(prefix);
        return;
    }
    if (prefix.back() == '(') {
        if (opens_left) generate(prefix+"(", opens_left-1, closes_left, solutions);
        generate(prefix+")", opens_left, closes_left-1, solutions);
    } else {
        if (opens_left) generate(prefix+"(", opens_left-1, closes_left, solutions);
        if (closes_left > opens_left) generate(prefix+")", opens_left, closes_left-1, solutions);
    }
}

vector<string> generate_parens(int n)
{
    vector<string> solutions;
    generate("(", n-1, n, solutions);
    return solutions;
}
