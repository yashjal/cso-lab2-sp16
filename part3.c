#include <assert.h>

#include "part3.h"

char part3(long x, int b)
{
    //t = temp variable (%rcx)
    long t;
    // b = %esi because %esi/int b is 16 bit
    // test sets the condition flags of b
    // jumps occur when b < 0 and (unsigned)b > 7
    if (b >= 0) {
        if ((unsigned)b <= 0x7) {
            t = 8 * b;
            //%cl is the least 8 significant bits of %rcx
            //bitwise & operation extracts that
            x >>= (t & 0xff);
            return x;

        }
    }

    return 0;
}
