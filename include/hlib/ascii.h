#ifndef HLIBC_ASCII_H_
#define HLIBC_ASCII_H_

#include <stdbool.h>
#include <hlib/assert.h>

static inline bool ascii_isascii(char c)
{
    return (unsigned char)c < 128;
}

static inline bool ascii_isdigit(char c)
{
    HLIB_ASSERT(ascii_isascii(c));
    return '0' <= c && c <= '9';
}

static inline bool ascii_islower(char c)
{
    HLIB_ASSERT(ascii_isascii(c));
    return 'a' <= c && c <= 'z';
}

static inline bool ascii_isupper(char c)
{
    HLIB_ASSERT(ascii_isascii(c));
    return 'A' <= c && c <= 'Z';
}

static inline bool ascii_isgraph(char c)
{
    HLIB_ASSERT(ascii_isascii(c));
    return (unsigned char)c > 32 && (unsigned char)c < 127;
}

static inline bool ascii_isprint(char c)
{
    HLIB_ASSERT(ascii_isascii(c));
    return (unsigned char)c >= 32 && (unsigned char)c < 127;
}

static inline bool ascii_isalnum(char c)
{
    extern const unsigned char hlib_ascii_property_table[128];
    HLIB_ASSERT(ascii_isascii(c));
    return hlib_ascii_property_table[(unsigned char)c] & (1 << 0);
}

static inline bool ascii_isalpha(char c)
{
    extern const unsigned char hlib_ascii_property_table[128];
    HLIB_ASSERT(ascii_isascii(c));
    return hlib_ascii_property_table[(unsigned char)c] & (1 << 1);
}

static inline bool ascii_isblank(char c)
{
    extern const unsigned char hlib_ascii_property_table[128];
    HLIB_ASSERT(ascii_isascii(c));
    return hlib_ascii_property_table[(unsigned char)c] & (1 << 2);
}

static inline bool ascii_iscntrl(char c)
{
    extern const unsigned char hlib_ascii_property_table[128];
    HLIB_ASSERT(ascii_isascii(c));
    return hlib_ascii_property_table[(unsigned char)c] & (1 << 3);
}

static inline bool ascii_ispunct(char c)
{
    extern const unsigned char hlib_ascii_property_table[128];
    HLIB_ASSERT(ascii_isascii(c));
    return hlib_ascii_property_table[(unsigned char)c] & (1 << 4);
}

static inline bool ascii_isspace(char c)
{
    extern const unsigned char hlib_ascii_property_table[128];
    HLIB_ASSERT(ascii_isascii(c));
    return hlib_ascii_property_table[(unsigned char)c] & (1 << 5);
}

static inline bool ascii_isxdigit(char c)
{
    extern const unsigned char hlib_ascii_property_table[128];
    HLIB_ASSERT(ascii_isascii(c));
    return hlib_ascii_property_table[(unsigned char)c] & (1 << 6);
}

static inline char ascii_tolower(char c)
{
    extern const char hlib_ascii_tolower_table[128];
    HLIB_ASSERT(ascii_isascii(c));
    return hlib_ascii_tolower_table[(unsigned char)c];
}

static inline char ascii_toupper(char c)
{
    extern const char hlib_ascii_toupper_table[128];
    HLIB_ASSERT(ascii_isascii(c));
    return hlib_ascii_toupper_table[(unsigned char)c];
}

#endif
