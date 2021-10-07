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

	qp->front=NULL;
	qp->back=NULL;
	
  if (!(qp = (rq_t*)malloc(sizeof(rq_t)))) {
    printf("[Error: malloc failed for queue]\n");
    return NULL; 
  }

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



int main(void) {}
