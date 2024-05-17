CROSS_COMPILE ?= aarch64-none-linux-gnu-
CC ?= $(CROSS_COMPILE)

CFLAGS := -g
RM := rm -f


default: all

all: writer

writer: writer.o
	$(CC) $(CFLAGS) writer.o -o writer

writer.o: writer.c
	$(CC) $(CFLAGS) -c writer.c

clean veryclean:
	$(RM) writer *.o
