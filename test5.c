/* test5.c --- 
 * 
 * 
 * Author: Alejandro A. Lopez Cochachi
 * Created: Sun Oct 10 12:26:20 2021 (-0400)
 * Version: 2
 * 
 * Description: Test file for queue. Tests qremove. 
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
	int int1, int2, int3, int4;  
	int_t *intt1, *intt2, *intt3, *intt4, *sought_intt;
	
	int1 = 1;
	int2 = 1;
	int3 = 3;
	int4 = 4; 
	
	intt1 = makeint(int1);
	intt2 = makeint(int2);
	intt3 = makeint(int3);
	intt4 = makeint(int4);
	
	// 1. remove non-existent elem from empty queue
	sought_intt = qremove(my_queue, srch, intt1); 

	qput(my_queue, intt1); // q: 1
		
	// 2. remove existing elem from single-element queue	
	sought_intt = qremove(my_queue, srch, intt1); 
	if (sought_intt->number != int1) {
		printf("[Error: qsearch failed test 2]\n"); 
		exit(EXIT_FAILURE); 
	}
	qput(my_queue, intt1); // q: 1
 	
	// 3. remove non-existent elem from single-element queue
	sought_intt = qremove(my_queue, srch, intt2); 
	if (sought_intt == NULL) {
		printf("[Error: qsearch failed test 3]\n"); 
		exit(EXIT_FAILURE); 
	}
	qput(my_queue, intt2); 
	qput(my_queue, intt3); // q: 1, 2, 3
	
	// 4. remove existing elem from front of multi-elem queue
	sought_intt = qremove(my_queue, srch, intt1); 
	if (sought_intt->number != int1) {
		printf("[Error: qsearch failed test 4]\n"); 
		exit(EXIT_FAILURE); 
	}
	qput(my_queue, intt1); // 2, 3, 1
	
	// 5. remove existing elem from middle of multi-elem queue
	sought_intt = qremove(my_queue, srch, intt3); 
	if (sought_intt->number != int3) {
		printf("[Error: qsearch failed test 5]\n"); 
		exit(EXIT_FAILURE); 
	}
	qput(my_queue, intt3);  // 2, 1, 3

	
	// 6. remove existing elem from back of multi-elem queue
	sought_intt = qremove(my_queue, srch, intt3); 
	if (sought_intt->number != int3) {
		printf("[Error: qsearch failed test 6]\n"); 
		exit(EXIT_FAILURE); 
	}
	qput(my_queue, intt3);  // 2, 1, 3

	
	// 7. remove non-existent elem from multi-elem queue
	sought_intt = qremove(my_queue, srch, intt4); 
	if (sought_intt != NULL) {
		printf("[Error: qsearch failed test 7]\n"); 
		exit(EXIT_FAILURE); 
	}	

	free(intt1);
	free(intt2);
	free(intt3);
	free(intt4);
	
 	qclose(my_queue);
	exit(EXIT_SUCCESS);

}
