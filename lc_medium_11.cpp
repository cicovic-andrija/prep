// #lc-medium-11

#include "markers.h"

#include <string>
using std::string;

#include <vector> // for DP approach

// Passed 142 test cases on LC.
string longest_palindrome(string s);
string longest_palindrome_dp(string s);

int main()
{
    __BEGIN

    std::cout << longest_palindrome("babad") << std::endl;
    std::cout << longest_palindrome("cbbd") << std::endl;
    std::cout << longest_palindrome("a") << std::endl;

    std::cout << longest_palindrome_dp("babad") << std::endl;
    std::cout << longest_palindrome_dp("cbbd") << std::endl;
    std::cout << longest_palindrome_dp("a") << std::endl;

    __END
}

bool test_palindrome(const char *p, const char *g)
{
    while (p < g) if (*p++ != *g--) return false;
    return true;
}

string longest_palindrome(string s)
{
    int n = s.size();
    if (n < 2) {
        return s;
    }

    const char *start = s.c_str();
    const char *end = start + s.size() - 1;
    const char *longest_p = start;
    int longest_size = 1;

    int j = 0;
    while (j < n - 1) {
        int i = 0;
        while (i < n - 1 - j) {
            int size = n - i - j;
            if (size <= longest_size) break;
            if (test_palindrome(start + j, end - i)) {
                longest_p = start + j;
                longest_size = size;
                break;
            }
            ++i;
        }
        ++j;
    }

    return s.substr(longest_p - s.c_str(), longest_size);
}

// i and j are positions in s
bool test_palindrome_dp(std::vector<std::vector<bool>>& tbl, int i, int j, const string& s)
{
    if (i == j) return tbl[i][j] = true; // same character
    if (j - i == 1) return tbl[i][j] = s[i] == s[j]; // substring of length 2
    return tbl[i][j] = s[i] == s[j] && tbl[i+1][j-1] == true; // substring of length > 2
}

// Dynamic programming approach.
// Every combination of i, j is checked,
// where i <= j. j - i grows, so substring grows.
// Previous calcs are reused by using a n x n table.
// For s where n = 4:
// x x x x
// - x x x
// - - x x
// - - - x
string longest_palindrome_dp(string s)
{
    int n = s.size();
    int start = 0, max_len = 0;
    std::vector<std::vector<bool>> tbl(n, std::vector<bool>(n, false));
    for (int g = 0; g < n; ++g) {
        for (int i = 0, j = g; j < n; i++, j++) {
            if (test_palindrome_dp(tbl, i, j ,s)) {
                if (j - i + 1 > max_len) {
                    start = i;
                    max_len = j - i + 1;
                }
            }
        }
    }
    return s.substr(start, max_len);
}
