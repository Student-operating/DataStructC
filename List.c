#include "List.h"

/*
* This file contains all the related methods of List
*/

typedef struct Lists {
	Node* head;
	int length;
}List;

List* ListConstructor() {
	List* L = (List*)malloc(sizeof(List) * 1);



	return L;
}

