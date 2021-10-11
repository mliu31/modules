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
#include "list.h"
#include "hash.h"

#define STARTING_ARR_CAPACITY 20; 

typedef struct real_helem_t {
	queue_t *queue;
	char *key;
} rhe_t;


typedef struct real_hashtable_t {
	rhe_t* elems_array[STARTING_ARR_CAPACITY];
	// when putting new elem in ht, need to check if ht_length == num_entries; double ht_length and copy elem into new one -- amortized O(1) runtime
	int max_len;
	int curr_len; 
	
} rht_t; 


hashtable_t *hopen(uint32_t hsize) {
	rht_t *hp;

	if (!(hp->elems_array = (rht_t*)calloc(hsize, sizeof(rhe_t)))) {
		printf("[Error: calloc failed for hashtable]\n");
		return NULL;
	}

	hp->max_len = hsize;
	hp->curr_len = 0; 
	
	for(int i = 0; i < hsize; i++) {
		((hp->elems_array)[i]).queue = qopen();
		((hp->elems_array)[i]).key = NULL;
	}
	
	return (hashtable_t*)hp; 
	
}

void hclose(hashtable_t *htp) {

	// loop thru each elem in hash (rht_t) ht->elem_array
	// create rhe_t elem 
	// free queue and key

	// free elems_array
	// free ht
	
	rhe_t *e;
	e = (rhe_t*)htp;
	
	
	
}

int main(void) {

	int32_t size = 10;
	
	hashtable_t* hashtable = hopen(size);
	//qclose(((rhe_t*)thingie)[0].queue);
	//free(thingie);
	//hclose(thingie);

	return 0;
	
}
