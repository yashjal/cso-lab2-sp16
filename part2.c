#include <assert.h>

#include "part2.h"

long part2(long x, long y)
{
    // t = return value (%rax)
    long t;
    t = 3 * x;
    t <<= 4;
    // u = temp variable (%rdx)
    long u;
    u = y + 31;
    //test does a bitwise and operation on y and y
    //so it sets ZF to 1 iff y is 0
    //cmovns checks ZF
    if (y >= 0)
        u = y;

    u >>= 5;
    return (u & t);



}
