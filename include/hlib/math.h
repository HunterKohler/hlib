#ifndef HLIB_MATH_H_
#define HLIB_MATH_H_

#include <hlib/config.h>

#define HLIB_MAX(a, b)            \
    ({                            \
        HLIB_TYPEOF(a) __a = (a); \
        HLIB_TYPEOF(b) __b = (b); \
        __a > __b ? __a : __b;    \
    })

#define HLIB_MIN(a, b)            \
    ({                            \
        HLIB_TYPEOF(a) __a = (a); \
        HLIB_TYPEOF(b) __b = (b); \
        __a < __b ? __a : __b;    \
    })

#define HLIB_CLAMP(x, a, b)                   \
    ({                                        \
        HLIB_TYPEOF(a) __a = (a);             \
        HLIB_TYPEOF(b) __b = (b);             \
        HLIB_TYPEOF(x) __x = (x);             \
        HLIB_ASSERT(__a <= __b);              \
        __x<__a ? __a : __x> __b ? __b : __x; \
    })

#endif
