#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>


#include "global.h"

/*
* git@github.com:Student-operating/DataStructC.git
*/
typedef int elem;

typedef struct Nodes {
	elem data;
	int dataSize;
	struct Nodes* next;
	struct Nodes* prev;
}Node;




bool nodesInit(Node* node, int flag);

bool initToLinkList(Node* node, int len);

bool initToArrayList(Node* node, int len);

int dataLength(Node* node);

char* numTostr(int len);

bool toString(Node* node); 

Node* nodesExtend();


