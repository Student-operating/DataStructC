#pragma once
#include "global.h"

typedef struct Lists {
	Node* head;
	Node* tail;
	Node* now;
	int length;
}List;

List LListConstructor();

bool LLAdd(List* L, elem e);

void LLESpace(List** L);
