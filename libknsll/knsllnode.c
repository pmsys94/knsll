#include "knsllnode.h"

struct listnode{
	void* data;
	lnode next;
};

lnode newnode(void *toSave){
	lnode nd = (lnode)malloc(sizeof(*nd));
	if (nd == NULL) return NULL;
	nd->data = toSave;
	nd->next = NULL;
	return nd;
}

int rmnode(lnode nd, int rmdata){
	if (nd == NULL) return 0;
	if(nd->next != NULL){
		rmnode(nd->next, rmdata);
	}
	if(rmdata) free(nd->data);
	free(nd);
	return 1;
}

void setNextNode(lnode nd, lnode newnext){
	if(nd == NULL) return;
	nd->next = newnext;
}

lnode getNextNode(lnode nd){
	if(nd == NULL) return NULL;
	return nd->next;
}

void* getNodeData(lnode nd){
	if(nd == NULL) return NULL;
	return nd->data;
}
