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

int main(void) {
	queue_t *my_queue = qopen();
	int first_el, second_el, third_el;
	int32_t first_put, second_put, third_put;
	void *first_get, *second_get, *third_get;
	
	first_el = 1;
	second_el = 2;
	third_el = 3;

	first_put = qput(my_queue, &first_el);
	second_put = qput(my_queue, &second_el);
	third_put = qput(my_queue, &third_el);
	
	if(first_put != 0 || second_put != 0 || third_put != 0) {
		printf("Qput failed\n");
		exit(EXIT_FAILURE);
	}

	first_get = qget(my_queue);
	second_get = qget(my_queue);
	third_get = qget(my_queue);

	if(first_get == NULL || second_get == NULL || third_get == NULL) {
		printf("Qget failed\n");
		exit(EXIT_FAILURE);
	}

	qclose(my_queue);
	exit(EXIT_SUCCESS);

}
