/* test4.c --- 
 * 
 * 
 * Author: Alejandro A. Lopez Cochachi
 * Created: Sun Oct 10 12:26:20 2021 (-0400)
 * Version: 2
 * 
 * Description: Test file for queue. Tests qsearch. 
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

typedef struct int_type {
	int number;
} int_t; 


int_t* makeint(int k) {
	int_t* integer_package = (int_t*)calloc(1, sizeof(int_t));
	integer_package->number = k;

	return integer_package; 
}


bool srch(void* elementp, const void* keyp) {
	int_t *a = ((int_t*)(elementp));
	int_t *b = ((int_t*)(keyp));

	if (a->number == b->number)
		return true;
	else
		return false; 
}


int main(void) { 
	queue_t *my_queue = qopen();
	int int1, int2, int3; 
	int_t *intt1, *intt2, *intt3, *sought_intt;
	
	int1 = 1;
	int2 = 1;
	int3 = 3; 
	
	intt1 = makeint(int1);
	intt2 = makeint(int2);
	intt3 = makeint(int3);

	// search for elem in empty queue
	sought_intt = qsearch(my_queue, srch, intt1); 
	if (sought_intt != NULL) {
		printf("[Error: qsearch failed 1\n]"); 
		exit(EXIT_FAILURE); 
	}
	
	qput(my_queue, intt1);
	qput(my_queue, intt2);	

	// search for existing elem in non-empty queue
	sought_intt = qsearch(my_queue, srch, intt1); 
	if (sought_intt != intt1) {
		printf("[Error: qsearch failed 2\n]"); 
		exit(EXIT_FAILURE);
	}

	
	// search for non-existent elem in non-empty queue
	sought_intt = qsearch(my_queue, srch, intt3); 
	if (sought_intt != NULL) {
		printf("[Error: qsearch failed 3\n]"); 
		exit(EXIT_FAILURE); 
	} 
		
	free(intt1);
	free(intt2);
	free(intt3);
	
	qclose(my_queue);
	exit(EXIT_SUCCESS);

}
