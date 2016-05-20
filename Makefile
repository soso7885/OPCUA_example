DEMO = demo_src
SVR_SRC = server.c
CLT_SRC = client.c
CFLAG = -Wall -std=c99 -g
LIB = -lopen62541
LIB_PATH = -L $(shell pwd)
INCLUDE_PATH = -I $(shell pwd)/include
CC = gcc
TARGET = MySvr
TARGET += MyClt

all : $(TARGET)
	make -C ./$(DEMO)

MySvr: $(SVR_SRC)
	$(CC) $(CFLAG) $(INCLUDE_PATH) -o $@ $(SVR_SRC) $(LIB_PATH) $(LIB)

MyClt: $(CLT_SRC)
	$(CC) $(CFLAG) $(INCLUDE_PATH) -o $@ $(CLT_SRC) $(LIB_PATH) $(LIB)
	
clean:
	rm -f $(TARGET)
	make clean -C ./$(DEMO)
