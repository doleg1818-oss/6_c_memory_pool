#include "memory_pool.h"


void memory_pool_init(memory_pool_t *pool)
{
    if(pool == NULL)
    {
        return;
    }
    for(size_t i = 0; i < MEMORY_POOL_BLOCK_COUNT; i++)
    {
        pool->used[i] = false;      // mark every block as free
    }
    pool->used_count = 0;
}

void *memory_pool_alloc(memory_pool_t *pool)        
{
    if(pool == NULL)
    {
        return NULL;
    }
    for(size_t i = 0; i < MEMORY_POOL_BLOCK_COUNT; i++) // Check all block of pool
    {
        if(pool->used[i] == false)                  // Found free block
        {
            pool->used[i] = true;                  // mark as used
            pool->used_count++;     
            
            if(pool->used_count > pool->peak_used_count)
            {
                pool->peak_used_count = pool->used_count;
            }

            return pool->memory[i];                 // return pointer on this free block
        }
    }
    return NULL;
}

bool memory_pool_free(memory_pool_t *pool, void *ptr)
{
    if(pool == NULL || ptr == NULL)
    {
        return false;
    }
    
    for(size_t i = 0; i < MEMORY_POOL_BLOCK_COUNT; i++)
    {
        if(ptr == pool->memory[i])  // ??
        {
            memset(pool->memory[i], 0, MEMORY_POOL_BLOCK_SIZE);

            if(pool->used[i] == false)  // if block is free
            {
                return false;
            }
            pool->used[i] = false;      // make this block free
            pool->used_count--;

            return true;
        }
    }
    return false;
}

size_t memory_pool_used_count(const memory_pool_t *pool)
{
    if(pool == NULL)
    {
        return 0;
    }
    return pool->used_count;
}

size_t memory_pool_free_count(const memory_pool_t *pool)
{
    if(pool == NULL)
    {
        return 0;
    }
    return MEMORY_POOL_BLOCK_COUNT - pool->used_count;
}

size_t memory_pool_peak_used_count(const memory_pool_t *pool)
{
    if(pool == NULL)
    {
        return 0;
    }
    return pool->peak_used_count;
}

