#include <assert.h>

#include "part4.h"

long foo(long* p, long val)
{
    // t = return variable (%rax)
    long t;
    t = *p;
    val = val + t;
    *p = val;
    return t;
}

long part4(long* array, int size) {

    //u = %rbp ; v = %ebx
    long u = 0;
    int v = 0;
    // x contains address of array (%r13)
    long x = array;
    // y = %r12d
    int y = size;
    //t = return variable (%rax)
    long t;
    //int comparison since registers represent 16 bits
    while (y > v) {
        t = v;
        array = x + 8 * t;
        size = 2;
        //since %rax is caller saved, t gets changed in foo
        t = foo(array, size);
        u += t;
        v += 1;
    }
    t = u;
    return t;
}
