/* queue.c --- 
 * 
 * 
 * Author: Megan Y. Liu
 * Created: Wed Oct  6 09:08:30 2021 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"


typedef struct real_qelem_t {
	struct real_qelem_t *next; 
	void *data;
} rqe_t; 


typedef struct real_queue_t {
	rqe_t *front;
	rqe_t *back;  
} rq_t; 


queue_t* qopen(void) {
  rq_t *qp;

  if (!(qp = (rq_t*)malloc(sizeof(rq_t)))) {
    printf("[Error: malloc failed for queue]\n");
    return NULL; 
  }

	qp->front=NULL;
	qp->back=NULL;

  return (queue_t*)qp; 
}


void qclose(queue_t *qp) {
  free(qp); 
} 


int32_t qput(queue_t* qp, void* elementp) {
	rq_t *rq;
	rqe_t *rqe;

	rq = (rq_t*)qp;	

	if (!(rqe = (rqe_t*)malloc(sizeof(rqe_t)))) {
		printf("[Error: malloc failed for queue element]\n");
		return -1;
	}

	rqe->data = elementp;
		
	
	if (rq->back==NULL && rq->front==NULL) 
		rq->front = rqe; 
	else 
		rq->back->next = rqe; 
	rq->back = rqe; 
	return 0; 
}

void* qget(queue_t *qp) {

	rq_t *rq;

	rq = (rq_t*)qp;

	if (rq->back==NULL && rq->front==NULL) {
		printf("Cannot get() element from empty queue\n");
		return NULL;
	}
	else if(rq->back==rq->front) {
		rqe_t *placeholder;

		placeholder = rq->front;
		rq->front = NULL;
		rq->back = NULL;

		return placeholder;
	}
	else {
		rqe_t *placeholder;

		placeholder = rq->front;
		rq->front = rq->front->next;

		return placeholder;
	}
	
}

static void print_queue(queue_t* qp) {
	rqe_t* e;
	rq_t *rq;
	
	rq = (rq_t*)qp;  
	e = rq->front;

	if(e == NULL){
		printf("Empty queue\n");
		return;
	}
	
	while(e != NULL){
		printf("Value: %d\n",*((int*)e->data));
		e = e->next;
	}
}

int main(void) {
	queue_t* my_queue = qopen();
	int num_pt, second_num;

	num_pt = 3;
	second_num = 10;
	
	qput(my_queue,&num_pt);
	qput(my_queue, &second_num);
	print_queue(my_queue);
	
	qget(my_queue);
	print_queue(my_queue);
	
	exit(EXIT_SUCCESS);
}
