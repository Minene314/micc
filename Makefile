CFLAGS=-std=c11 -g -static
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

micc: $(OBJS)
	$(CC) -o micc $(OBJS) $(LDFLAGS)

$(OBJS): micc.h

test: micc
	./test.sh

clean:
	rm -f micc *.o *~ tmp*

.PHONY: test clean
