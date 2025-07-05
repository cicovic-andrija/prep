// #lc-easy-3

#include "markers.h"

#include <string>

// Passed 100 test cases on LC.
bool run(std::string str);

int main()
{
    __BEGIN

    std::cout << run("()") << std::endl; // true
    std::cout << run("(]") << std::endl; // false
    std::cout << run("({})") << std::endl; // true
    std::cout << run("{}([)]") << std::endl; // false
    std::cout << run("({[]}){[]}()") << std::endl; // true
    std::cout << run("()}") << std::endl; // false

    __END
}

char matching(const char opening)
{
    if (opening == '(') return ')';
    if (opening == '{') return '}';
    if (opening == '[') return ']';
    return '\0';
}

const char *explore(const char *s, const char until, bool &is_valid)
{
    while (*s) {
        switch (*s) {
        case '{': case '(': case '[':
            s = explore(s+1, matching(*s), is_valid);
            if (!is_valid) return nullptr;
            break;
        case '}': case ')': case ']':
            if (*s != until) {
                is_valid = false;
            }
            return !is_valid ? nullptr : s+1;
        }
    }

    is_valid = false;
    return nullptr;
}

bool run(std::string str)
{
    const char *s = str.c_str();
    bool is_valid = true;
    while (*s) {
        if (*s == '{' || *s == '(' || *s == '[')
        {
            s = explore(s+1, matching(*s), is_valid);
            if (!is_valid) return false;
        } else {
            return false;
        }
    }
    return is_valid;
}
