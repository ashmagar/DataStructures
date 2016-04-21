#include <stdio.h>
#include <assert.h>
#include "random.h"
#include "structures.h"
#include "avl.h"

int main(int argc,char* argv[])
{
  randSeed();

	if(argc==1 || argc%2==0)
	{
		return -1;
	}
	int i=0;
	struct data* myDta = NULL;
	struct avlTree* myAvlT = createAvlTree();
	for(i=1;i<argc;i+=2)
	{
		assert(i+1<argc);
		myDta = createData(atof(argv[i]),atof(argv[i+1]));
		insertAvl(myAvlT,myDta);
	}
	inOrderAvl(myAvlT);

  return 0;

}
