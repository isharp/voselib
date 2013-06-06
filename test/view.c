#include <stdio.h>
#include <stdlib.h>
#include "sllist.h"
#define MAX 100
int main(void)
{
        struct sllist *nums = sllist_create();
        int *number;
        for(int i = 0; i < MAX; i++) {
                number = malloc(sizeof(int));
                *number = i;
                sllist_push_back(nums, number);
                sllist_push_front(nums,number);
        }

        nums->current = nums->head;
        int val;
        while(nums->current != NULL) {
                val = *(int*)(nums->current->data);
                printf("%d\n", val);
                sllist_step(nums);
        }
        number = malloc(sizeof(int));
        *number = 314159;
        sllist_insert_after(nums, 50, number);
        sllist_extract_after(nums, 50);
        for(int i = 0; i < nums->size; i++) {
                number = sllist_read_index(nums, i);
                printf("%d\n", *number);
        }
        free(number);
        sllist_destroy(nums);
}
