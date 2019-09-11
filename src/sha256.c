#include "ssl.h"
#define RT(x, c) (x >> c | x << (32 - c))

static const uint32_t k[] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

struct State {
    const uint8_t * p;
    size_t len;
    size_t total_len;
    int got_single_one;
    int got_total_len;
};

static int get_chunk(uint8_t *chunk, struct State * state)
{

    uint32_t chunkSize = 64;
    uint32_t totalLen = 8;
    size_t space_in_chunk;

    if (state->got_total_len) {
        return 0;
    }

    if (state->len >= chunkSize) {
        memcpy(chunk, state->p, chunkSize);
        state->p += chunkSize;
        state->len -= chunkSize;
        return 1;
    }

    memcpy(chunk, state->p, state->len);
    chunk += state->len;
    space_in_chunk = chunkSize - state->len;
    state->p += state->len;
    state->len = 0;

    if (!state->got_single_one) {
        *chunk++ = 0x80;
        space_in_chunk -= 1;
        state->got_single_one = 1;
    }

    if (space_in_chunk >= totalLen) {
        const size_t left = space_in_chunk - totalLen;
        size_t len = state->total_len;
        int i;
        memset(chunk, 0x00, left);
        chunk += left;

        chunk[7] = (uint8_t) (len << 3);
        len >>= 5;
        for (i = 6; i >= 0; i--) {
            chunk[i] = (uint8_t) len;
            len >>= 8;
        }
        state->got_total_len = 1;
    } else {
        memset(chunk, 0x00, space_in_chunk);
    }

    return 1;
}

uint8_t* sha256(uint8_t *msg, size_t len)
{
    uint32_t* h = (uint32_t*)malloc(8* sizeof(uint32_t));
    h[0] = 0x6a09e667;
    h[1] = 0xbb67ae85;
    h[2] = 0x3c6ef372;
    h[3] = 0xa54ff53a;
    h[4] = 0x510e527f;
    h[5] = 0x9b05688c;
    h[6] = 0x1f83d9ab;
    h[7] = 0x5be0cd19;

    unsigned i, j;

    uint8_t chunk[64];

    struct State state;

    state.p = msg;
    state.len = len;
    state.total_len = len;
    state.got_single_one = 0;
    state.got_total_len = 0;

    while (get_chunk(chunk, &state)) {
        uint32_t ah[8];

        const uint8_t *p = chunk;

        for (i = 0; i < 8; i++)
            ah[i] = h[i];

        for (i = 0; i < 4; i++) {
            uint32_t w[16];

            for (j = 0; j < 16; j++) {
                if (i == 0) {
                    w[j] = (uint32_t) p[0] << 24 | (uint32_t) p[1] << 16 | (uint32_t) p[2] << 8 | (uint32_t) p[3];
                    p += 4;
                } else {
                    const uint32_t s0 = RT(w[(j + 1) & 0xf], 7) ^ RT(w[(j + 1) & 0xf], 18) ^ (w[(j + 1) & 0xf] >> 3);
                    const uint32_t s1 = RT(w[(j + 14) & 0xf], 17) ^ RT(w[(j + 14) & 0xf], 19) ^ (w[(j + 14) & 0xf] >> 10);
                    w[j] = w[j] + s0 + w[(j + 9) & 0xf] + s1;
                }
                const uint32_t s1 = RT(ah[4], 6) ^ RT(ah[4], 11) ^ RT(ah[4], 25);
                const uint32_t ch = (ah[4] & ah[5]) ^ (~ah[4] & ah[6]);
                const uint32_t temp1 = ah[7] + s1 + ch + k[i << 4 | j] + w[j];
                const uint32_t s0 = RT(ah[0], 2) ^ RT(ah[0], 13) ^ RT(ah[0], 22);
                const uint32_t maj = (ah[0] & ah[1]) ^ (ah[0] & ah[2]) ^ (ah[1] & ah[2]);
                const uint32_t temp2 = s0 + maj;

                ah[7] = ah[6];
                ah[6] = ah[5];
                ah[5] = ah[4];
                ah[4] = ah[3] + temp1;
                ah[3] = ah[2];
                ah[2] = ah[1];
                ah[1] = ah[0];
                ah[0] = temp1 + temp2;
            }
        }
        for (i = 0; i < 8; i++)
            h[i] += ah[i];
    }

    uint8_t* hash = (uint8_t*)malloc(32* sizeof(uint8_t));
    for (i = 0, j = 0; i < 8; i++)
    {
        hash[j++] = (uint8_t) (h[i] >> 24);
        hash[j++] = (uint8_t) (h[i] >> 16);
        hash[j++] = (uint8_t) (h[i] >> 8);
        hash[j++] = (uint8_t) h[i];
    }
    free(h);
    return hash;
}