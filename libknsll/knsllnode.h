#ifndef KNSLLNODE_H
#define KNSLLNODE_H

	#include <stdio.h>
	#include <stdlib.h>
	typedef struct listnode *lnode;

	lnode newnode(void *toSave);
	int rmnode(lnode nd, int rmdata);
	void setNextNode(lnode nd, lnode newnext);
	lnode getNextNode(lnode nd);
	void* getNodeData(lnode nd);

#endif
