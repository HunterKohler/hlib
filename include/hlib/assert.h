#ifndef HLIBC_ASSERT_H_
#define HLIBC_ASSERT_H_

#include <assert.h>
#include <hlib/config.h>

#define HLIB_ASSERT(x)    \
    do {                  \
        if (HLIB_DEBUG) { \
            assert(x);    \
        }                 \
    } while (0)

#define HLIB_STATIC_ASSERT(x, msg) _Static_assert(x, msg)

#endif
