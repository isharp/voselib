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

struct sll_fixture {
    struct sllist *sllist;
};

void sll_setup (struct sll_fixture *sll_f, gconstpointer test_data) {
    sll_f->sllist = sllist_create();
}

void sll_teardown (struct sll_fixture *sll_f, gconstpointer ignored) {
    sllist_destroy(sll_f->sllist);
}


int main(int argc, char *argv[]) {
    g_test_init(&argc, &argv, NULL);
}
