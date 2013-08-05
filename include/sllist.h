#ifndef SLLIST_H
#define SLLIST_H

/**
 * @file sllist.h
 * @brief Stuctures and functions for a singly-linked list API.
 *
 * The user is provided with several different functions to manipulate lists and
 * associated data.
 */

/**
 * The node structure.
 *
 * The purpose of this structure is to actually hold the data or "payload" to be
 * stored in the list. The nodes are connected sequentially, and thus each node
 * requires a second field to store the address of the next node.
 */
struct snode;

/**
 * The list structure.
 *
 * Metadata is contained here. A pointer to the first and last nodes in the list
 * allows for several operations to be performed more quickly. There is also
 * another pointer-to-node member variable for storing the location of a
 * "current" or active node that presumably will have operations performed on
 * it. "current" is only modified whenever a reference to it becomes invalid, or 
 * whenever sllist_step is called. Finally there is a size variable containing 
 * the total number of nodes. Note that the first index of the list is
 * considered index zero.
 */
struct sllist;

/**
 * Create a new list.
 *
 * Returns a pointer to a new, empty list. If allocation fails, returns NULL.
 */
struct sllist *sllist_create(void);

/**
 * Destroy a list.
 *
 * Frees the memory of the list struct and all associated nodes. The memory to
 * all the data in the list is also freed, thus we are operating under the
 * assumption that the data was dynamically allocated.
 */
void sllist_destroy(struct sllist *sllist);

/**
 * Accessor function to get a reference to the data in a node.
 */
void *snode_data(const struct snode *snode);

/**
 * Accessor function to get a reference to the next node of a node.
 */
struct snode *snode_next(const struct snode *snode);

/**
 * Accessor function to get a reference to the head of a list.
 */
struct snode *sllist_head(const struct sllist *sllist);

/**
 * Accessor function to get a reference to the tail of a list.
 */
struct snode *sllist_tail(const struct sllist *sllist);

/**
 * Accessor function to get a reference to the current node of a list.
 */
struct snode *sllist_current(const struct sllist *sllist);

/**
 * Accessor function to get the size of the list. 
 */
int sllist_size(const struct sllist *sllist);


/**
 * Prepend a node to the list:
 *
 * Adds a node to the front of the list. If allocation fails, returns -1,
 * otherwise returns 0.
 */
int sllist_push_front(struct sllist *sllist, void *data);

/**
 * Append node to a list.
 *
 * Adds a node to the end of the list. If allocation fails, returns -1,
 * otherwise returns 0.
 */
int sllist_push_back(struct sllist *sllist, void *data);

/**
 * Extract the first node.
 *
 * Remove the first node from the linked list, save a pointer to the data, free
 * the node (but do not free the data itself), and return a pointer to the data
 * so that it can be used. If the list is empty, returns NULL. If "current" is
 * popped, "current" is set to NULL.
 */
void *sllist_pop_front(struct sllist *sllist);

/**
 * Extract the last node.
 *
 * Remove the last node from the linked list, save a pointer to the data, free
 * the node (but do not free the data itself), and return a pointer to the data
 * so that it can be used. If the list is empty, returns NULL. If "current" is
 * popped, "current" is set to NULL.
 */
 void *sllist_pop_back(struct sllist *sllist);

/**
 * Step through a list.
 *
 * Changes the current node to the node after the current node. Returns 1 if
 * the current node is NULL.
 */
int sllist_step(struct sllist *sllist);

/**
 * Access data by index.
 *
 * Returns a pointer to the payload of the node at the location specified by the
 * passed index value. The passed index value is interpreted as an offset from
 * index zero, the first node of the list. Returns NULL if the list is empty or
 * the index is out of range.
 */
void *sllist_read_index(struct sllist *sllist, int index);

/**
 * Insert a node after the node at the specified index.
 *
 * Adds a node after the passed node. If allocation fails, returns -1. If the
 * node doesn't exist in the list, returns 1. Otherwise, returns 0.
 */
int sllist_insert_after(struct sllist *sllist, int index, void *data);

/**
 * Extract a node after the node at the specified index.
 *
 * Remove the specified node from the linked list, save a pointer to the data,
 * free the node (but do not free the data itself), and return a pointer to the
 * data so that it can be used. If the list is empty or the node doesn't exist
 * in the list, returns NULL. Attempting to extract after the tail will also
 * return NULL. If "current" is extracted, it will be set to null.
 */
void *sllist_extract_after(struct sllist *sllist, int index);

#endif
