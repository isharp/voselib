#include <stdlib.h>
#include <glib.h>
#include "sllist.h"

/* Types of lists to test:
 * empty lists
 * lists with 1 element
 * lists with 2 elements
 * lists with multiple elements
 */


/* Aspects to test about each list:
 * head and tail are NULL in an empty list
 * head and tail point to the first and last nodes
 * currrent is NULL whenever the list is empty
 * current is points to the first node by default in a non-empty list.
 * size must be the same as the total number of nodes.
 */

/* Types of data to test:
 * int*
 * dynamically allocated char* arrays.
 * int (*array)[10]
 */

/* Ways to test the data:
 * ensure that the data can be retrieved by index
 */


 //Singly linked list fixture. A wrapper for sllist struct, for testing.
struct sll_fix {
        struct sllist *sllist;
};

//Prepare fixture for testing an empty list.
static void sll_setup(struct sll_fix *sll_f, gconstpointer test_data)
{
        sll_f->sllist = sllist_create();
}


static void sll_teardown(struct sll_fix *sll_f, gconstpointer ignored)
{
        sllist_destroy(sll_f->sllist);
}

//Prepare fixture for testing push_front operation.
static void sll_setup_pf(struct sll_fix *sll_f, gconstpointer test_data)
{
        sll_f->sllist = sllist_create();
        int *testp;
        testp = malloc(sizeof(int) * 10);
        for(int i = 0; i < 10; i++)
                testp[i] = i * 10;
        sllist_push_front(sll_f->sllist, testp);
}

//Prepare fixture for testing push_back operation.
static void sll_setup_pb(struct sll_fix *sll_f, gconstpointer test_data)
{
		sll_f->sllist = sllist_create();
		int *testp;
		testp = malloc(sizeof(int) * 10);
		for(int i = 0; i < 10; i++)
				testp[i] = i * 10;
		sllist_push_back(sll_f->sllist, testp);
}

//Prepare fixture for testing step operation.

static void sll_setup_step(struct sll_fix *sll_f, gconstpointer test_data)
{
		sll_f->sllist = sllist_create();
		int *testp_1;
		int *testp_2;
                int *testp_3;
		testp_1 = malloc(sizeof(int) * 10);
		testp_2 = malloc(sizeof(int) * 10);
		testp_3 = malloc(sizeof(int) * 10);
		for(int i = 0; i < 10; i++) {
				testp_1[i] = i * 10;
				testp_2[i] = i * 20;
				testp_3[i] = i * 30;
		}
		sllist_push_back(sll_f->sllist, testp_1);
		sllist_push_back(sll_f->sllist, testp_2);
		sllist_push_back(sll_f->sllist, testp_3);
}


//Procedure for testing an empty list
static void check_create(struct sll_fix *sll_f, gconstpointer ignored)
{
        sll_setup(sll_f, ignored);
        g_assert(sll_f->sllist->head == NULL);
        g_assert(sll_f->sllist->tail == NULL);
        g_assert(sll_f->sllist->current == NULL);
        g_assert(sll_f->sllist->size == 0);
}

//Procedure for testing a push_front operation on an empty list.
static void check_pf(struct sll_fix *sll_f, gconstpointer ignored)
{
        sll_setup_pf(sll_f, ignored);
        int *int_arr;
	int_arr = sll_f->sllist->head->data;
        g_assert(sll_f->sllist->size == 1);
	int i;
	for(i = 0; i < 10; i++)
	        g_assert(int_arr[i] == i * 10);
}

//Procedure for testing a push_back operation on an empty list
static void check_pb(struct sll_fix *sll_f, gconstpointer ignored)
{
        sll_setup_pb(sll_f, ignored);
        int *int_arr;
        int_arr = sll_f->sllist->head->data;
        g_assert(sll_f->sllist->size == 1);
        int i;
        for(i = 0; i < 10; i++)
                g_assert(int_arr[i] == i * 10);

}

//Procedure for testing a step operation on a list with 3 elements.
static void check_step(struct sll_fix *sll_f, gconstpointer ignored)
{
        sll_setup_step(sll_f, ignored);
        int *int_arr_1;
        int *int_arr_2;
        int *int_arr_3;
        int_arr_1 = sll_f->sllist->head->data;
        int_arr_2 = sll_f->sllist->head->next->data;
        int_arr_3 = sll_f->sllist->head->next->next->data;
        g_assert(sll_f->sllist->size == 3);
        int i;
        for(i = 0; i < 10; i++) {
                g_assert(int_arr_1[i] == i * 10);
                g_assert(int_arr_2[i] == i * 20);
                g_assert(int_arr_3[i] == i * 30);
        }
        int *int_arr;
        int loop_ctr = 1;
        sll_f->sllist->current = sll_f->sllist->head;
        while(sll_f->sllist->current != NULL) {
                int_arr =sll_f->sllist->current->data;    
                for(i = 0; i < 10; i++) {
                        g_assert(int_arr[i] == 10 * loop_ctr * i);
                }
                sllist_step(sll_f->sllist);
                loop_ctr++;
        }



}

//Run tests in the order they appear in this file.
int main(int argc, char *argv[])
{
        g_test_init(&argc, &argv, NULL);
        g_test_add("/test/setup test", struct sll_fix, NULL, sll_setup,
                                                check_create, sll_teardown);
        g_test_add("/test/sll_setup_pf test", struct sll_fix, NULL,
                                                        sll_setup_pf, check_pf,
                                                        sll_teardown);
        g_test_add("/test/sll_setup_pb test", struct sll_fix, NULL,
                                                        sll_setup_pb, check_pb,
                                                        sll_teardown);
        g_test_add("/test/sll_step test", struct sll_fix, NULL, sll_setup_step,
                                                        check_step,
                                                        sll_teardown);
        return g_test_run();
}
