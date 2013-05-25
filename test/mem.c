#include "sllist.h"

int main(void)
{
        struct sllist *sllist;
        sllist = sllist_create();
        sllist_destroy(sllist);
}
