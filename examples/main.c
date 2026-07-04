#include <stdio.h>
#include <stdint.h>
#include "memory_pool.h"

int main(void)
{
    memory_pool_t pool;
    
    memory_pool_init(&pool);

    void *block = memory_pool_alloc(&pool);
    if(block != NULL)
    {
        printf("Block allocation succsesfuly \n");
    }

    printf("Used block %zu\n", memory_pool_used_count(&pool));
    printf("Free block %zu\n", memory_pool_free_count(&pool));

    memory_pool_free(&pool, block);

    printf("Block freed\n");
    printf("Used blocks %zu\n", memory_pool_used_count(&pool));

    return 0;
}