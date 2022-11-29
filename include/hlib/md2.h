#ifndef HLIBC_MD2_H_
#define HLIBC_MD2_H_

#include <stddef.h>
#include <stdint.h>
#include <hlib/config.h>

#define HLIB_MD2_KEY_SIZE 0
#define HLIB_MD2_DIGEST_SIZE 16
#define HLIB_MD2_BLOCK_SIZE 64

struct hlib_md2_context {
    size_t size;
    uint8_t state[16];
    uint8_t checksum[16];
    uint8_t buffer[HLIB_MD2_BLOCK_SIZE];
};

void hlib_md2_init(struct hlib_md2_context *ctx);

void hlib_md2_update(
    struct hlib_md2_context *ctx, const void *src, size_t size);

void hlib_md2_finalize(struct hlib_md2_context *ctx, void *dest);

void hlib_md2_hash(const void *src, size_t size, void *dest);

#endif
