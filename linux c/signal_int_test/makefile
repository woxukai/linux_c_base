OBJS = signal_int_test.o ../err/err.o
#VPATH err:../err
CC=gcc
signal_int_test:$(OBJS)
	$(CC) -o $@ $^ -lpthread
signal_int_test.o:signal_int_test.c
	$(CC) -c $<
clean:
	rm -f signal_int_test signal_int_test.o
