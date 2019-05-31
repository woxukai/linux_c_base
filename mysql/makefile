OBJS = mysql_test.o #../err/err.o
#VPATH err:../err
CC=g++
CPPFLAGS=-Wall -std=c++11 -ggdb
LIB=-lmysqlclient
LIB_PATH=-I$LD_LIBRARY_PATH_64
#mysql_test:$(OBJS)
#	$(CC)  mysql_test.cpp -o mysql_test -ILD_LIBRARY_PATH_64 -lmysqlclient

mysql_test:$(OBJS)
	$(CC)  $^ -o $@  $(LIB)  #-lpthread
mysql_test.o:mysql_test.cpp
	$(CC) $(CPPFLGAS) -o $@ -c $<
.PHONY:
	clean
clean:
	rm -f $(OBJS) mysql_test
