#include "List.h"

/*
* This file contains all the related methods of List
*/



List LListConstructor(){
	List* L = (List*)malloc(sizeof(List) * 1);
	nodesInit(&(L->head), 0);
	L->tail = L->head->prev;
	L->length = dataLength(L->head->next);
	L->now = L->head->next;

	printf("value(head): %d\n", L->head->data);
	printf("value(prev): %d\n", L->head->prev->data);
	//printf("value( now): %d\n", L->head->prev->data);
	printf("     length: %d\n", L->length);


	return *L;
}

/*
* Purpose: Extend link list
*/
void LLESpace(List** L) {
	(*L)->tail->next = nodesExtend();
	Node* p = (*L)->tail->next;
	for (; p->next != NULL;) {
		p = p->next;
	}
	(*L)->tail = p;
	(*L)->tail->next = (*L)->head;
	(*L)->head->prev = (*L)->tail;
	(*L)->length = dataLength((*L)->head->next);
}

/*
* Purpose: Add e at the end
*/
bool LLAdd(List* L,elem e) {
	if (L == NULL) return false;
	//printf("修改前长度: %d\n", dataLength(L->now));
	
	L->now->data = e;
	L->now = L->now->next;

	//printf("修改后长度: %d\n", dataLength(L->now));
	if ((L->length - dataLength(L->now)) > (L->length-dataLength(L->head->next) / 2)) {
		LLESpace(&L);

	}
		
	return true;
}




