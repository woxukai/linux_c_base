OBJS = sigsuspend_test.o ../err/err.o
#VPATH err:../err
CC=gcc
sigsuspend_test:$(OBJS)
	$(CC) -o $@ $^ -lpthread
sigsuspend_test.o:sigsuspend_test.c
	$(CC) -c $<
clean:
	rm -f sigsuspend_test sigsuspend_test.o
