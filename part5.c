#include <assert.h>

#include <stdlib.h>

#include "part5.h"

long bar(long * a, int size) {
    // l = %edx ; ar = %r8 ; t = %rax (return), k = %rcx
    int l = 0;
    long ar = 1;
    long t = 0;
    long k;
    size -= 1;
    while (size > l) {
        k = l;
        //since a(%rdi) is a long array, a move
        //by 8*k means accessing the kth element
        k = a[k];
        t += k;
        ar *= k;
        l += 1;
    }

    t += ar;
    return t;
}

long part5(int size)
{
    // x = %esi (temp) ; t = %rax (return)
    int x = size;
    long t = size;
    // k = %ecx, l = %rdx
    int k;
    long l;
    t = 8 * t + 22;
    t &= 0xfffffffffffffff0;
    //subtracting t from the stack base pointer
    // makes the stack an array with t elements
    // with constant pointer to 1st element at %r8
    long array[t];
    size = array[0];
    //move 0 to least 16 significant bits (to %eax)
    t &= 0x00000000;
    while ((int)t < x) {
        k = t + t;
        k = (long) k;
        l = (int)t;
        // (%r8,%rdx,8) means 8*l + array
        //since %r8 is a longarray it translates
        // to accessing its lth element
        array[l] = k;
        t += 1;
    }
    //since %rax is caller saved, t gets changed in bar
    t = bar(array, x);
    return t;

}
