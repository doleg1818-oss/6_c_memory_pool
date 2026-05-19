#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define MEMORY_POOL_BLOCK_SIZE 32U
#define MEMORY_POOL_BLOCK_COUNT 8U

typedef struct 
{
    uint8_t memory[MEMORY_POOL_BLOCK_COUNT][MEMORY_POOL_BLOCK_SIZE];
    bool used[MEMORY_POOL_BLOCK_COUNT];
    size_t used_count;
    size_t peak_used_count;
} memory_pool_t;

void memory_pool_init(memory_pool_t *pool);
void *memory_pool_alloc(memory_pool_t *pool);
bool memory_pool_free(memory_pool_t *pool, void *ptr);
size_t memory_pool_used_count(const memory_pool_t *pool);
size_t memory_pool_free_count(const memory_pool_t *pool);
size_t memory_pool_peak_used_count(const memory_pool_t *pool);

#endif
