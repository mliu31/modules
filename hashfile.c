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
	// when putting new elem in ht, need to check if ht_length == num_entries; double ht_length and copy elem into new one -- amortized O(1) runtime
	//  key and keylen (arbitrary str--we can choose) into our SuperFastHash function
	
	// cast htp as rht_t
	rht_t *hp;
	uint32_t hashnumber;

	hp = (rht_t*)htp;
	hashnumber = SuperFastHash(key, keylen, hp->len);

	return qput(hp->table[hashnumber], ep);
	// call super fast hash and return the value in an int var
	//   param in superfast hash = param in hput: 
	//   data = key
	//   len = keylen
	//   tablesize = rht->max_len

	
	// index to that returned value in the hash table and store put the ep into the queue there 
} 

void printe(void *h) {
	puts((char*)h);
}

bool keysearch(void* elementp, const void* searchkeyp) {

	char *elp = (char*)elementp;
	char *kep = (char*)searchkeyp;

	if(strcmp(elp, kep) == 0)
		return true;
	else
		return false;

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

/*
void *hremove(hashtable_t *htp,
							bool (*searchfn)(void* elementp, const void* searchkeyp),
							const char *key,
							int32_t keylen) {
	//TODO
}
*/

int main(void) {

	uint32_t size = 40;
	char greeting[] = "hello";
	
	hashtable_t* hashtable = hopen(size);
	hput(hashtable, greeting, "hello", 5);
	happly(hashtable, printe);
	char* whatever = (char*)hsearch(hashtable, keysearch, "hello", 5);
	puts(whatever);
	hclose(hashtable);

  exit(EXIT_SUCCESS);
	
}
