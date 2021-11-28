#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

#include "global.h"

typedef int elem;

typedef struct Nodes {
	elem* data;
	struct Nodes* next;
	struct Nodes* prev;
}Node;


bool nodesInit(Node* node, int flag);

