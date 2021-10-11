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


void printe(void* element_p) {

	printf("%d\n", (((int_t*)(element_p))->number));

}

int main(void) { 
	queue_t *my_queue_1 = qopen();
	queue_t *my_queue_2 = qopen();
	queue_t *my_queue_3 = qopen();
	queue_t *my_queue_4 = qopen();
	queue_t *my_queue_5 = qopen();
	queue_t *my_queue_6 = qopen();
	queue_t *my_queue_7 = qopen();
	queue_t *my_queue_8 = qopen();
	
	int int1, int2, int3, int4; 
	int_t *intt1, *intt2, *intt3, *intt4;
	
	int1 = 1;
	int2 = 2;
	int3 = 3;
	int4 = 4;
	
	intt1 = makeint(int1);
	intt2 = makeint(int2);
	intt3 = makeint(int3);
	intt4 = makeint(int4);

	
	// search for elem in empty queue
	qconcat(my_queue_1, my_queue_2); 
	qapply(my_queue_1, printe);
	
	qput(my_queue_3, intt3);

	// search for existing elem in non-empty queue
	qconcat(my_queue_4, my_queue_3);
	qapply(my_queue_4, printe);
	
	qput(my_queue_5, intt4);
	
	// search for non-existent elem in non-empty queue
	qconcat(my_queue_5, my_queue_6);
	qapply(my_queue_5, printe);

	qput(my_queue_7, intt1);
	qput(my_queue_8, intt2);
	
	qconcat(my_queue_7, my_queue_8);
	qapply(my_queue_7, printe);

	free(intt1);
	free(intt2);
	free(intt3);
	free(intt4);
 	qclose(my_queue_7);
	qclose(my_queue_5);
	qclose(my_queue_4);
	qclose(my_queue_1);
	
	exit(EXIT_SUCCESS);

}
