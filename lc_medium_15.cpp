// #lc-medium-14

#include "markers.h"

#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
using std::string;
using std::vector;

// Passed 25 test cases on LC.
vector<string> letter_combinations(string digits);
vector<string> letter_combinations_recursive(string digits);

int main()
{
    __BEGIN

    for (const string &c : letter_combinations("273")) {
        std::cout << c << std::endl;
    }

    for (const string &c : letter_combinations_recursive("23")) {
        std::cout << c << std::endl;
    }

    __END
}

inline int nopts(char digit)
{
    return digit == '7' || digit == '9' ? 4 : 3;
}

vector<string> phone = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz",
};

inline char get_char(char digit, int option)
{
    return phone[digit - '0'][option];
}

vector<string> letter_combinations(string digits)
{
    int n = digits.size();
    if (n < 1) return {};

    vector<int> options;
    for (const char d : digits) {
        options.push_back(nopts(d));
    }

    vector<string> combinations;
    int ptr = 0;
    while (true) {
        --options[ptr];
        if (options[ptr] < 0) {
            if (ptr == 0) break;
            options[ptr] = nopts(digits[ptr]);
            --ptr;
            continue;
        }
        if (ptr < n-1) {
            ++ptr;
            continue;
        }

        // generate string for this options
        string c;
        for (int i = 0; i < n; ++i) {
            c.push_back(get_char(digits[i], options[i]));
        }
        combinations.push_back(c);
    }

    return combinations;
}

void letter_combinations_recursive_int(string prefix, string rest, vector<string>& combinations)
{
    if (rest.empty()) {
        combinations.push_back(prefix);
        return;
    }

    for (int i = 0; i < nopts(rest[0]); ++i) {
        letter_combinations_recursive_int(prefix+get_char(rest[0], i), rest.substr(1), combinations);
    }
}

vector<string> letter_combinations_recursive(string digits)
{
    vector<string> combinations;
    letter_combinations_recursive_int("", digits, combinations);
    return combinations;
}
