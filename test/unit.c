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
static void sll_setup(struct sll_fix *sll_f, gconstpointer ignored)
{
        sll_f->sllist = sllist_create();
}

static void sll_teardown(struct sll_fix *sll_f, gconstpointer ignored)
{
        sllist_destroy(sll_f->sllist);
}

static void no_op(struct sll_fix *sll_f, gconstpointer ignored) {;}
//Prepare fixture for testing push_front operation.
static void sll_setup_pf(struct sll_fix *sll_f, gconstpointer ignored)
{
        sll_f->sllist = sllist_create();
        int *testp;
        testp = malloc(sizeof(int) * 10);
        for(int i = 0; i < 10; i++)
                testp[i] = i * 10;
        sllist_push_front(sll_f->sllist, testp);
}

//Prepare fixture for testing push_back operation.
static void sll_setup_pb(struct sll_fix *sll_f, gconstpointer ignored)
{
	sll_f->sllist = sllist_create();
	int *testp;
	testp = malloc(sizeof(int) * 10);
	for(int i = 0; i < 10; i++)
	        testp[i] = i * 10;
	sllist_push_back(sll_f->sllist, testp);
}

//Prepare fixture for testing pop operation.
static void sll_setup_pop(struct sll_fix *sll_f, gconstpointer ignored)
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

//Prepare fixture for testing step operation.
static void sll_setup_step(struct sll_fix *sll_f, gconstpointer ignored)
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

//Prepare fixture for testing a lengthy list (100 elements.)
static void sll_setup_lengthy(struct sll_fix *sll_f, gconstpointer ignored)
{
        sll_f->sllist = sllist_create();
        int *testp;
        for(int i = 0; i < 100; i++) {
                testp = malloc(sizeof(int) * 10);
                for(int j = 0; j < 10; j++)
                        testp[j] = j * 10;
                sllist_push_back(sll_f->sllist, testp);

        }
}

//Procedure for testing an empty list
static void check_create(struct sll_fix *sll_f, gconstpointer ignored)
{
        sll_setup(sll_f, ignored);
        g_assert(sllist_head(sll_f->sllist) == NULL);
        g_assert(sllist_tail(sll_f->sllist) == NULL);
        g_assert(sllist_current(sll_f->sllist) == NULL);
        g_assert(sllist_size(sll_f->sllist) == 0);
}

//Procedure for testing a push_front operation on an empty list.
static void check_pf(struct sll_fix *sll_f, gconstpointer ignored)
{
        sll_setup_pf(sll_f, ignored);
        struct lnode *head = sllist_head(sll_f->sllist);
        int *int_arr = lnode_data(head);
        g_assert(sllist_size(sll_f->sllist) == 1);
	for(int i = 0; i < 10; i++)
	        g_assert(int_arr[i] == i * 10);
}

//Procedure for testing a push_back operation on an empty list
static void check_pb(struct sll_fix *sll_f, gconstpointer ignored)
{
        sll_setup_pb(sll_f, ignored);
        struct lnode *head = sllist_head(sll_f->sllist);
        int *int_arr = lnode_data(head);
        g_assert(sllist_size(sll_f->sllist) == 1);
        for(int i = 0; i < 10; i++)
                g_assert(int_arr[i] == i * 10);

}

//Procedure for testing a pop_front operation on a list with 3 elements.
static void check_popf(struct sll_fix *sll_f, gconstpointer ignored)
{
        sll_setup_pop(sll_f, ignored);
        int* int_arr;
        int loop_ctr = 1;
        while ((int_arr = sllist_pop_front(sll_f->sllist))) {
                for(int i = 0; i < 10; i++)
                        g_assert(int_arr[i] == 10 * loop_ctr * i);
                loop_ctr++;
        }
}

//Procedure for testing a pop_back operation on a list with 3 elements.
static void check_popb(struct sll_fix *sll_f, gconstpointer ignored)
{
        sll_setup_pop(sll_f, ignored);
        int* int_arr;
        int loop_ctr = 3;
        while((int_arr = sllist_pop_back(sll_f->sllist))) {
                for(int i = 0; i < 10; i++)
                        g_assert(int_arr[i] == 10 * loop_ctr * i);
                loop_ctr--;
        }
}

//Procedure for testing a step operation on a list with 3 elements.
static void check_step(struct sll_fix *sll_f, gconstpointer ignored)
{
        sll_setup_step(sll_f, ignored);
        struct lnode *head = sllist_head(sll_f->sllist);
        struct lnode *head_next = lnode_next(head);
        struct lnode *head_next_next = lnode_next(head_next);
        int *int_arr_1;
        int *int_arr_2;
        int *int_arr_3;
        int_arr_1 = lnode_data(head); 
        int_arr_2 = lnode_data(head_next); 
        int_arr_3 = lnode_data(head_next_next); 
        g_assert(sllist_size(sll_f->sllist) == 3);
        for(int i = 0; i < 10; i++) {
                g_assert(int_arr_1[i] == i * 10);
                g_assert(int_arr_2[i] == i * 20);
                g_assert(int_arr_3[i] == i * 30);
        }
        int *int_arr;
        int loop_ctr = 1;
        struct lnode *current = sllist_head(sll_f->sllist); 
        while(current != NULL) {
                int_arr = lnode_data(current);
                for(int i = 0; i < 10; i++)
                        g_assert(int_arr[i] == 10 * loop_ctr * i);
                sllist_step(sll_f->sllist);
                current = sllist_current(sll_f->sllist);
                loop_ctr++;
        }

}

