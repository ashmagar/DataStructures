#include "stack.h"


struct stack* createStack()
{
  struct stack *s = malloc(sizeof(struct stack));
  s->stk = createDLinkedList();
  return s;

}


//push item onto the stack
void pushStack(struct stack *s,struct data *dta)
{
	addFront(s->stk,dta);
}


//get item from top of stack
struct data* top(struct stack *s)
{
	return getFront(s->stk);
}

//pop item from the stack
void popStack(struct stack *s)
{
	removeFront(s->stk);
}

//test if stack is empty.  return 1 if empty and 0 is not
int isEmptyStack(struct stack *s)
{
	return(isEmpty(s->stk));
}

//print stack.  You have to print from the stack. You can not call a print function from dlinklist
void printStack(struct stack *s)
{
//	struct data* tDta = NULL;
	struct stack *tS = createStack();

	while(!isEmptyStack(s))
	{
		struct data* tDta = top(s);
		printData(tDta);
		pushStack(tS,createData(tDta->v1,tDta->v2));
		popStack(s);
	}

	while(!isEmptyStack(tS))
	{
		struct data* tDta = top(tS);
		pushStack(s,createData(tDta->v1,tDta->v2));
                popStack(tS);
	}
	cleanStack(tS);
}

//get number of elements from stack
//int sizeStack(struct stack *s)
//{
//}

//clean stack memory
void cleanStack(struct stack *s)
{
	while(!isEmptyStack(s))
	{
		popStack(s);
	}
	free(s->stk);
	free(s);
}
