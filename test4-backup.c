/* test4.c --- 
 * 
 * 
 * Author: Alejandro A. Lopez Cochachi
 * Created: Sun Oct 10 13:57:06 2021 (-0400)
 * Version: 4
 * 
 * Description: Test file for queue. Testing qsearch and qremove
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

	queue_t *my_queue = qopen();
	rqe_t *search_return, *remove_return;
	int first_el, second_el, third_el;
		
	first_el = 1;
	second_el = 2;
	third_el = 3;

	qput(my_queue, &first_el);
	qput(my_queue, &second_el);
	qput(my_queue, &third_el);

	search_return = (rqe_t*)qsearch(my_queue, srch, first_el);

	if(search_return != first_el) {
		printf("Search failed\n");
		exit(EXIT_FAILURE);
	}

	remove_return = (rqe_t*)qremove(my_queue, srch, first_el);

	if(remove_return != first_el) {
		printf("Remove failed\n");
		exit(EXIT_FAILURE);
	}
	
	qclose(my_queue);
	exit(EXIT_SUCCESS);
}
