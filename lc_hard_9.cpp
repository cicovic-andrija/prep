// #lc-hard-9

#include "markers.h"

#include <algorithm>
#include <string>
#include <stack>
using std::string;
using std::stack;

// Passed 232 test cases on LC.
int longest_valid_parentheses(const string& s);

int main()
{
    __BEGIN

    std::cout << longest_valid_parentheses("(()") << std::endl;
    std::cout << longest_valid_parentheses(")()())") << std::endl;
    std::cout << longest_valid_parentheses("") << std::endl;

    __END
}

int longest_valid_parentheses(const string& s)
{
    int max_len = 0;
    int len = s.length();
    stack<int> st;

    st.push(-1);
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else // ')'
        {
            st.pop();
            if (st.empty()) {
                st.push(i);
            } else {
                max_len = std::max(max_len, i - st.top());
            }
        }
    }

    return max_len;
}
