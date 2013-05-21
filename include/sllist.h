#ifndef SLLIST_H
#define SLLIST_H

/** 
 * @file sllist.h
 * @brief Stuctures and functions for a singly-linked list API.
 *
 * The API presented here is intended to be an opaque implementation. The user
 * is provided with several different functions to manipulate lists and their
 * contents.
 */

/**
 * The node structure.
 * 
 * The purpose of this structure is to actually hold the data or "payload" to be
 * stored in the list. The nodes are connected sequentially, and thus each node
 * requires a second field to store the address of the next node.
 */
struct lnode;

/**
 * The list structure.
 * 
 * Metadata is contained here. A pointer to the first and last nodes in the list
 * allows for several operations to be performed more quickly. There is also
 * another pointer-to-node member variable for storing the location of a
 * "current" or active node that presumably will have operations performed on
 * it. Finally there is a size variable containing the total number of nodes.
 * Note that the first index of the list is considered index zero.
 */
struct sllist;

/**
 * Create a new list.
 *
 * Returns a pointer to a new, empty list. If allocation fails, returns NULL.
 */
struct sllist* sllist_create(void);

/**
 * Destroy a list.
 * 
 * Frees the memory of the list struct and all associated nodes.
 */
void sllist_destroy(struct sllist *sllist); 

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
 * Step through a list.
 * 
 * Changes the current node to the node after the current node. Returns 1 if 
 * stepping is impossible, such as when the current node is NULL or at the very
 * end of the list. Otherwise, returns 0. 
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
void* sllist_read_index(struct sllist *sllist, int index);

/**
 * Access data by node
 *
 * Returns a pointer to the payload of the passed node.
 */
void* sllist_read_node(struct sllist *sllist, struct lnode *lnode);

/**
 * Obtain a pointer to a node by index.
 * 
 * Returns a pointer to the node at the location specified by the passed index
 * value. The passed index value is interpreted as an offset from index zero,
 * the first node of the list. Returns NULL if the list is empty or the index is
 * out of range.
 */
struct lnode* sllist_find(struct sllist *sllist, int index);

/**
 * Insert a node after a specified node.
 * 
 * Adds a node after the passed node. If allocation fails, returns -1, 
 * otherwise returns 0.
 */
int sllist_insert_after(struct sllist *sllist, struct lnode *lnode, void *data);

/**
 * Extract the first node.
 * 
 * Remove the first node from the linked list, save a pointer to the data, free 
 * the node (but do not free the data itself), and return a pointer to the data 
 * so that it can be used. If the list is empty or the node doesn't exist in the
 * list, returns NULL.
 */
void* sllist_pop_front(struct sllist *sllist);

/**
 * Extract the last node.
 * 
 * Remove the last node from the linked list, save a pointer to the data, free 
 * the node (but do not free the data itself), and return a pointer to the data 
 * so that it can be used. If the list is empty or the node doesn't exist in the
 * list, returns NULL.
 */
 void* sllist_pop_back(struct sllist *sllist);

/**
 * Extract a specified node.
 * 
 * Remove the specified node from the linked list, save a pointer to the data, 
 * free the node (but do not free the data itself), and return a pointer to the
 * data so that it can be used. If the list is empty or the node doesn't exist
 * in the list, returns NULL. 
 */	
void* sllist_extract_after(struct sllist *sllist, struct lnode *lnode);

/**
 * Access data of the first node.
 * 
 * Returns a pointer to the data field of the first node. If the list is empty,
 * the function returns NULL.
 */
void* sllist_read_front(struct sllist *sllist);

/**
 * Access data of the last node.
 * 
 * Returns a pointer to the data field of the last node. If the list is empty,
 * the function returns NULL.
 */
void* sllist_read_back(struct sllist *sllist);

#endif
