#pragma once

#include <stdint.h>

void KeccakF1600_StateExtractBytes(uint64_t *state, unsigned char *data,
                                   uint16_t offset, uint16_t length);
void KeccakF1600_StateXORBytes(uint64_t *state, const unsigned char *data,
                               uint16_t offset, uint16_t length);
void KeccakF1600_StatePermute(uint64_t *state);
