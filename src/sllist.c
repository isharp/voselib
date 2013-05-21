#include <stdlib.h>
#include "sllist.h"

struct lnode {
    void *data;
    struct lnode *next;
};

struct sllist {
    struct node *head;
    struct node *tail;
    struct node *current;
    int size;
};

struct sllist* sllist_create(void) {
    struct sllist *sllist;
    sllist = malloc(sizeof(struct sllist));
    sllist->head = NULL;
    sllist->tail = NULL;
    sllist->current = NULL;
    sllist->size = 0;
    return sllist;
}


