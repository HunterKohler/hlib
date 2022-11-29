#ifndef HLIBC_BIT_H_
#define HLIBC_BIT_H_

#include <stddef.h>
#include <stdint.h>
#include <hlib/config.h>
#include <hlib/utility.h>

static inline uint16_t hlib_byteswap16(uint16_t x)
{
    return __builtin_bswap16(x);
}

static inline uint32_t hlib_byteswap32(uint32_t x)
{
    return __builtin_bswap32(x);
}

static inline uint64_t hlib_byteswap64(uint64_t x)
{
    return __builtin_bswap64(x);
}

static inline uint8_t hlib_rotl8(uint8_t x, size_t n)
{
    return (x << n) | (x >> (8 - n));
}

static inline uint16_t hlib_rotl16(uint16_t x, size_t n)
{
    return (x << n) | (x >> (16 - n));
}

static inline uint32_t hlib_rotl32(uint32_t x, size_t n)
{
    return (x << n) | (x >> (32 - n));
}

static inline uint64_t hlib_rotl64(uint64_t x, size_t n)
{
    return (x << n) | (x >> (64 - n));
}

static inline uint8_t hlib_rotr8(uint8_t x, size_t n)
{
    return (x >> n) | (x << (8 - n));
}

static inline uint16_t hlib_rotr16(uint16_t x, size_t n)
{
    return (x >> n) | (x << (16 - n));
}

static inline uint32_t hlib_rotr32(uint32_t x, size_t n)
{
    return (x >> n) | (x << (32 - n));
}

static inline uint64_t hlib_rotr64(uint64_t x, size_t n)
{
    return (x >> n) | (x << (64 - n));
}

static inline uint16_t hlib_cpu_to_le16(uint16_t x)
{
    if (HLIB_BIG_ENDIAN) {
        return hlib_byteswap16(x);
    } else {
        return x;
    }
}

static inline uint32_t hlib_cpu_to_le32(uint32_t x)
{
    if (HLIB_BIG_ENDIAN) {
        return hlib_byteswap32(x);
    } else {
        return x;
    }
}

static inline uint64_t hlib_cpu_to_le64(uint64_t x)
{
    if (HLIB_BIG_ENDIAN) {
        return hlib_byteswap64(x);
    } else {
        return x;
    }
}

static inline uint16_t hlib_cpu_to_be16(uint16_t x)
{
    if (HLIB_LITTLE_ENDIAN) {
        return hlib_byteswap16(x);
    } else {
        return x;
    }
}

static inline uint32_t hlib_cpu_to_be32(uint32_t x)
{
    if (HLIB_LITTLE_ENDIAN) {
        return hlib_byteswap32(x);
    } else {
        return x;
    }
}

static inline uint64_t hlib_cpu_to_be64(uint64_t x)
{
    if (HLIB_LITTLE_ENDIAN) {
        return hlib_byteswap64(x);
    } else {
        return x;
    }
}

static inline uint16_t hlib_le16_to_cpu(uint16_t x)
{
    return hlib_cpu_to_le16(x);
}

static inline uint32_t hlib_le32_to_cpu(uint32_t x)
{
    return hlib_cpu_to_le32(x);
}

static inline uint64_t hlib_le64_to_cpu(uint64_t x)
{
    return hlib_cpu_to_le64(x);
}

static inline uint16_t hlib_be16_to_cpu(uint16_t x)
{
    return hlib_cpu_to_be16(x);
}

static inline uint32_t hlib_be32_to_cpu(uint32_t x)
{
    return hlib_cpu_to_be32(x);
}

static inline uint64_t hlib_be64_to_cpu(uint64_t x)
{
    return hlib_cpu_to_be64(x);
}

static inline uint16_t hlib_load_unaligned_le16(const void *ptr)
{
    if (HLIB_HAS_ATTR_PACKED && HLIB_LITTLE_ENDIAN) {
        const struct {
            uint16_t value;
        } HLIB_ATTR_PACKED *p = ptr;
        return p->value;
    } else {
        uint8_t *p = ptr;
        return ((uint16_t)p[0] << 0) | ((uint16_t)p[1] << 8);
    }
}

