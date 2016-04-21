#include "clinklist.h"

int main(int argc, char* argv[])
{
	struct clinklist* myLl = createlinklist();
	struct data* myDta=NULL;
	myDta = createData(1.1,2.2);
	addFront(myLl,myDta);
	printList(myLl);
printf("\n");

	myDta = createData(3.3,4.4);
	addFront(myLl,myDta);
	printList(myLl);
printf("\n");

	myDta = createData(5.5,6.6);
	addFront(myLl,myDta);
	printList(myLl);
printf("\n");

	myDta = createData(0.0,0.0);
	addBack(myLl,myDta);
	printList(myLl);
printf("\n");
	

  return 0;
}
