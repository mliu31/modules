/* test3.c --- 
 * 
 * 
 * Author: Alejandro A. Lopez Cochachi
 * Created: Sun Oct 10 12:39:34 2021 (-0400)
 * Version: 3
 * 
 * Description: Test file for queue. Testing qapply
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void print_element(void* element_p) {
	printf("%d-->", *((int*)element_p));
}

int main(void) {
	queue_t *my_queue = qopen();
	int first_el, second_el, third_el;
	int32_t first_put, second_put, third_put;

	first_el = 1;
	second_el = 2;
	third_el = 3;

	first_put = qput(my_queue, &first_el);
	second_put = qput(my_queue, &second_el);
	third_put = qput(my_queue, &third_el);

	qapply(my_queue, printe);
	qclose(my_queue);
	exit(EXIT_SUCCESS);
}
