CC=g++
RM=rm -rf
SRCS=StackAllocator.cc main.cc
OBJS=$(subst .cc,.o,$(SRCS))
TARGET=stack-alloc

all: $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) -c $<

clean:
	$(RM) $(OBJS) $(TARGET)
