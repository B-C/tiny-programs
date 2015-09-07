#include <stdio.h>
#include <stdlib.h>

#include "hashtable.h"

#define BUCKET_NB 20

int main() {
  LinkedList* buckets[BUCKET_NB];
  for(int i = 0 ; i< BUCKET_NB ; i++)
	buckets[i] = NULL;

  HTable htable = {
	.TABLE_SIZE = BUCKET_NB,
	.table = buckets,
  };

  char * fname[20] = {
	"bertrand"
  };

  char * name[20] = {
	"chazot"
  };
	

  for(int i =  0 ; i < 1 ; i++) {
	ht_insert(&htable, name[i], fname[i]);
	ht_insert(&htable, fname[i], name[i]);
  }

  ht_print(&htable);

  /* for(int i =  0 ; i < 8 ; i++) { */
  /* 	printf("\n %s %s \n",name[i], (const char*)ht_find(&htable, name[i])); */
  /* 	printf("\n %s %s \n",fname[i], (const char*)ht_find(&htable, fname[i])); */
  /* } */

  printf("\ndone\n");
  return 0;
}


