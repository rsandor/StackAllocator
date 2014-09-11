#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "StackAllocator.h"

int main(int argc, char **argv) {
	unsigned int tests = 100000000;
	unsigned int chunkSize = 32;
	unsigned int totalSize = chunkSize * tests;

	if (argc > 1 and !strcmp(argv[1], "malloc")) {
		// Run many allocations with malloc
		printf("Testing With Malloc...");

		for (unsigned int i = 0; i < tests; i++) {
			char *ptr = (char *)malloc(sizeof(char) * chunkSize);
			sprintf(ptr, "12345678901234567890123456789012");
			free(ptr);
		}
	}
	else {
		// Run many allocation with the stack allocator
		printf("Testing Stack Allocator...");
		GameUtil::StackAllocator *stack = new GameUtil::StackAllocator(totalSize);

		for (unsigned int i = 0; i < tests; i++) {
			char *ptr = (char *)stack->alloc(chunkSize);
			sprintf(ptr, "12345678901234567890123456789012");
		}

		delete stack;
	}

	printf(" done.\n");

	return 0;
}