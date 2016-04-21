#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "data.h"

struct node
{
  struct node *next;
  struct node *prev;
  struct data *d;
};

struct dlinklist
{
  struct node *head;
  struct node *tail;
};

//reserve space for a new dlinklist, set initial variables, and return dlinklist
struct dlinklist* createlinklist();
//reserve space for new node, set variables and return
struct node* createNode(struct data *d);
//reserve space for a new data struct,set variables and return
void addFront(struct dlinklist *ll,struct data *d);
//create a new node, set the data pointer, and add to back of dlinklist
void addBack(struct dlinklist *ll,struct data *d);
//print values in the data structures in the dlinklist
void printList(struct dlinklist *ll);
//print the list backwards
void printBackwards(struct dlinklist *ll);
#endif
