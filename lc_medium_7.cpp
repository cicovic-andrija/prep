// #lc-medium-7

#include "markers.h"

#include <algorithm>
#include <deque>
#include <string>
using std::string;

// Passed 263 test cases on LC.
string simplify_path(string path);

int main()
{
    __BEGIN

    std::cout << simplify_path("/") << std::endl;
    std::cout << simplify_path("//") << std::endl;
    std::cout << simplify_path("/../../../") << std::endl;
    std::cout << simplify_path("/aa/") << std::endl;
    std::cout << simplify_path("/aa/bb/../cc") << std::endl;
    std::cout << simplify_path("/aa/bb/../cc/..") << std::endl;
    std::cout << simplify_path("/../bb/./dd") << std::endl;

    __END
}

// function assumes path is a valid path
string simplify_path(string path)
{
    std::deque<string> dq;
    int curr = path.find("/"); // must be at least one for valid path
    while (true)
    {
        int next = path.find("/", curr + 1);
        string dir = static_cast<string::size_type>(next) != string::npos ? path.substr(curr + 1, next - curr - 1) : path.substr(curr + 1);
        if (dir == "" || dir == ".") { // (a) // or (b) /.
            // do nothing - this branch can be removed,
            // but it's left here to illustrate all the cases
        } else if (dir == "..") { // (c) /..
            // go up the stack
            if (!dq.empty()) {
                dq.pop_back();
            }
        } else { // (d) /foo
            dq.push_back(std::move(dir));
        }

        if (static_cast<string::size_type>(next) == string::npos) break;

        curr = next;
    }

    if (dq.empty()) return "/";

    string canonical;
    while (!dq.empty()) {
        canonical = canonical + "/" + std::move(dq.front());
        dq.pop_front();
    }
    return canonical;
}