static inline uint32_t hlib_load_unaligned_le32(const void *ptr)
{
    if (HLIB_HAS_ATTR_PACKED && HLIB_LITTLE_ENDIAN) {
        const struct {
            uint32_t value;
        } HLIB_ATTR_PACKED *p = ptr;
        return p->value;
    } else {
        uint8_t *p = ptr;
        return ((uint32_t)p[0] << 0) | ((uint32_t)p[1] << 8) |
               ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
    }
}

static inline uint64_t hlib_load_unaligned_le64(const void *ptr)
{
    if (HLIB_HAS_ATTR_PACKED && HLIB_LITTLE_ENDIAN) {
        const struct {
            uint64_t value;
        } HLIB_ATTR_PACKED *p = ptr;
        return p->value;
    } else {
        uint8_t *p = ptr;
        return ((uint64_t)p[0] << 0) | ((uint64_t)p[1] << 8) |
               ((uint64_t)p[2] << 16) | ((uint64_t)p[3] << 24) |
               ((uint64_t)p[4] << 32) | ((uint64_t)p[5] << 40) |
               ((uint64_t)p[6] << 48) | ((uint64_t)p[7] << 56);
    }
}

static inline uint16_t hlib_load_unaligned_be16(const void *ptr)
{
    if (HLIB_HAS_ATTR_PACKED && HLIB_BIG_ENDIAN) {
        const struct {
            uint16_t value;
        } HLIB_ATTR_PACKED *p = ptr;
        return p->value;
    } else {
        uint8_t *p = ptr;
        return ((uint16_t)p[0] << 8) | ((uint16_t)p[1] << 0);
    }
}

static inline uint32_t hlib_load_unaligned_be32(const void *ptr)
{
    if (HLIB_HAS_ATTR_PACKED && HLIB_BIG_ENDIAN) {
        const struct {
            uint32_t value;
        } HLIB_ATTR_PACKED *p = ptr;
        return p->value;
    } else {
        uint8_t *p = ptr;
        return ((uint32_t)p[0] << 24) | ((uint32_t)p[1] << 16) |
               ((uint32_t)p[2] << 8) | ((uint32_t)p[3] << 0);
    }
}

static inline uint64_t hlib_load_unaligned_be64(const void *ptr)
{
    if (HLIB_HAS_ATTR_PACKED && HLIB_BIG_ENDIAN) {
        struct {
            uint64_t value;
        } HLIB_ATTR_PACKED *p = ptr;
        return p->value;
    } else {
        uint8_t *p = ptr;
        return ((uint64_t)p[0] << 56) | ((uint64_t)p[1] << 48) |
               ((uint64_t)p[2] << 40) | ((uint64_t)p[3] << 32) |
               ((uint64_t)p[4] << 24) | ((uint64_t)p[5] << 16) |
               ((uint64_t)p[6] << 8) | ((uint64_t)p[7] << 0);
    }
}

static inline uint16_t hlib_load_unaligned_cpu16(const void *ptr)
{
    if (HLIB_LITTLE_ENDIAN) {
        return hlib_load_unaligned_le16(ptr);
    } else {
        return hlib_load_unaligned_be16(ptr);
    }
}

static inline uint16_t hlib_load_unaligned_cpu32(const void *ptr)
{
    if (HLIB_LITTLE_ENDIAN) {
        return hlib_load_unaligned_le32(ptr);
    } else {
        return hlib_load_unaligned_be32(ptr);
    }
}

static inline uint16_t hlib_load_unaligned_cpu64(const void *ptr)
{
    if (HLIB_LITTLE_ENDIAN) {
        return hlib_load_unaligned_le64(ptr);
    } else {
        return hlib_load_unaligned_be64(ptr);
    }
}

