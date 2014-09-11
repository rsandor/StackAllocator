/*
 * Stack Allocator Implementation
 */

#include "StackAllocator.h"
#include <stdlib.h>

namespace GameUtil {
	StackAllocator::StackAllocator(U32 stackSize_bytes)
	{
		size = stackSize_bytes;
		top = 0;
		stack = (U8 *)( malloc(size) );
	}

	StackAllocator::~StackAllocator() {
		free(stack);
	}

	void *StackAllocator::alloc(U32 size_bytes)
	{
		if (size_bytes + top > size) {
			return NULL;
		}

		U32 current = top;
		top += size_bytes;
		return (void *)(stack + current);
	}

	StackAllocator::Marker GameUtil::StackAllocator::getMarker()
	{
		return top;
	}

	void StackAllocator::freeToMarker(Marker marker)
	{
		if (marker >= top) {
			return;
		}
		top = marker;
	}

	void StackAllocator::clear()
	{
		top = 0;
	}
}
