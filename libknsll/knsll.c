#include "knsll.h"

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
	if(lst == NULL) return 0;
	lnode nd = newnode(data);
	if (nd == NULL) return 0;
	if (lst->first == NULL){
		lst->first = nd;
	} else {
		setNextNode(lst->last, nd);
	}	
	lst->last = nd;
	(lst->items)++;
	return 1;
}

unsigned int getItemCount(llist lst){
	if(lst == NULL) return 0;
	return lst->items;
}

void* deleteItem(llist lst, void *removeCompData){
	void* rmdata = NULL;
	if(lst == NULL) return rmdata;// returns NULL
	if (lst->items == 0) return rmdata; // returns NULL
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
		} else { // not found
			last = node;
			node = getNextNode(node);
		}
	}
	return rmdata;
}

void* searchItem(llist lst, void *searchKey){
	if(lst == NULL) return NULL;
	if (lst->items == 0) return NULL;
	lnode node = lst->first;
	while(node != NULL){
		int comp = lst->compFunc(searchKey, getNodeData(node));
		if(comp == 0){ //found
			return getNodeData(node);
		} else { // not found
			node = getNextNode(node);
		}
	}
	return NULL;
}
		
llist newlist(compare_f UseToCompare){
	if(UseToCompare == NULL) return NULL;
	llist lst = (llist)malloc(sizeof(*lst));
	if(lst == NULL) return NULL;
	lst->items = 0;
	lst->first = NULL;
	lst->compFunc = UseToCompare;
	return lst;
}

void rmlist(llist lst, int hardDataFree){
	if(lst == NULL) return;
	if(lst->items > 0){
		rmnode(lst->first, hardDataFree);
	}
	free(lst);
}
// -------------------   linked list adt   --------------------------------------

// -------------------   iterator   ---------------------------------------------

int hasNext(literator it){
	if(it == NULL) return 0;
	return (it->current != NULL);
}

void* getNext(literator it){
	if(it == NULL) return NULL;
	if(it->list == NULL) return NULL;
	if(hasNext(it) == 0) return NULL;
	lnode node = it->current;
	it->current = getNextNode(it->current);
	return getNodeData(node);
}

literator init_it(llist listToIterate){
	if(listToIterate == NULL) return NULL;
	literator it = (literator)malloc(sizeof(*it));
	if(it == NULL) return NULL;
	it->list = listToIterate;
	it->current = it->list->first;
	return it;
}

void kill_it(literator it){
	if(it == NULL) return;
	free(it);
}
// -------------------   iteartor   --------------------------------------------
