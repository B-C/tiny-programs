#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "llist.h"

struct HTable {
  const int TABLE_SIZE;
  LinkedList* *table;
};

typedef struct HTable HTable;

void ht_insert(HTable *h, const char* key, const void * item);
const void* ht_find(const HTable *h, const char* key);

// Debug
void ht_print(const HTable *h);



#endif
