/* hashfile.c --- 
 * 
 * 
 * Author: Agon Hoxha
 * Created: Sun Oct 10 17:45:07 2021 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "queue.h"
#include "queue.c"
#include "hash.h"
#include "hash.c" 

#define STARTING_ARR_CAPACITY 50


typedef struct real_helem_t {
	queue_t *queue;
	char *key;
} rhe_t;


typedef struct real_hashtable_t {
	rhe_t* elems_array[STARTING_ARR_CAPACITY]; 
	int max_len;
	int curr_len; 
	
} rht_t; 


static void printe(void* elementp) {
	printf("%d-->", *((int*)elementp));
}


hashtable_t *hopen(uint32_t hsize) {
	rht_t *hp;
	rhe_t *ep;
	
	if (!(hp = (rht_t*)calloc(1, sizeof(rht_t)))) {
		printf("[Error: calloc failed for hashtable]\n");
		return NULL;
	}

	hp->max_len = hsize;
	hp->curr_len = 0;
			
	for(int i = 0; i < hsize; i++) {
		if (!(ep = (rhe_t*)calloc(hsize, sizeof(rhe_t)))) {
			printf("[Error: calloc failed for hash element]\n");
			return NULL;
		}
		hp->elems_array[i] = ep;
		
		ep->queue = qopen();
		ep->key = NULL;
	}
	return (hashtable_t*)hp; 	
}


void hclose(hashtable_t *htp) {
	rht_t *hp;
	rhe_t *ep;

	hp = (rht_t*)htp;

	for(int i = 0; i < hp->max_len; i++) {
		ep = hp->elems_array[i];
		qclose(ep->queue);
		free(ep);
 	}
	free(hp);
}


int32_t hput(hashtable_t *htp, void *ep, const char *key, int keylen) {
	// when putting new elem in ht, need to check if ht_length == num_entries; double ht_length and copy elem into new one -- amortized O(1) runtime
	//  key and keylen (arbitrary str--we can choose) into our SuperFastHash function
	
	// cast htp as rht_t
	rht_hp *hp;
	int hashvalue; 

	hp = (rht_hp*)htp;
	
	// call super fast hash and return the value in an int var
	//   param in superfast hash = param in hput: 
	//   data = key
	//   len = keylen
	//   tablesize = rht->max_len

	
	// index to that returned value in the hash table and store put the ep into the queue there 
}


void happly(hashtable_t *htp, void (*fn)(void* ep)) {
	//TODO
}


void *hsearch(hashtable_t *htp,
							bool (*searchfn)(void* elementp, const void* searchkeyp),
							const char *key,
							int32_t keylen) {
	//TODO
}


void *hremove(hashtable_t *htp,
							bool (*searchfn)(void* elementp, const void* searchkeyp),
							const char *key,
							int32_t keylen) {
	//TODO
}


int main(void) {

	int32_t size = 3;
	
	hashtable_t* hashtable = hopen(size);
	hclose(hashtable);

  exit(EXIT_SUCCESS);
	
}
