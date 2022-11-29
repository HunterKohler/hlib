#ifndef HLIB_SIPHASH_H_
#define HLIB_SIPHASH_H_

#include <stddef.h>
#include <stdint.h>
#include <hlib/config.h>

#define HLIB_SIPHASH_BLOCK_SIZE 8
#define HLIB_SIPHASH_DIGEST_SIZE 8
#define HLIB_SIPHASH_KEY_SIZE 16

struct hlib_siphash_context {
    uint64_t v[4];
    size_t size;
    uint8_t buffer[HLIB_SIPHASH_BLOCK_SIZE];
};

void hlib_siphash_init(struct hlib_siphash_context *ctx, const void *key);

void hlib_siphash_update(struct hlib_siphash_context *ctx, const void *src,
                         size_t size, size_t c, size_t d);

void hlib_siphash_finalize(
    struct hlib_siphash_context *ctx, void *dest, size_t c, size_t d);

void hlib_siphash_hash(const void *key, const void *src, size_t size,
                       const void *dest, size_t c, size_t d);

void hlib_siphash_update_default(
    struct hlib_siphash_context *ctx, const void *src, size_t size);

void hlib_siphash_finalize_default(
    struct hlib_siphash_context *ctx, void *dest);

void hlib_siphash_hash_default(
    const void *key, const void *src, size_t size, const void *dest);

#endif
