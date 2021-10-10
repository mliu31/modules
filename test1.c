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

#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	queue_t* my_queue = qopen();

	if(my_queue == NULL) {
		printf("Qopen failed to make the queue\n");
		exit(EXIT_FAILURE);
	}

	qclose(my_queue);

	if(my_queue != NULL) {
		printf("Qclose failed to close the queue\n");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
	
}
