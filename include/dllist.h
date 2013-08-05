#ifndef DLLIST_H
#define DLLIST_H

/**
 * @file dllist.h
 * @brief Structures and functions for a doubly-linked list API.
 *
 * The user is provided with several different functions to manipulate lists and
 * associated data.
 */

struct dnode {
        void *data;
        struct dnode *next;
        struct dnode *prev;
};

struct dllist {
        struct dnode *sentinel;
        struct dnode *head;
        struct dnode *tail;
        struct dnode *current;
        int size;
};

//Creation and destruction
struct dllist *dllist_create(void);
void dllist_destroy(struct dllist *dllist);     //If the list elements contain
                                                //dynamically allocated memory,
                                                //you will need to free the data
                                                //manually, then call this fn.

//Accessors
void *dnode_data(struct dnode *dnode);
struct dnode *dllist_sentinel(struct dllist *dllist);
struct dnode *dllist_head(struct dllist *dllist);
struct dnode *dllist_tail(struct dllist *dllist);
int dllist_size(struct dllist *dllist);
struct dnode *dnode_next(struct dnode *dnode);
struct dnode *dnode_prev(struct dnode *dnode);

//Operations
struct dnode *dllist_push_front(struct dllist *dllist, void *data);
struct dnode *dllist_push_back(struct dllist *dllist, void *data);
void *dllist_pop_front(struct dllist *dllist);
void *dllist_pop_back(struct dllist *dllist);
struct dnode *dllist_insert_before(struct dnode *dnode, void *data);
struct dnode *dllist_insert_after(struct dnode *dnode, void *data);
void *dllist_extract_before(struct dnode *dnode);
void *dllist_extract_after(struct dnode *dnode);
struct dnode *dllist_find_index(struct dllist *dllist, int index);
void *dllist_read_index(struct dllist *dllist, int index);
struct dllist *dllist_concat(struct dllist *dllist1, struct dllist dllist2);

#endif
