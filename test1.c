/* test1.c --- 
 * 
 * 
 * Author: Alejandro A. Lopez Cochachi
 * Created: Thu Oct  7 10:39:28 2021 (-0400)
 * Version: 1
 * 
 * Description: Test file for queue
 * 
 */

#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	printf("Here");
	queue_t* my_queue = qopen();

	if(my_queue == NULL) {
		printf("Failed");
		exit(EXIT_FAILURE);
	} else{
		printf("Success");
		exit(EXIT_SUCCESS);
	}
}
