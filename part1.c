#include <assert.h>

#include "part1.h"

long part1(long x, long y)
{
    // x = %rdi ; y = %rsi
    if (x <= y)
        return y;
    else
        return x;

}
