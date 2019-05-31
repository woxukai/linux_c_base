OBJS = adapter.o #../err/err.o
#VPATH err:../err
CC=g++
CPPFLAGS=-g -Wall -std=c++11 -ggdb
LDFLAGS=-pthread

adapter:$(OBJS)
	$(CC) $(LDFLAGS)  $^ -o $@  #-lpthread
adapter.o:adapter.cc
	$(CC) $(CPPFLGAS) -o $@ -c $<
.PHONY:
	clean

clean:
	rm -f adapter adapter.o
