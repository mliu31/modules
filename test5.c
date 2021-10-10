/* test5.c --- 
 * 
 * 
 * Author: Alejandro A. Lopez Cochachi
 * Created: Sun Oct 10 14:09:27 2021 (-0400)
 * Version: 5
 * 
 * Description: Test file for queue. Testing concat
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

bool srch(void* elementp, const void* keyp) {

	int* a = ((int*)(elementp));
	int* b = ((int*)(keyp));

	if(*a == *b) {
		return true;
	} else {
		return false;
	}
}

int main(void) {

	queue_t *first_queue = qopen();
	queue_t *second_queue = qopen();
	int first_el, second_el, third_el;
	rqe_t *search_return;
	
	first_el = 1;
	second_el = 2;
	third_el = 3;

	qput(first_queue, &first_el);
	qput(first_queue, &second_el);
	qput(second_queue, &third_el);

	qconcat(first_queue, second_queue);
	search_return = (rqe_t*)qsearch(first_queue, srch, third_el); 

	if(search_return != third_el) {
		printf("Concat failed\n");
		exit(EXIT_FAILURE);
	}
	
	qclose(first_queue);
	exit(EXIT_SUCCESS);
}
