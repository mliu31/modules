/* test1.c --- 
 * 
 * 
 * Author: Alejandro A. Lopez Cochachi
 * Created: Thu Oct  7 10:39:28 2021 (-0400)
 * Version: 1
 * 
 * Description: Test file for queue. Testing qopen and qclose.
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int main(void) {
	queue_t* my_queue = qopen();

	if(my_queue == NULL) {
		printf("[Error: failed to make the queue]\n");
		exit(EXIT_FAILURE);
	}

	qclose(my_queue);

	if(my_queue != NULL) {
		printf("[Error: failed to close the queue]\n");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
	
}
