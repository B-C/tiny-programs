#include <stdlib.h>
#include "llist.h"

#include <stdio.h>

const void* ll_get(const LinkedList* l, 
				   int(* f)(const void * arg, const void * item), 
				   const void * f_arg) {
  if(l == NULL)
	return NULL;
  
  if(f(f_arg, l->item))
	return l->item;

  return ll_get(l->next, f, f_arg);
}

LinkedList* ll_add(LinkedList* tail, void *item) {
  LinkedList *head = (LinkedList*) malloc(sizeof(LinkedList));

  head->item = item;
  head->next = tail;

  return head;
}


void ll_free(LinkedList* l) {
  if(l == NULL)
	return;

  ll_free(l->next);
  l->next = NULL;

  free(l->item);
  l->item = NULL;
  free(l);
}

void ll_soft_free(LinkedList* l) {
  if(l == NULL)
	return;

  ll_free(l->next);
  l->next = NULL;

  free(l);
}
