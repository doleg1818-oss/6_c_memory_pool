#include <assert.h>
#include <stdio.h>
#include <stdint.h>

#include "memory_pool.h"

int main(void)
{
    memory_pool_t pool;

    memory_pool_init(&pool);

    assert(memory_pool_used_count(&pool) == 0);
    assert(memory_pool_free_count(&pool) == MEMORY_POOL_BLOCK_COUNT);

    void *block1 = memory_pool_alloc(&pool);
    assert(block1 != NULL);
    assert(memory_pool_used_count(&pool) == 1);

    void *block2 = memory_pool_alloc(&pool);
    assert(block2 != NULL);
    assert(memory_pool_used_count(&pool) == 2);

    assert(memory_pool_free(&pool, block1) == true);
    assert(memory_pool_used_count(&pool) == 1);

    assert(memory_pool_free(&pool, block1) == false);  // double free

    assert(memory_pool_free(&pool, block2) == true);
    assert(memory_pool_used_count(&pool) == 0); 

    printf("memory pool test passed \n");

    return 1;
}