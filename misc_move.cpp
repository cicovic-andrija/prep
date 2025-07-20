#include "markers.h"

#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    __BEGIN

    string str = "Salut";
    vector<string> v;

    v.push_back(str); // push_back(const T&) overload
    cout << "After copy, str=" << quoted(str) << endl;

    v.push_back(move(str)); // push_back(T&&) overload
    cout << "After move, str=" << quoted(str) << endl;

    cout << "Vector=[" << quoted(v[0]) << ", " << quoted(v[1]) << "]" << endl;

    __END
}
