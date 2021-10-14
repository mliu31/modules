/* htest2.c --- 
 * 
 * 
 * Author: Alejandro A. Lopez Cochachi
 * Created: Wed Oct 13 13:10:55 2021 (-0400)
 * Version: 2
 * 
 * Description: Testing happly and hsearch.
 * 
 */

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

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

int main(void) {
	uint32_t htsize = 10;
	char message[] = "hello world";
	int32_t put;
	
	hashtable_t* htp = hopen(htsize);
	
	put = hput(htp, message, "hello world", 11);
	happly(htp, printe);

	char* search_result = (char*)hsearch(htp, keysearch, "hello world", 11);

	if (strcmp(search_result, "hello world") != 0) {
		printf("[Error: Failed to search the right entry in the hash table]");
	}
	
	hclose(htp);
	exit(EXIT_SUCCESS);
	
}
