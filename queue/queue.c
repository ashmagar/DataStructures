#include "queue.h"


struct queue* createQueue()
{
  struct queue *q = malloc(sizeof(struct queue));
  q->que = createDLinkedList();
  return q;

}

//push item onto the queue
void pushQueue(struct queue *q,struct data *dta)
{
	addBack(q->que,dta);
}

//get item from top of queue
struct data* top(struct queue *q)
{
	return(getFront(q->que));
}

//pop item from the queue
void popQueue(struct queue *q)
{
	removeFront(q->que);
}

//test if queue is empty.  return 1 if empty and 0 is not
int isEmptyQueue(struct queue *q)
{
	return(isEmpty(q->que));
}

//print queue.  You have to print from the queue.  You can not call a print function from dlinklist
void printQueue(struct queue *q)
{
	struct queue* tempQ = createQueue();
	
	while(!isEmptyQueue(q))
	{
		struct data* tempDta = top(q);
		printData(tempDta);
		pushQueue(tempQ,createData(tempDta->v1,tempDta->v2));
		popQueue(q);
	}
	
	while(!isEmptyQueue(tempQ))
	{
		struct data* tempDta = top(tempQ);
		pushQueue(q,createData(tempDta->v1,tempDta->v2));
		popQueue(tempQ);
	}
	cleanQueue(tempQ);
}

//get number of elements from queue
//int sizeQueue(struct queue *q)
//{

//}

//clean queue memory
void cleanQueue(struct queue *q)
{
	while(!isEmptyQueue(q))
	{
		popQueue(q);
	}
	free(q->que);	
	free(q);
}
