/* test3.c --- 
 * 
 * 
 * Author: Alejandro A. Lopez Cochachi
 * Created: Sun Oct 10 12:26:20 2021 (-0400)
 * Version: 2
 * 
 * Description: Test file for queue. Tests qapply.
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


void printe(void* elementp) {
	printf("%d-->", *((int*)elementp)); 
}


int main(void) { 
	queue_t *my_queue = qopen();
	int int1, int2, int3; 
	int_t *intt1, *intt2, *intt3; 

	int1 = 1;
	int2 = 2;
	int3 = 3; 
	
	intt1 = makeint(int1);
	intt2 = makeint(int2);
	intt3 = makeint(int3);

	qput(my_queue, intt1);
	qput(my_queue, intt2);
  qput(my_queue, intt3);	

	qapply(my_queue, printe); 
	
 	qclose(my_queue);
	exit(EXIT_SUCCESS);

}
