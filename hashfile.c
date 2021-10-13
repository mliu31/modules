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
#include "hash.h"
#include "hash.c"


typedef struct real_hashtable_t {
	queue_t** table; 
	uint32_t len;
} rht_t; 


hashtable_t *hopen(uint32_t hsize) {
	rht_t *hp;
	
	if (!(hp = (rht_t*)calloc(1, sizeof(rht_t)))) {
		printf("[Error: malloc failed for hashtable]\n");
		return NULL;
	}

	if (!(hp->table = (queue_t**)calloc(hsize, sizeof(queue_t*)))) {
		printf("[Error: calloc failed for table]\n");
		return NULL;
	}

	hp->len = hsize;
	
	for(int i = 0; i < hp->len; i++) {
	  hp->table[i] = qopen();
	}

	return (hashtable_t*)hp; 	
}


void hclose(hashtable_t *htp) {
	rht_t *hp;

	hp = (rht_t*)htp;

	for(int i = 0; i < hp->len; i++) {
	  qclose(hp->table[i]);
	}

	free(hp->table);
	free(hp);
}


int32_t hput(hashtable_t *htp, void *ep, const char *key, int keylen) {

	rht_t *hp;
	uint32_t hashnumber;

	hp = (rht_t*)htp;
	hashnumber = SuperFastHash(key, keylen, hp->len);

	return qput(hp->table[hashnumber], ep);
} 


void printe(void *h) {
	puts((char*)h);
}


void happly(hashtable_t *htp, void (*fn)(void* ep)) {
	rht_t *hp;

	hp = (rht_t*)htp;

	for(int i = 0; i < hp->len; i++) {
	  qapply(hp->table[i], fn);
	}
}


void *hsearch(hashtable_t *htp,
							bool (*searchfn)(void* elementp, const void* searchkeyp),
							const char *key,
							int32_t keylen) {
	rht_t *hp;
	uint32_t hashnumber;

	hp = (rht_t*)htp;
	hashnumber = SuperFastHash(key, keylen, hp->len);

	return qsearch(hp->table[hashnumber], searchfn, key);
}


void *hremove(hashtable_t *htp,
							bool (*searchfn)(void* elementp, const void* searchkeyp),
							const char *key,
							int32_t keylen) {
	rht_t *hp;
	uint32_t hashnumber;

	hp = (rht_t*)htp;
	hashnumber = SuperFastHash(key, keylen, hp->len);

	return qremove(hp->table[hashnumber], searchfn, key);
}
