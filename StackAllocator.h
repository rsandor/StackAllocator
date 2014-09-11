/*
 * Stack Allocator Class Definition
 */

#include "types.h"

namespace GameUtil {
	class StackAllocator
	{
	public:
		typedef U32 Marker;
		explicit StackAllocator(U32 stackSize_bytes);
		~StackAllocator();
		void *alloc(U32 size_bytes);
		Marker getMarker();
		void freeToMarker(Marker marker);
		void clear();
	private:
		Marker top;
		U32 size;
		U8 *stack;
	};
}
