// #lc-medium-12

#include "markers.h"

#include <algorithm>
#include <vector>
#include <string>
using std::string;

// Passed 47 test cases on LC.
int longest_common_subsequence(string s1, string s2);

int main()
{
    __BEGIN

    // std::cout << longest_common_subsequence("abcde", "ace") << std::endl;
    std::cout << longest_common_subsequence("ace", "abccde") << std::endl;
    std::cout << longest_common_subsequence("abc", "abc") << std::endl;
    std::cout << longest_common_subsequence("abc", "def") << std::endl;

    __END
}

int longest_common_subsequence(string s1, string s2)
{
    std::vector<int> dp(s1.size(), 0);
    int longest = 0;

    for (char c : s2) {
        int curr_length = 0;
        for (decltype(dp)::size_type i = 0; i < dp.size(); ++i) {
            if (curr_length < dp[i]) {
                curr_length = dp[i];
            } else if (c == s1[i]) {
                dp[i] = curr_length + 1;
                longest = std::max(longest, curr_length + 1);
            }
        }
    }

    return longest;
}
