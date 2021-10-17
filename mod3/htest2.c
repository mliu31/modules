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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

typedef struct str_type {
	char* str;
} str_t;

str_t* makestr(char* input_str) {
	str_t* something = (str_t*) calloc(1, sizeof(str_t));
	something->str = input_str;

	return something;
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

int main(void) {
	uint32_t htsize;
	char* message;
	str_t* htentry;

	htsize = 10;
	message = "hello world";
	htentry = makestr(message);
	
	hashtable_t* htp = hopen(htsize);
	
	hput(htp, htentry->str, "hello world", 11);
	happly(htp, printe);

	char* search_result = (char*)hsearch(htp, keysearch, "hello world", 11);

	if (strcmp(search_result, "hello world") != 0) {
		printf("[Error: Failed to search the right entry in the hash table]");
		exit(EXIT_FAILURE);
	}

	free(htentry);
	hclose(htp);
	exit(EXIT_SUCCESS);
	
}
