#include "global.h"
#define ExtendSpace 16

/*
* Purpose: Initializes an incoming node into a list of 16 nodes
* Parameters: the target to which the result is received -- "node", the default generation mode --"flag"
* Usage: initialized to a list of length 16 when flag is 0, otherwise generated from an array with equal flag values
* Return: Returns "true" on success, "false" otherwise
* Note: The maximum length of the array generated is 16
*/
bool nodesInit(Node** node,int flag) {
	if (flag < 0 || flag>32) return false;

	if (flag == 0) {
		initToLinkList(&(*node),16);
	}
	else {
		initToArrayList(&(*node), flag);
	}

	return true;
}

/*
* Purpose: Build a linked list of length len
* Parameters: linked list "node"; Chain length of the table "len"
* Usage: Returns a collection of data from node;
* Return: Return to running state
*/
bool initToLinkList(Node** node,int len) {
	
	*node = (Node*)calloc(1,sizeof(Node));

	Node* n = (Node*)malloc(sizeof(Node) * 1);
	n->data = 0;
	n->dataSize = 1;
	(*node)->next = n;
	(*node)->prev = n;

//The first interpolation
	for (int i = 0; i < len-1; i++) {
		
		n->next = (Node*)malloc(sizeof(Node) * 1);// creat next node
		n->next->data = 0;// default the data of next node;
		n->next->dataSize = 1;// default size of one data;
		n->next->next = *node;// default next-position of next node;
		n->next->prev = n;// lock the prev node for next node
		
		
		n = n->next;// move the point of creat to next node
		(*node)->prev = n;// reset the cycle
	}//for

//The tail interpolation
	return true;
}

bool initToArrayList(Node** node, int len) {
	if (len <= 0) {
		printf("===YOU USED A WRONG LENGTH!===\n");
		return false;
	}

	Node* home = (Node*)malloc(sizeof(Node) * len);
	home->next = home;
	home->prev = home + len;
	Node* p = home;
	for (int i = 0; i < len; i++) {
		p->data = 0;
		p++;
	}
	home->dataSize = len;
	*node = home;

	return true;
}

int dataLength(Node* node) {
	if (node == NULL) {
		printf("The node is NULL\n");
		return -1;
	}

	if (node->dataSize > 1)return node->dataSize;

	int length = 0;
	Node* p = node;
	for (;p->dataSize!=0; length++)
		p = p->next;
	

	return length;
}

char* numTostr(int len) {
	char* str = "%02d,";

	switch (len) {
	case 1:str = "%c,";
		break;
	case 4:str = "%02d,";
		break;
	case 8:str = "%lf,";
		break;
	default:
		break;
	}

	return str;
}

bool toString(Node* node) {
	if (node == NULL) {
		printf("The node is NULL\n");
		return -1;
	}
	int len = dataLength(node->next);
	node = node->next;

	char* str = numTostr(sizeof(elem));
	if(node->next == 0){
		//node = node->next;
		

		printf("\n[ ");
		for (int i = 0; i < len; i++) {
			printf(str, node->data);
			node = node->next;
		}
		printf(" ]\n");
	}
	else {
		printf("# # #\n<--\n");
		for (int i = 0; i < len; i++) {
			if (i % 16 == 0 && i != 0)putchar('\n');
			printf(str, node->data);
			node = node->next;
		}
		printf(" \n-->\n# # #\n");
	}
	

	


	return true;
}

Node* nodesExtend() {
	Node* extend = (Node*)malloc(sizeof(Node) * 1);
	Node* ehome = extend;
	extend->data = 0;
	extend->dataSize = 1;
	for (int i = 0; i < ExtendSpace-1; i++) {
		extend->next = (Node*)malloc(sizeof(Node) * 1);
		extend->next->data = 0;
		extend->next->dataSize = 1;
		extend->next->next = NULL;
		extend->next->prev = extend;


		extend = extend->next;
	}

	return ehome;
}







