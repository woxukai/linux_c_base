OBJS = burger.o #../err/err.o
#VPATH err:../err
CC=g++
CPPFLAGS=-g -Wall -std=c++11 -ggdb
LDFLAGS=-pthread

burger:$(OBJS)
	$(CC) $(LDFLAGS)  $^ -o $@  #-lpthread
burger.o:burger.cc
	$(CC) $(CPPFLGAS) -o $@ -c $<
.PHONY:
	clean

clean:
	rm -f burger burger.o
