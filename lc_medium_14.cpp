// #lc-medium-14

#include "markers.h"

#include <algorithm>
#include <vector>
#include <string>
using std::string, std::vector;

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

