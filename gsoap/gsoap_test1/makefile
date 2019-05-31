# this is a Makefile to build client and server
# please setting the GSOAP_PATH first.
# build procedure:
#     step1: make soap
#     step2: make all

OBJ_NS = calc
OBJ_NAME = add
GSOAP_PATH = /home/xukai/Downloads/gsoap-2.8/gsoap
INCLUDE = -I$(GSOAP_PATH)
CC = gcc -g -DWITH_NONAMESPACES
OBJ_SERVER = addserver.c soapH.h soapC.c stdsoap2.h stdsoap2.c soapServer.c  
OBJ_CLIENT = addclient.o soapH.h soapC.o stdsoap2.h stdsoap2.o soapClient.o soapStub.h
LIBS = -l gsoap

all: server client 

server: $(OBJ_SERVER)
	#$(CC) $(INCLUDE) $^ -o $@ $(LIBS)
	$(CC)  $^   -o $@ $(LIBS) -L$(GSOAP_PATH) 
client: $(OBJ_CLIENT)
	$(CC)   $^   $(INCLUDE) -o $@  -L$(GSOAP_PATH) $(LIBS)
	#$(CC) $(INCLUDE) $^ -o $@ $(INCLUDE) $(LIBS) -L$(GSOAP_PATH)
#soapC.o: soapC.c soapH.h stdsoap2.h stdsoap2.c
#	$(CC) -o $@ $^ $(LIBS)
.PHONY:soap
soap:
#	@cp -v $(GSOAP_PATH)/stdsoap2.* .
	soapcpp2 -c $(OBJ_NAME).h
# -c 表示生成c文件

.PHONY:clean
clean:
	rm -f server client *.o
distclean:
	rm -f server client *.o ns* add* *.xml *.nsmap *.wsdl stdsoap2.*
