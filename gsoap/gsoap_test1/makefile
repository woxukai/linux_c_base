# this is a Makefile to build client and server
# please setting the GSOAP_PATH first.
# build procedure:
#     step1: make soap
#     step2: make all

OBJ_NS = calc
OBJ_NAME = add
GSOAP_PATH = /home/xukai/Downloads/gsoap-2.8/gsoap
INCLUDE = -I$(GSOAP_PATH)
CC = g++ -g -DWITH_NONAMESPACES

OBJ_SERVER = soapC.o stdsoap2.o $(OBJ_NAME)Server.o $(OBJ_NAME)server.o
OBJ_CLIENT = soapC.o stdsoap2.o $(OBJ_NAME)Client.o $(OBJ_NAME)client.o


all: server client 

server: $(OBJ_SERVER)
	$(CC) $(INCLUDE) $^ -o $@
client: $(OBJ_CLIENT)
	$(CC) $(INCLUDE) $^ -o $@

.PHONY:soap
soap:
	@cp -v $(GSOAP_PATH)/stdsoap2.* .
	soapcpp2 -c $(OBJ_NAME).h
# -c 表示生成c文件

.PHONY:clean
clean:
	rm -f server client *.o
distclean:
	rm -f server client *.o ns* add* *.xml *.nsmap *.wsdl stdsoap2.*
