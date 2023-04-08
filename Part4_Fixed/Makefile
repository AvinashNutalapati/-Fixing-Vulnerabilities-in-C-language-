PROJ_DIR := $(abspath .)
GCC_PATH := gcc

all: a.out

a.out: mem.o wrapped_malloc.o
	$(GCC_PATH) mem.o wrapped_malloc.o -o $@

mem.o: mem.c wrapped_malloc.h
	$(GCC_PATH) -g -c -o $@ mem.c

wrapped_malloc.o: wrapped_malloc.c wrapped_malloc.h
	$(GCC_PATH) -g -c -o $@ wrapped_malloc.c

clean:
	rm *.o
	rm a.out
