LIB_CFLAGS = -fPIC  -shared
TARGET     = libmylib.so
SRCS       = mylib.c
OBJS       = $(SRCS:.c=.o)
TEST       = test
LIB	= -L. -lmylib

all : $(TARGET)
$(TARGET) :$(OBJS)
	$(CC) $(LIB_CFLAGS) $(OBJS) -o $(TARGET)

$(TEST) :
	$(CC) test.c -o $(TEST) $(LIB)

%.o : %.c
	$(CC) -o $@ -c $<
clean:
	rm -f $(TARGET) $(TEST) $(OBJS) $(TEST).o
