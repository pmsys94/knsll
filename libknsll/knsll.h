/*
	libknsll - adt module for a genric simple linked list interface
	------------------------------------------------------------

	This code module is an implementaition of a simple linked list container.
	It can store any type of data in it and releases it to the client as void pointer.
	For iterations over the stored data use the Iterator interface.
	To prevent memory leaks, call the rmlist function to a list your client isn't using anymore.

	For deleting and searching the list is initialized with a compare funtion of your client.
	It must identify by two (2) void data's (key and stored data) if they are matching or not.
	If they are match, the compare function has to return 0 - else something diffrent.

	Prototype of compare funtion is:

	int compare(void* key1, void* key2);

	Key 1 will be the search key, key 2 will be the data of a node.

	p.s:
	The deleteItem() Funtion deletes one (1) item AND returns the void pointer of the stored data.
	This function and searchItem return the data pointer or if sth. went wrong NULL.
	
	The rmlist() Funtion forces all stored data to deletion AND not neturns any stored data.
*/

#ifndef KNSLL_H
#define KNSLL_H

#define verKNSLL 2

	#include <stdio.h>
	#include "knsllnode.h"

	typedef int (*compare_f)(void* key1, void* key2);
	// -------------------   linked list adt   --------------------------------------
	typedef struct list *llist; // <- use this type for a new list
	int addItem(llist lst, void *data); // store data as a new item
	unsigned int getItemCount(llist lst);
	void* deleteItem(llist lst, void *removeCompData); // remove an item and get its stored data back: give it a search key which your compare function can compare
	void* searchItem(llist lst, void *searchKey); // search an item and get its stored data back: see deleteItem()
	
	llist newlist(compare_f UseToCompare); // constructor of adt: give it a funtion of your client that can compare a search key with the data - it must be like discribed above
	void rmlist(llist lst, int hardDataFree); // destructor of adt: it will force any data nodes to delete (incl. stored data ptr if param. 2 is true)
	// -------------------   linked list adt   --------------------------------------

	// -------------------   iterator   ---------------------------------------------
	typedef struct listiterator *literator; // <- use this type to iterate over the data of an list instance
	int hasNext(literator it); // check if iteration can go forward
	void* getNext(literator it);
	literator init_it(llist listToIterate); // contructor of iterator adt: give it a list instance
	void kill_it(literator it); // destructor of iterator adt: it will not care to the list and its data
	// -------------------   iteartor   ---------------------------------------------
#endif