//Procedure for testing a read_index operation on a list with 100 elements.
static void check_ri(struct sll_fix *sll_f, gconstpointer ignored)
{
        sll_setup_lengthy(sll_f, ignored);
        int size = sllist_size(sll_f->sllist); 
        int *int_arr;
        for(int i = 0; i < size; i++) {
                int_arr = sllist_read_index(sll_f->sllist, i);
                for(int j = 0; j < 10; j++)
                        g_assert(int_arr[j] == j * 10);
                sllist_step(sll_f->sllist);
                size = sllist_size(sll_f->sllist); 
        }
}

//Procedure for testing an insert_after operation on a list with 100 elements.
static void check_ia(struct sll_fix *sll_f, gconstpointer ignored)
{

        sll_setup_lengthy(sll_f, ignored);
        int *int_arr1 = malloc(sizeof(int) * 10);
        int *int_arr2 = malloc(sizeof(int) * 10);
        int *int_arr3 = malloc(sizeof(int) * 10);
        int *int_arr4 = malloc(sizeof(int) * 10);
        for(int i = 0; i < 10; i++) {
                int_arr1[i] = 314159 * i;
                int_arr2[i] = 314159 * i;
                int_arr3[i] = 314159 * i;
                int_arr4[i] = 314159 * i;
        }
        g_assert(!sllist_insert_after(sll_f->sllist, 0, int_arr1));
        g_assert(!sllist_insert_after(sll_f->sllist, 1, int_arr2));
        g_assert(!sllist_insert_after(sll_f->sllist, 50, int_arr3));
        g_assert(!sllist_insert_after(sll_f->sllist, 102, int_arr4));
        int_arr1 = sllist_read_index(sll_f->sllist, 0);
        for(int i = 0; i < 10; i++)
                g_assert(int_arr1[i] == i * 10);
        int_arr1 = sllist_read_index(sll_f->sllist, 1);
        for(int i = 0; i < 10; i++)
                g_assert(int_arr1[i] == 314159 * i);
        int_arr1 = sllist_read_index(sll_f->sllist, 2);
        for(int i = 0; i < 10; i++)
                g_assert(int_arr1[i] == 314159 * i);
        int_arr1 = sllist_read_index(sll_f->sllist, 51);
        for(int i = 0; i < 10; i++)
                g_assert(int_arr1[i] == 314159 * i);
        int_arr1 = sllist_read_index(sll_f->sllist, 52);
        for(int i = 0; i < 10; i++)
                g_assert(int_arr1[i] == i * 10);
        int_arr1 = sllist_read_index(sll_f->sllist, 103);
        for(int i = 0; i < 10; i++)
                g_assert(int_arr1[i] == 314159 * i);
}

//Procedure for testing an extract_after operation on a list with 100 elements.
static void check_ea(struct sll_fix *sll_f, gconstpointer ignored)
{
        sll_setup_lengthy(sll_f, ignored);
        int *int_arr = malloc(sizeof(int) * 10);
        int_arr = sllist_extract_after(sll_f->sllist, 98);
        int size = sllist_size(sll_f->sllist); 
        g_assert(size == 99);
        g_assert(int_arr != NULL);
        int_arr = sllist_extract_after(sll_f->sllist, 98);
        g_assert(int_arr == NULL);
}

//Run tests in the order they appear in this file.
int main(int argc, char *argv[])
{
        g_test_init(&argc, &argv, NULL);
        g_test_add("/test/sll_create test", struct sll_fix, NULL, sll_setup,
                                                        check_create,
                                                        sll_teardown);
        g_test_add("/test/sll_push_front test", struct sll_fix, NULL,
                                                        sll_setup_pf, check_pf,
                                                        sll_teardown);
        g_test_add("/test/sll_push_back test", struct sll_fix, NULL,
                                                        sll_setup_pb, check_pb,
                                                        sll_teardown);
        g_test_add("/test/sll_pop_front test", struct sll_fix, NULL,
                                                        sll_setup_pop,
                                                        check_popf,
                                                        sll_teardown);
        g_test_add("/test/sll_pop_back test", struct sll_fix, NULL,
                                                        sll_setup_pop,
                                                        check_popb,
                                                        sll_teardown);
        g_test_add("/test/sll_step test", struct sll_fix, NULL, sll_setup_step,
                                                        check_step,
                                                        sll_teardown);
        g_test_add("/test/sll_read_index test", struct sll_fix, NULL,
                                                        sll_setup_lengthy,
                                                        check_ri, sll_teardown);
        g_test_add("/test/sll_insert_after test", struct sll_fix, NULL,
                                                        sll_setup_lengthy,
                                                        check_ia, no_op);
        g_test_add("/test/sll_extract_after test", struct sll_fix, NULL,
                                                        sll_setup_lengthy,
                                                        check_ea, sll_teardown);
        return g_test_run();
}
