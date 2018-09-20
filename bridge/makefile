OBJS = bridge.o #../err/err.o
#VPATH err:../err
CC=g++
CPPFLAGS=-g -Wall -std=c++11 -ggdb
LDFLAGS=-pthread

bridge:$(OBJS)
	$(CC) $(LDFLAGS)  $^ -o $@  #-lpthread
bridge.o:bridge.cc
	$(CC) $(CPPFLGAS) -o $@ -c $<
.PHONY:
	clean

clean:
	rm -f bridge bridge.o
