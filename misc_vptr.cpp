#include "markers.h"

// Compile and examine where vtable is stored in the binary for Dummy.

class Dummy {
    virtual void foo() {}
};

Dummy dummy;

int main()
{
    __BEGIN
    __END
}
