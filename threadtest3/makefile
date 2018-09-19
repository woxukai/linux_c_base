OBJS = threadtest.o #../err/err.o
#VPATH err:../err
CC=g++
CPPFLAGS=-Wall -std=c++11 -ggdb
LDFLAGS=-pthread

threadtest:$(OBJS)
	$(CC) $(LDFLAGS)  $^ -o $@  #-lpthread
threadtest.o:threadtest.cc
	$(CC) $(CPPFLGAS) -o $@ -c $<
.PHONY:
	clean

clean:
	rm -f threadtest threadtest.o
