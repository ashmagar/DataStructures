#include "avl.h"
#include<assert.h>


struct avlLeaf* createAvlLeaf(struct data *d)
{
  struct avlLeaf* maple = malloc(sizeof(struct avlLeaf));
  maple->right = NULL;
  maple->left = NULL;
  maple->parent = NULL;
  maple->dta = d;
  maple->height = 1;
  return maple;
}

struct avlTree* createAvlTree()
{
  struct avlTree* oak = malloc(sizeof(struct avlTree));
  oak->root = NULL;
  return oak;
}

int getHeight(struct avlLeaf *lf)
{
	return (lf==NULL ? 0 : lf->height);
}

int maxHeight(int a,int b)
{
	return (a > b ? a : b);
}

int getBalanceFact(struct avlLeaf *lf)
{
	return ( getHeight(lf->right) - getHeight(lf->left) );
}

int isRoot(struct avlLeaf *lf)
{
	return lf->parent == NULL ? 1 : 0;
}

int isLeftChild(struct avlLeaf *lf)
{
	return !isRoot(lf) && (lf->parent->left == lf) ;
}

int isRightChild(struct avlLeaf *lf)
{
	return !isRoot(lf) && (lf->parent->right == lf);
}

void rotateRight(struct avlTree *t,struct avlLeaf *current)
{
	current = current -> left;

	struct avlLeaf *x = current->parent;

	x->left = current->right;
	current->right->parent = x;

	current->parent = x -> parent;

	if(isRoot(x))
	{
		t->root = current;
	}
	else if(isLeftChild(x))
	{
		current->parent->left = current;
	}
	else
	{
		assert(isRightChild(x));
		current->parent->right = current;
	}

	x->parent = current;
	x->height = maxHeight(getHeight(x->right),getHeight(x->left)) + 1;
}

void rotateLeft(struct avlTree *t,struct avlLeaf *current)
{
        current = current -> right;

        struct avlLeaf *x = current->parent;

        x->right = current->left;
        current->left->parent = x;

        current->parent = x -> parent;

        if(isRoot(x))
        {
                t->root = current;
        }
        else if(isRightChild(x))
        {
                current->parent->right = current;
        }
        else
        {
                assert(isLeftChild(x));
                current->parent->left = current;
        }

        x->parent = current;
        x->height = maxHeight(getHeight(x->left),getHeight(x->right)+1);
}

void insertAvl(struct avlTree *t,struct data *d)
{
	struct avlLeaf* newLeaf = createAvlLeaf(d);
	if(t->root == NULL)
	{
		t->root = newLeaf;
	}
	else
	{
		insertAvl_r(t,t->root,newLeaf);
	}
}

void insertAvl_r(struct avlTree *t,struct avlLeaf* current,struct avlLeaf* newLeaf)
{
	if(sumData(newLeaf->dta) <= sumData(current->dta))
	{
		if(current->left==NULL)
		{
			current->left = newLeaf;
			newLeaf->parent = current;
		}
		else
		{
			insertAvl_r(t,current->left,newLeaf);
		}
	}
	else if(sumData(newLeaf->dta) > sumData(current->dta))
	{
		if(current->right==NULL)
		{
			current->right = newLeaf;
			newLeaf->parent = current;
		}
		else
		{
			insertAvl_r(t,current->right,newLeaf);
		}
	}
	current->height = maxHeight(getHeight(current->right),getHeight(current->left)) + 1;
	int bf = getBalanceFact(current);

	if(bf == 2)
	{
		//single rotate
		if(getBalanceFact(current->right) == 1)
		{
			rotateLeft(t,current);
		}
		//special case double rotate (e.g. 5 8 6)
		else if(getBalanceFact(current->right) == -1)
		{
			rotateRight(t,current->right);
			rotateLeft(t,current);
		}
	}

	if(bf == -2)
	{
		//single rotate
		 if(getBalanceFact(current->left) == -1)
                {
                        rotateLeft(t,current);
                }
                //special case double rotate (e.g. 5 3 4)
                else if(getBalanceFact(current->left) == 1)
                {
                        rotateLeft(t,current->left);
                        rotateRight(t,current);
                }
	}
}

void inOrderAvl(struct avlTree *t)
{
	if(t->root != NULL)
	{
		inOrderAvl_r(t->root);
	}
}
void inOrderAvl_r(struct avlLeaf *current)
{
	if(current == NULL)
	{
		return;
	}

	inOrderAvl_r(current->left);
	printData(current->dta);
	inOrderAvl_r(current->right);
}