static inline void hlib_store_unaligned_le16(void *ptr, uint16_t value)
{
    if (HLIB_HAS_ATTR_PACKED && HLIB_LITTLE_ENDIAN) {
        struct {
            uint16_t value;
        } HLIB_ATTR_PACKED *p = ptr;
        p->value = value;
    } else {
        uint8_t *p = ptr;
        p[0] = value >> 0;
        p[1] = value >> 8;
    }
}

static inline void hlib_store_unaligned_le32(void *ptr, uint32_t value)
{
    if (HLIB_HAS_ATTR_PACKED && HLIB_LITTLE_ENDIAN) {
        struct {
            uint32_t value;
        } HLIB_ATTR_PACKED *p = ptr;
        p->value = value;
    } else {
        uint8_t *p = ptr;
        p[0] = value >> 0;
        p[1] = value >> 8;
        p[2] = value >> 16;
        p[3] = value >> 24;
    }
}

static inline void hlib_store_unaligned_le64(void *ptr, uint64_t value)
{
    if (HLIB_HAS_ATTR_PACKED && HLIB_LITTLE_ENDIAN) {
        struct {
            uint64_t value;
        } HLIB_ATTR_PACKED *p = ptr;
        p->value = value;
    } else {
        uint8_t *p = ptr;
        p[0] = value >> 0;
        p[1] = value >> 8;
        p[2] = value >> 16;
        p[3] = value >> 24;
        p[4] = value >> 32;
        p[5] = value >> 40;
        p[6] = value >> 48;
        p[7] = value >> 56;
    }
}

static inline void hlib_store_unaligned_be16(void *ptr, uint16_t value)
{
    if (HLIB_HAS_ATTR_PACKED && HLIB_BIG_ENDIAN) {
        struct {
            uint16_t value;
        } HLIB_ATTR_PACKED *p = ptr;
        p->value = value;
    } else {
        uint8_t *p = ptr;
        p[0] = value >> 8;
        p[1] = value >> 0;
    }
}

static inline void hlib_store_unaligned_be32(void *ptr, uint32_t value)
{
    if (HLIB_HAS_ATTR_PACKED && HLIB_BIG_ENDIAN) {
        struct {
            uint32_t value;
        } HLIB_ATTR_PACKED *p = ptr;
        p->value = value;
    } else {
        uint8_t *p = ptr;
        p[0] = value >> 24;
        p[1] = value >> 16;
        p[2] = value >> 8;
        p[3] = value >> 0;
    }
}

static inline void hlib_store_unaligned_be64(void *ptr, uint64_t value)
{
    if (HLIB_HAS_ATTR_PACKED && HLIB_LITTLE_ENDIAN) {
        struct {
            uint64_t value;
        } HLIB_ATTR_PACKED *p = ptr;
        p->value = value;
    } else {
        uint8_t *p = ptr;
        p[0] = value >> 56;
        p[1] = value >> 48;
        p[2] = value >> 40;
        p[3] = value >> 32;
        p[4] = value >> 24;
        p[5] = value >> 16;
        p[6] = value >> 8;
        p[7] = value >> 0;
    }
}

static inline void hlib_store_unaligned_cpu16(void *ptr, uint16_t value)
{
    if (HLIB_LITTLE_ENDIAN) {
        return hlib_store_unaligned_le16(ptr, value);
    } else {
        return hlib_store_unaligned_be16(ptr, value);
    }
}

static inline void hlib_store_unaligned_cpu32(void *ptr, uint32_t value)
{
    if (HLIB_LITTLE_ENDIAN) {
        return hlib_store_unaligned_le32(ptr, value);
    } else {
        return hlib_store_unaligned_be32(ptr, value);
    }
}

static inline void hlib_store_unaligned_cpu64(void *ptr, uint64_t value)
{
    if (HLIB_LITTLE_ENDIAN) {
        return hlib_store_unaligned_le64(ptr, value);
    } else {
        return hlib_store_unaligned_be64(ptr, value);
    }
}

#endif
