OBJS = signal_test.o ../err/err.o
#VPATH err:../err
CC=gcc
signal_test:$(OBJS)
	$(CC) -o $@ $^ -lpthread
signal_test.o:signal_test.c
	$(CC) -c $<
clean:
	rm -f signal_test signal_test.o
