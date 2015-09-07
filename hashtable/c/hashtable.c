#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"

struct Tuple {
  const void* item;
  const char* key;
};
typedef struct Tuple Tuple;

static void ll_print(LinkedList *l);
static unsigned int aux_hasing(unsigned int h, char k);
static unsigned int hashing(const char* key, unsigned int max);
int ll_search(const void* key, const void* tuple);


void ht_insert(HTable *h, const char* key, const void * item) {
  unsigned int hkey = hashing(key, h->TABLE_SIZE);
  LinkedList *list = h->table[hkey];
  Tuple *tuple =(Tuple*)malloc(sizeof(Tuple));

  tuple->item = item;
  tuple->key = key;

  h->table[hkey] = ll_add(list, tuple);
}

const void* ht_find(const HTable *h, const char* key) {
  unsigned int hkey = hashing(key, h->TABLE_SIZE);
  LinkedList *list = h->table[hkey];

  if(list == NULL)
	return NULL;
  else
	return ((Tuple*)ll_get(list, ll_search, key))->item;
  return NULL;
}

int ll_search(const void* key, const void* tuple) {
  return (strcmp((char*)key, ((Tuple*)tuple)->key)==0);
}

void ht_print(const HTable *h) {
  printf("________________________________\n");
  for(int i = 0 ; i < h->TABLE_SIZE ; i++) {
	printf("%d: ", i);
	ll_print(h->table[i]);
	printf("\n");
  }
  printf("________________________________\n");
}

static void ll_print(LinkedList * list) {
  while(list) {
	Tuple *t = (Tuple *) list->item;
	printf("%s %s\t", t->key, (const char *) t->item);
	list = list->next;
  }
}

static unsigned int hashing(const char* key, unsigned int max) {
  unsigned int hkey = 0;

  while(*key)
	hkey = aux_hasing(hkey, *key++);
  hkey%=max;
  return hkey;
}

static unsigned int aux_hasing(unsigned int h, char k) {
  int hightorder = h & 0xf8000000;
  h = h << 5;
  h = h^(hightorder >> 27);
  h = h ^ k;

  return h;
}
