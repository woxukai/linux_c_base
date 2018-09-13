OBJS = singleson.o ../err/err.o
#VPATH err:../err
CC=gcc
singleson:$(OBJS)
	$(CC) -o $@ $^ -lpthread
singleson.o:singleson.c
	$(CC) -c $<
clean:
	rm -f singleson singleson.o
