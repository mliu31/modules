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

typedef struct real_helem_t {
	queue_t *queue;
	char *key;
} rhe_t;

hashtable_t *hopen(uint32_t hsize) {

	rhe_t *hp;

	if (!(hp = (rhe_t*)calloc(hsize, sizeof(rhe_t)))) {
		printf("[Error: calloc failed for hashtable]\n");
		return NULL;
	}

	for(int i = 0; i < hsize; i++) {
		hp[i].queue = qopen();
		hp[i].key = NULL;
	}
	
	return (hashtable_t*)hp; 
	
}

void hclose(hashtable_t *htp) {

	rhe_t *e;
	e = (rhe_t*)htp;
	
}

int main(void) {

	int32_t size = 17;
	
	hashtable_t* thingie = hopen(size);
	//qclose(((rhe_t*)thingie)[0].queue);
	//free(thingie);
	//hclose(thingie);

	return 0;
	
}
