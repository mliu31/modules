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

	int32_t thing;
	int int1; 
	int_t *intt1;
	
	int1 = 1;
	
	intt1 = makeint(int1);

	thing = qput(my_queue_2, intt1);
	qconcat(my_queue_1, my_queue_2);
	qapply(my_queue_1, printe);
	
	free(intt1);
 	qclose(my_queue_1);
	
	exit(EXIT_SUCCESS);

}
