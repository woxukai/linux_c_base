###############################################################################
#
#
#
#
#
#
#
#
# 线程编译:gcc -lpthread -o file file.c
#
#示例:TARGT =test ; OBJ = $(TARGT).o; SRC = $(TARGT).c; all:$(TARGT) %.o:%.c
#$(CC) $(CFLAGS) -c $< -o $@
#CFLAGS = -Wall -Os -Dlinux -D__linux__-Dunix -D__uClinux__ -DEMBED LDFLAGS=-WL,-elf2flt
#LOCAL_LIBS=/usr/local/arm-elf/lib/libpthread.a
#CC = arm-elf-gcc
#LD = arm-elf-gcc
#$(TARGT):$(OBJ) $(LOCAL_LIBS)
#$(CC) $(CFLAGS) -c $< -o $@; $(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJ);
#$(LOCAL_LIBS) $(LDLIBS)
#clean: rm -f $(EXEC) *.elf *.gdb *.o
#
#########################################################################
# $@-----指代目标文件
# $^ ----指代所有依赖文件
# $< ----指代第一个依赖文件


CC = gcc

thread_timelock:thread_timelock.o
	$(CC) -o $@ $^ -lrt -lpthread

thread_timelock.o:thread_timelock.c
	$(CC) -c $<
clean:
	rm -f thread_timelock thread_timelock.o
