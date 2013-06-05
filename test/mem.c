#include <stdlib.h>
#include "sllist.h"

int main(void)
{
        struct sllist *nums;
        nums = sllist_create();
        int *number;
        for(int i = 0; i < 2000; i++) {
                number = malloc(sizeof(int));
                *number = i;
                sllist_push_back(nums, number);
        } 

        number = sllist_pop_front(nums);
        free(number);
        number = sllist_pop_back(nums);
        free(number);
        sllist_destroy(nums);
}
