
VPATH = ../

CC = gcc
CFLAGS = -Wall -g -std=c99
LFLAGS = -lcunit
IFLAGS = -I..
TARGETS = stk_test
OBJS = stk_test.o stk.o

.c.o:
	$(CC) $(CFLAGS) $(IFLAGS) -c $<

all : $(TARGETS)

stk_test : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LFLAGS)

check : stk_test
	@./stk_test

clean :
	rm $(TARGETS) $(OBJS) 

stk_test.o : stk_test.c ../stk.c ../stk.h
