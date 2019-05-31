OBJS = sheep.o #../err/err.o
#VPATH err:../err
CC=g++
CPPFLAGS=-g -Wall -std=c++11 -ggdb
LDFLAGS=-pthread

sheep:$(OBJS)
	$(CC) $(LDFLAGS)  $^ -o $@  #-lpthread
sheep.o:sheep.cc
	$(CC) $(CPPFLGAS) -o $@ -c $<
.PHONY:
	clean

clean:
	rm -f sheep sheep.o
