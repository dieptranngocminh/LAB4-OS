
#include <stdlib.h>
#include "queue.h"
#include <pthread.h>

/* Remember to initilize the queue before using it */
void initialize_queue(struct pqueue_t * q) {
	q->head = q->tail = NULL;
	pthread_mutex_init(&q->lock, NULL);
}

/* Return non-zero if the queue is empty */
int empty(struct pqueue_t * q) {
	return (q->head == NULL);
}

/* Get PCB of a process from the queue (q).
 * Return NULL if the queue is empty */
struct pcb_t * de_queue(struct pqueue_t * q) {
	struct pcb_t * proc = NULL;
	// TODO: return q->head->data and remember to update the queue's head
	// and tail if necessary. Remember to use 'lock' to avoid race
	// condition
	
	// YOUR CODE HERE
	// head
	pthread_mutex_lock(&(q->lock));
	if(q == NULL){
		return NULL;//pcb_t is pointer
	}
	if(q->head != NULL){
		proc = q->head->data;
		struct qitem_t * tmp = q->head;
		q->head = q->head->next;
		free(tmp);
		if(q->head == NULL){ //update tail
			q->tail == NULL;
		}
	}
	pthread_mutex_unlock(&(q->lock));
	return proc;
}

/* Put PCB of a process to the queue. */
void en_queue(struct pqueue_t * q, struct pcb_t * proc) {
	// TODO: Update q->tail.
	// Remember to use 'lock' to avoid race condition
	
	// YOUR CODE HERE
	//tail
	pthread_mutex_lock(&(q->lock));
	if(q == NULL){
		return;
	}
	if(q->head == NULL){

		q->head = q->tail = (struct qitem_t*) malloc(sizeof(struct qitem_t));
		q->tail->data = proc;

	}
	else{
		q->tail->next = (struct qitem_t*) malloc(sizeof(struct qitem_t));
		q->tail = q->tail->next;
		q->tail->data = proc;
	}
	pthread_mutex_unlock(&(q->lock));
}



