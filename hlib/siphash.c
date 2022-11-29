#include <string.h>
#include <hlib/bit.h>
#include <hlib/siphash.h>

static void hlib_sipround(struct hlib_siphash_context *ctx)
{
    ctx->v[0] += ctx->v[1];
    ctx->v[1] = hlib_rotl64(ctx->v[1], 13);
    ctx->v[1] ^= ctx->v[0];
    ctx->v[0] = hlib_rotl64(ctx->v[0], 32);

    ctx->v[2] += ctx->v[3];
    ctx->v[3] = hlib_rotl64(ctx->v[3], 16);
    ctx->v[3] ^= ctx->v[2];

    ctx->v[2] += ctx->v[1];
    ctx->v[1] = hlib_rotl64(ctx->v[1], 17);
    ctx->v[1] ^= ctx->v[2];
    ctx->v[2] = hlib_rotl64(ctx->v[2], 32);

    ctx->v[0] += ctx->v[3];
    ctx->v[3] = hlib_rotl64(ctx->v[3], 21);
    ctx->v[3] ^= ctx->v[0];
}

static void hlib_siphash_transform(
    struct hlib_siphash_context *ctx, const void *data, size_t c, size_t d)
{
    uint64_t m = hlib_load_unaligned_le64(data);
    ctx->v[3] ^= m;

    for (; c > 0; --c) {
        hlib_sipround(ctx);
    }

    ctx->v[0] ^= m;
}

void hlib_siphash_init(struct hlib_siphash_context *ctx, const void *key)
{
    const uint8_t *k = key;
    uint64_t k0 = hlib_load_unaligned_le64(k);
    uint64_t k1 = hlib_load_unaligned_le64(k + 8);
    ctx->v[0] = k0 ^ 0x736F6D6570736575ULL;
    ctx->v[1] = k1 ^ 0x646F72616E646F6DULL;
    ctx->v[2] = k0 ^ 0x6C7967656E657261ULL;
    ctx->v[3] = k1 ^ 0x7465646279746573ULL;
    ctx->size = 0;
}

void hlib_siphash_update(struct hlib_siphash_context *ctx, const void *src,
                         size_t size, size_t c, size_t d)
{
    const uint8_t *data = src;
    size_t block_size = HLIB_SIPHASH_BLOCK_SIZE;
    size_t buffer_size = ctx->size & (block_size - 1);

    ctx->size += size;

    if (buffer_size) {
        uint8_t *buffer_end = ctx->buffer + buffer_size;
        size_t buffer_rem = block_size - buffer_size;

        if (buffer_rem > size) {
            memmove(buffer_end, data, size);
            return;
        }

        memmove(buffer_end, data, buffer_rem);
        data += buffer_rem;
        size -= buffer_rem;
        hlib_siphash_transform(ctx, ctx->buffer, c, d);
    }

    const uint8_t *data_end = data + size;
    const uint8_t *data_lim = data_end - block_size;

    for (; data <= data_lim; data += block_size) {
        hlib_siphash_transform(ctx, data, c, d);
    }

    memmove(ctx->buffer, data, data_end - data);
}

void hlib_siphash_finalize(
    struct hlib_siphash_context *ctx, void *dest, size_t c, size_t d)
{
    size_t block_size = HLIB_SIPHASH_BLOCK_SIZE;
    size_t buffer_size = ctx->size & (block_size - 1);
    uint8_t *buffer_end = ctx->buffer + buffer_size;

    memset(buffer_end, 0, block_size - buffer_size);
    ctx->buffer[block_size - 1] = ctx->size & 0xFF;
    hlib_siphash_transform(ctx, ctx->buffer, c, d);
    ctx->v[2] ^= 0xFF;

    for (int i = 0; i < d; i++) {
        hlib_sipround(ctx);
    }

    uint64_t digest = ctx->v[0] ^ ctx->v[1] ^ ctx->v[2] ^ ctx->v[3];
    hlib_store_unaligned_le64(dest, digest);
}

void hlib_siphash_hash(const void *key, const void *src, size_t size,
                       const void *dest, size_t c, size_t d)
{
    struct hlib_siphash_context ctx;
    hlib_siphash_init(&ctx, key);
    hlib_siphash_update(&ctx, src, size, c, d);
    hlib_siphash_finalize(&ctx, dest, c, d);
}

void hlib_siphash_update_default(
    struct hlib_siphash_context *ctx, const void *src, size_t size)
{
    hlib_siphash_update(ctx, src, size, 2, 4);
}

void hlib_siphash_finalize_default(struct hlib_siphash_context *ctx, void *dest)
{
    hlib_siphash_finalize(ctx, dest, 2, 4);
}

void hlib_siphash_hash_default(
    const void *key, const void *src, size_t size, const void *dest)
{
    hlib_siphash_hash(key, src, size, dest, 2, 4);
}
