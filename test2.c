/* test2.c --- 
 * 
 * 
 * Author: Alejandro A. Lopez Cochachi
 * Created: Sun Oct 10 12:26:20 2021 (-0400)
 * Version: 2
 * 
 * Description: Test file for queue. Tests qput and qget.
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

		
int main(void) {
	// testing qput 
	queue_t *my_queue = qopen();
	int int1, int2, int3; 
	int_t *intt1, *intt2, *intt3; 
	int first_put, second_put, third_put;
	int_t *first_get, *second_get, *third_get;

	int1 = 1;
	int2 = 2;
	int3 = 3; 
	
	intt1 = makeint(int1);
	intt2 = makeint(int2);
	intt3 = makeint(int3);

	first_put = qput(my_queue, intt1);
	second_put = qput(my_queue, intt2);
  third_put = qput(my_queue, intt3);	

	if(first_put != 0 || second_put != 0 || third_put != 0) {
		printf("[Error: Qput failed]\n");
		exit(EXIT_FAILURE);
	}

	// testing qget
	first_get = qget(my_queue);
	second_get = qget(my_queue);
	third_get = qget(my_queue);

	if(first_get == NULL || second_get == NULL || third_get == NULL) {
		printf("[Error: Qget failed]\n");
		exit(EXIT_FAILURE);
	}
	
 	qclose(my_queue);
	exit(EXIT_SUCCESS);

}
