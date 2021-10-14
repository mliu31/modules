/* htest1.c --- 
 * 
 * 
 * Author: Megan Y. Liu
 * Created: Wed Oct 13 10:08:06 2021 (-0400)
 * Version: 
 * 
 * Description: 
 * testing hashfile.c functions hopen, hclose, hput 
 */

#include <stdlib.h>
#include <stdio.h>
#include "hash.h"


typedef struct str_type {
	char* str;
} str_t;


str_t* makestr(char* input_str) {
	str_t* str = (str_t*) calloc(1, sizeof(str_t));
	str = (str_t*) input_str;

	return str; 
}


int main(void) {
	uint32_t htsize;
	char* message;
	int32_t successful_put;
	str_t* htentry; 

	htsize = 10;
	message = "hello world"; 
	htentry= makestr(message); 
	
	hashtable_t* htp = hopen(htsize); 
	
	if(htp == NULL) {
		printf("[Error: Failed to create hash table]");
		exit(EXIT_FAILURE); 
	}

	successful_put = hput(htp, htentry, "hello world", 11);
	if(successful_put != 0) {
		printf("[Error: Failed to add entry into hash table]");
		exit(EXIT_FAILURE); 
	}

	free(htentry); 
	hclose(htp); 
		
	exit(EXIT_SUCCESS); 
}
