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


int main(void) {
	uint32_t htsize = 10;
	char message[] = "hello world"; 
	int32_t removed_res; 
	
	hashtable_t* htp = hopen(htsize); 
	
	if(htp == NULL) {
		printf("[Error: Failed to create hash table]");
		exit(EXIT_FAILURE); 
	}

	removed_res = hput(htp, message, "hello world", 11);
	if(removed_res != 0) {
		printf("[Error: Failed to add entry into hash table]");
		exit(EXIT_FAILURE); 
	}
	
	hclose(htp); 
		
	exit(EXIT_SUCCESS); 
}
