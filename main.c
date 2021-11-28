#include "global.h"
#include "List.h"

static int randSeed;
float MyRandow(int i) {
	unsigned int times = (unsigned int)time(NULL);
	srand(times * (i + 1));
	randSeed = rand();
	randSeed = randSeed % 100;
	return randSeed;
}


main() {
	List list;
	list = LListConstructor();
	/*toString(list.head);
	LLAdd(&list, 13);
	LLAdd(&list, 11);
	LLAdd(&list, 4);*/
	toString(list.head);
	for (int i = 0; i < 32; i++) {
		LLAdd(&list, (int)MyRandow(i));
	}
	
	toString(list.head);
}