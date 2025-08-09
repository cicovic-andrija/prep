// #lc-hard-9

#include "markers.h"

#include <algorithm>
#include <string>
using std::string;

// Passed XXX test cases on LC.
int longest_valid_parentheses(const string& s);

int main()
{
    __BEGIN

    std::cout << longest_valid_parentheses("(()") << std::endl;
    std::cout << longest_valid_parentheses(")()())") << std::endl;
    std::cout << longest_valid_parentheses("") << std::endl;

    __END
}

bool check_parens(const string &s)
{
    int counter = 0;

    for (const char c : s) {
        if (c == '(') {
            ++counter;
        } else { // ')'
            if (counter == 0) return false;
            --counter;
        }
    }

    return counter == 0;
}

int longest_valid_parentheses(const string& s)
{
    if (s.empty()) return 0;
}
