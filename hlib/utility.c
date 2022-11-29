#include <math.h>
#include <hlib/utility.h>

#define HLIB_DEFINE_INTEGRAL_CMP(name, type)   \
    int name(const type *a, const type *b)     \
    {                                          \
        type av = *a;                          \
        type bv = *b;                          \
        return av > bv ? 1 : av < bv ? -1 : 0; \
    }

#define HLIB_DEFINE_FLOATING_CMP(name, type)                \
    int name(const type *a, const type *b)                  \
    {                                                       \
        type av = *a;                                       \
        type bv = *b;                                       \
        return isgreater(a, b) ? 1 : isless(a, b) ? -1 : 0; \
    }

HLIB_DEFINE_INTEGRAL_CMP(hlib_bool_cmp, bool);
HLIB_DEFINE_INTEGRAL_CMP(hlib_char_cmp, char);
HLIB_DEFINE_INTEGRAL_CMP(hlib_uchar_cmp, unsigned char);
HLIB_DEFINE_INTEGRAL_CMP(hlib_schar_cmp, signed char);
HLIB_DEFINE_INTEGRAL_CMP(hlib_short_cmp, short);
HLIB_DEFINE_INTEGRAL_CMP(hlib_int_cmp, int);
HLIB_DEFINE_INTEGRAL_CMP(hlib_long_cmp, long);
HLIB_DEFINE_INTEGRAL_CMP(hlib_llong_cmp, long long);
HLIB_DEFINE_INTEGRAL_CMP(hlib_ushort_cmp, unsigned short);
HLIB_DEFINE_INTEGRAL_CMP(hlib_uint_cmp, unsigned int);
HLIB_DEFINE_INTEGRAL_CMP(hlib_ulong_cmp, unsigned long);
HLIB_DEFINE_INTEGRAL_CMP(hlib_ullong_cmp, unsigned long long);
HLIB_DEFINE_INTEGRAL_CMP(hlib_int8_cmp, int8_t);
HLIB_DEFINE_INTEGRAL_CMP(hlib_int16_cmp, int16_t);
HLIB_DEFINE_INTEGRAL_CMP(hlib_int32_cmp, int32_t);
HLIB_DEFINE_INTEGRAL_CMP(hlib_int64_cmp, int64_t);
HLIB_DEFINE_INTEGRAL_CMP(hlib_uint8_cmp, uint8_t);
HLIB_DEFINE_INTEGRAL_CMP(hlib_uint16_cmp, uint16_t);
HLIB_DEFINE_INTEGRAL_CMP(hlib_uint32_cmp, uint32_t);
HLIB_DEFINE_INTEGRAL_CMP(hlib_uint64_cmp, uint64_t);
HLIB_DEFINE_FLOATING_CMP(hlib_float_cmp, float);
HLIB_DEFINE_FLOATING_CMP(hlib_double_cmp, double);
HLIB_DEFINE_FLOATING_CMP(hlib_ldouble_cmp, long double);
