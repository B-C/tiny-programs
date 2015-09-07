#ifndef LLIST_H
#define LLIST_H

struct LinkedList {
  void * item;
  struct LinkedList *next;
};
typedef struct LinkedList LinkedList;

const void* ll_get(const LinkedList* l, 
				   int(* f)(const void * arg, const void * item), 
				   const void * f_arg);

LinkedList* ll_add(LinkedList* tail, void *item);

// free item too
void ll_free(LinkedList* l);
void ll_soft_free(LinkedList* l);
#endif
