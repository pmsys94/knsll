#include "knsll.h"

static int errll = 0;

struct list{
	unsigned int items;
	lnode first;
	lnode last;
	compare_f compFunc;
};

struct listiterator{
	llist list;
	lnode current;
};

// -------------------   linked list adt   --------------------------------------

int addItem(llist lst, void *data){
	if(lst == NULL){
		errll = ELLNULL;
		return errll;
	}
	lnode nd = newnode(data);
	if (nd == NULL){
		errll = ELLMEM;
		return errll;
	}
	if (lst->first == NULL){
		lst->first = nd;
	} else {
		setNextNode(lst->last, nd);
	}	
	lst->last = nd;
	(lst->items)++;
	return 0;
}

unsigned int getItemCount(llist lst){
	if(lst == NULL) return 0;
	errll = 0;
	return lst->items;
}

void* deleteItem(llist lst, void *removeCompData){
	void* rmdata = NULL;
	if(lst == NULL){
		errll = ELLNULL;
		return NULL;
	}
	if(lst->items == 0){
		errll = ELLZERO;
		return NULL;
	}
	if(lst->compFunc == NULL){
		errll = ELLCOMP;
		return NULL;
	}
	lnode last = NULL;
	lnode node = lst->first;
	while(node != NULL){
		int comp = lst->compFunc(removeCompData, getNodeData(node));
		if(comp == 0){ //found
			if(last == NULL){// first item should be deleted
				lst->first = getNextNode(node);
			} else {
				setNextNode(last, getNextNode(node));// if this is the last node: get Next returns NULL and NULL will be set on the previous node as next
			}
			setNextNode(node, NULL); // prevent recursive delete
			rmdata = getNodeData(node);
			rmnode(node, 0);
			node = NULL;
			(lst->items)--;
			errll = 0;
		} else { // not found
			last = node;
			node = getNextNode(node);
			errll = ELLNF;
		}
	}
	return rmdata;
}

void* searchItem(llist lst, void *searchKey){
	if(lst == NULL){
		errll = ELLNULL;
		return NULL;
	}
	if (lst->items == 0){
		errll = ELLZERO;
		return NULL;
	}
	if(lst->compFunc == NULL){
		errll = ELLCOMP;
		return NULL;
	}
	lnode node = lst->first;
	while(node != NULL){
		int comp = lst->compFunc(searchKey, getNodeData(node));
		if(comp == 0){ //found
			errll = 0;
			return getNodeData(node);
		} else { // not found
			node = getNextNode(node);
		}
	}
	errll = ELLNF;
	return NULL;
}
		
llist newlist(compare_f UseToCompare){
	llist lst = (llist)malloc(sizeof(*lst));
	if(lst == NULL){
		errll = ELLMEM;
		return NULL;
	}
	lst->items = 0;
	lst->first = NULL;
	lst->last = NULL;
	lst->compFunc = UseToCompare;
	errll = 0;
	return lst;
}

void rmlist(llist lst, int hardDataFree){
	if(lst == NULL){
		errll = ELLNULL;
		return;
	}
	if(lst->items > 0){
		rmnode(lst->first, hardDataFree);
	}
	free(lst);
	errll = 0;
}
// -------------------   linked list adt   --------------------------------------

// -------------------   iterator   ---------------------------------------------

int hasNext(literator it){
	if(it == NULL) return 0;
	return (it->current != NULL);
}

void* getNext(literator it){
	if(it == NULL){
		errll = ELLITN;
		return NULL;
	}
	if(it->list == NULL){
		errll = ELLNULL;
		return NULL;
	}
	if(hasNext(it) == 0) return NULL;
	lnode node = it->current;
	it->current = getNextNode(it->current);
	errll = 0;
	return getNodeData(node);
}

literator init_it(llist listToIterate){
	if(listToIterate == NULL){
		errll = ELLNULL;
		return NULL;
	}
	literator it = (literator)malloc(sizeof(*it));
	if(it == NULL){
		errll = ELLMEM;
		return NULL;
	}
	it->list = listToIterate;
	it->current = it->list->first;
	errll = 0;
	return it;
}

void kill_it(literator it){
	if(it == NULL) return;
	free(it);
	errll = 0;
}
// -------------------   iteartor   --------------------------------------------

void perror_knsll(const char* msg){
	char* errtext;
	switch(errll){
		case ELLNULL:{
			errtext = "Linked List is NULL";
			break;
		}
		case ELLMEM:{
			errtext = "No memory can be allocated";
			break;
		}
		case ELLZERO:{
			errtext = "No items in list";
			break;
		}
		case ELLCOMP:{
			errtext = "No compare function specified";
			break;
		}
		case ELLNF:{
			errtext = "No matching key was found on search";
			break;
		}
		case ELLITN:{
			errtext = "Iterator interface is NULL";
			break;
		}
	}
	printf("%s : %s\n", msg, errtext);
	errll = 0;
}
