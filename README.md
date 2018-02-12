# knsll
A container libary for a simple linked list in C

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
	
	The rmlist() Funtion forces all stored data to deletion AND not neturns any stored data. It returns sucess. 
