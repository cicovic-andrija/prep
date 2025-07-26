// #lc-medium-13

#include "markers.h"

#include <string>
using std::string;

// Passed 61 test cases on LC.
string reverse_words(string s);

int main()
{
    __BEGIN

    std::cout << reverse_words("  the sky is    blue ") << std::endl;

    __END
}

string extract_word(const char *&p)
{
    while (*p == ' ') ++p;

    string w;
    while (*p && *p != ' ') w.push_back(*p++);
    return w;
}

bool reverse_words_rec(const char *p, string &reversed)
{
    string word = extract_word(p);
    if (word.empty()) return true;

    bool last = reverse_words_rec(p, reversed);
    if (last) {
        reversed = word;
        return false;
    }
    reversed += " " + word;
    return false;
}

string reverse_words(string s)
{
    string reversed;
    reverse_words_rec(s.c_str(), reversed);
    return reversed;
}
