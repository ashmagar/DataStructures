#ifndef AVL_H_
#define AVL_H_

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "data.h"

struct avlLeaf* createAvlLeaf(struct data *d);
struct avlTree* createAvlTree();
void insertAvl(struct avlTree *t,struct data *d);
void insertAvl_r(struct avlTree *t,struct avlLeaf* current,struct avlLeaf* newLeaf);
void inOrderAvl(struct avlTree *t);
void inOrderAvl_r(struct avlLeaf *current);
void rotateRight(struct avlTree *t,struct avlLeaf *current);
void rotateLeft(struct avlTree *t,struct avlLeaf *current);
int maxHeight(int a,int b);
int getHeight(struct avlLeaf *lf);
int getBalanceFact(struct avlLeaf *lf);


int isRoot(struct avlLeaf *lf);
int isLeftChild(struct avlLeaf *lf);
int isRightChild(struct avlLeaf *lf);

#endif
