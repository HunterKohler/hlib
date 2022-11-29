#ifndef HLIB_CONFIG_H_
#define HLIB_CONFIG_H_

#if __cplusplus
#define HLIB_CPLUSPLUS __cplusplus
#else
#define HLIB_CPLUSPLUS 0L
#endif

#ifdef __STDC_VERSION__
#define HLIB_STDC_VERSION __STDC_VERSION__
#else
#define HLIB_STDC_VERSION 0L
#endif

#define HLIB_STDC_C99 199901L
#define HLIB_STDC_C11 201112L
#define HLIB_STDC_C17 201710L

// This needs to be checked upon release of C23. The number here is based on
// the draft n3054, released September 3, 2022.
#define HLIB_STDC_C23 202311

#ifndef HLIB_DEBUG
#define HLIB_DEBUG 0
#endif

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define HLIB_LITTLE_ENDIAN 1
#define HLIB_BIG_ENDIAN 0
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#define HLIB_LITTLE_ENDIAN 0
#define HLIB_BIG_ENDIAN 1
#else
#error Byte order unknown: CPU may not be supported
#endif

#ifdef __has_builtin
#define HLIB_HAS_BUILTIN(x) __has_builtin(x)
#else
#define HLIB_HAS_BUILTIN(x) 0
#endif

#ifdef __has_attribute
#define HLIB_HAS_ATTRIBUTE(x) __has_attribute(x)
#else
#define HLIB_HAS_ATTRIBUTE(x) 0
#endif

#if HLIB_HAS_ATTRIBUTE(__packed__)
#define HLIB_HAS_ATTR_PACKED 1
#define HLIB_ATTR_PACKED __attribute__((__packed__))
#else
#define HLIB_HAS_ATTR_PACKED 0
#define HLIB_ATTR_PACKED
#endif

// Function must not read state.
#if HLIB_HAS_ATTRIBUTE(__const__)
#define HLIB_HAS_ATTR_CONST 1
#define HLIB_ATTR_CONST __attribute__((__const__))
#else
#define HLIB_HAS_ATTR_CONST 0
#define HLIB_ATTR_CONST
#endif

// Function must not modify state.
#if HLIB_HAS_ATTRIBUTE(__pure__)
#define HLIB_HAS_ATTR_PURE 1
#define HLIB_ATTR_PURE __attribute__((__pure__))
#else
#define HLIB_HAS_ATTR_PURE 0
#define HLIB_ATTR_PURE
#endif

#if HLIB_STDC_VERSION >= HLIB_STDC_C23
#define HLIB_HAS_ATTR_NORETURN 1
#define HLIB_ATTR_NORETURN [[noreturn]]
#elif HLIB_STDC_VERSION >= HLIB_STDC_C11
#define HLIB_HAS_ATTR_NORETURN 1
#define HLIB_ATTR_NORETURN _Noreturn
#elif HLIB_HAS_ATTRIBUTE(__noreturn__)
#define HLIB_HAS_ATTR_NORETURN 1
#define HLIB_ATTR_NORETURN __attribute__((__noreturn__))
#else
#define HLIB_HAS_ATTR_NORETURN 0
#define HLIB_ATTR_NORETURN
#endif

#if HLIB_HAS_ATTRIBUTE(__always_inline__)
#define HLIB_HAS_ATTR_ALWAYS_INLINE 1
#define HLIB_ATTR_ALWAYS_INLINE __attribute__((__always_inline__))
#else
#define HLIB_HAS_ATTR_ALWAYS_INLINE 0
#define HLIB_ATTR_ALWAYS_INLINE
#endif

#endif
