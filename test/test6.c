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
	queue_t *my_queue1 = qopen();
	queue_t *my_queue2 = qopen();

	int int1;
	int_t *intt1; 

	int1 = 1;

	intt1 = makeint(int1);
	
	/*queue_t *queue_soln1 = qopen();
	queue_t *queue_soln2 = qopen();
	queue_t *queue_soln3 = qopen();
	queue_t *queue_soln4 = qopen();
	queue_t *queue_soln5 = qopen();
	queue_t *queue_soln6 = qopen();
	queue_t *queue_soln7 = qopen();
	
	int int1, int2, int3; 
	int_t *intt1, *intt2, *intt3;
	
	int1 = 1;
	int2 = 2;
	int3 = 3; 
	
	intt1 = makeint(int1);
	intt2 = makeint(int2);
	intt3 = makeint(int3);
	
	
	// 1. both q's NULL
	qconcat(my_queue1, my_queue2);
	
	// 2. q1 null, q2 empty

	// 3. q1 empty, q2 null

	// 4. q1 filled, q2 empty

	// 5. q1 empty, q2 filled

	// 6. q1 filled, q2 NULL

	// 7. q1 NULL, q2 empty

	// 8. both q's empty

	// 9. both q's filled
	
	*/
	
	qput(my_queue2, intt1);
	qconcat(my_queue1, my_queue2);
	qapply(my_queue1, printe);
	
	free(intt1);
 	qclose(my_queue1);
	
	exit(EXIT_SUCCESS);

}
