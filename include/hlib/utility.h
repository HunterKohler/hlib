#ifndef HLIB_UTILITY_H_
#define HLIB_UTILITY_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <hlib/assert.h>
#include <hlib/config.h>

#define HLIB_TYPEOF(a) __typeof(a)

#define HLIB_IS_SAME_TYPE(a, b) \
    (__builtin_types_compatible_p(HLIB_TYPEOF(a), HLIB_TYPEOF(b)))

#define HLIB_IS_ARRAY(a) (!HLIB_IS_SAME_TYPE((a), &(a)[0]))

#define HLIB_ARRAY_SIZE(a)                                       \
    ({                                                           \
        HLIB_STATIC_ASSERT(                                      \
            HLIB_IS_ARRAY(a), "Argument must be an array type"); \
        sizeof(a) / sizeof(a)[0];                                \
    })

#define HLIB_LIKELY(a) __builtin_expect(!!(a), 1)

#define HLIB_UNLIKELY(a) __builtin_expect(!!(a), 0)

HLIB_ATTR_ALWAYS_INLINE
HLIB_ATTR_NORETURN
static inline void unreachable()
{
#if HLIB_HAS_BUILTIN(__builtin_unreachable)
    __builtin_unreachable();
#else
    abort();
#endif
}

#define HLIB_CONTAINER_OF(member_ptr, container_type, member_name)         \
    ({                                                                     \
        void *__ptr = (member_ptr);                                        \
        HLIB_STATIC_ASSERT(                                                \
            HLIB_IS_SAME_TYPE(                                             \
                (*(member_ptr)), ((container_type *)0)->member_name) ||    \
                HLIB_IS_SAME_TYPE((*(member_ptr)), void),                  \
            "Invalid *member_ptr: Expected type of member");               \
        (container_type *)(void *)((char *)ptr -                           \
                                   offsetof(container_type, member_name)); \
    })

typedef void *(*hlib_cmp_t)(const void *, const void *);

int hlib_bool_cmp(const bool *a, const bool *b);
int hlib_char_cmp(const char *a, const char *b);
int hlib_uchar_cmp(const unsigned char *a, const unsigned char *b);
int hlib_schar_cmp(const signed char *a, const signed char *b);
int hlib_short_cmp(const short *a, const short *b);
int hlib_int_cmp(const int *a, const int *b);
int hlib_long_cmp(const long *a, const long *b);
int hlib_llong_cmp(const long long *a, const long long *b);
int hlib_ushort_cmp(const unsigned short *a, const unsigned short *b);
int hlib_uint_cmp(const unsigned int *a, const unsigned int *b);
int hlib_ulong_cmp(const unsigned long *a, const unsigned long *b);
int hlib_ullong_cmp(const unsigned long long *a, const unsigned long long *b);
int hlib_int8_cmp(const int8_t *a, const int8_t *b);
int hlib_int16_cmp(const int16_t *a, const int16_t *b);
int hlib_int32_cmp(const int32_t *a, const int32_t *b);
int hlib_int64_cmp(const int64_t *a, const int64_t *b);
int hlib_uint8_cmp(const uint8_t *a, const uint8_t *b);
int hlib_uint16_cmp(const uint16_t *a, const uint16_t *b);
int hlib_uint32_cmp(const uint32_t *a, const uint32_t *b);
int hlib_uint64_cmp(const uint64_t *a, const uint64_t *b);
int hlib_float_cmp(const float *a, const float *b);
int hlib_double_cmp(const double *a, const double *b);
int hlib_ldouble_cmp(const long double *a, const long double *b);

#endif
