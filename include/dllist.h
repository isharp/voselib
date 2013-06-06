#ifndef DLLIST_H
#define DLLIST_H

struct dnode {
        void *data;
        struct dnode *prev;
        struct dnode *next;
}

void dllist_init(struct dnode *dnode) {
}


#endif
