#include "global.h"

/*
* Function: Initializes an incoming node into a list of 16 nodes
* Parameter: the target to which the result is received, the default generation mode
* Usage: initialized to a list of length 16 when flag is 0, otherwise generated from an array with equal flag values
* Note: The maximum length of the array generated is 16
*/
bool nodesInit(Node* node,int flag) {
	if (flag < 0 || flag>32) return false;

	if (flag == 0) {
		initToLinkList(node,16);
	}

	return true;
}

Node* initToLinkList(Node* node,int len) {

}