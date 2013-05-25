#include <stdlib.h>
#include "sllist.h"

struct sllist* sllist_create(void)
{
        struct sllist *sllist;
        sllist = malloc(sizeof(struct sllist));
        if (sllist != NULL) {
                sllist->head = NULL;
                sllist->tail = NULL;
                sllist->current = NULL;
                sllist->size = 0;
        }
        return sllist;
}

void sllist_destroy(struct sllist *sllist)
{
        struct lnode *save_next;
        while(sllist->current != NULL) {
                save_next = sllist->current->next;
                free(sllist->current->data);
                free(sllist->current);
                sllist->current = save_next;
        }
        free(sllist);
}

int sllist_push_front(struct sllist *sllist, void *data)
{
        struct lnode *lnode;
        lnode = malloc(sizeof(struct lnode));
        if (lnode == NULL)
                return -1;
        lnode->data = data;
        lnode->next = sllist->head;
        sllist->head = lnode;
        if (sllist->size == 0)
                sllist->tail = lnode;
        sllist->size++;
        return 0;

}

int sllist_push_back(struct sllist *sllist, void *data)
{
        struct lnode *lnode;
        lnode = malloc(sizeof(struct lnode));
        if (lnode ==NULL)
                return -1;
        lnode->data = data;
        lnode->next = NULL;
        if (sllist->size == 0) {
                sllist->head = lnode;
                sllist->tail = lnode;
        } else {
                sllist->tail->next = lnode;
                sllist->tail = lnode;
        }
        sllist->size++;
        return 0;
}

int sllist_step(struct sllist *sllist)
{
        if(sllist->current == NULL)
                return 1;
        else {
                sllist->current = sllist->current->next;
                return 0;
        }
}
