BUILD = demo_build

CLT = client.c
CLT_FS = client_firstSteps.c
CLT_SL = client_stateless.c

SVR = server.c
SVR_DS = server_datasource.c
SVR_FS = server_firstSteps.c
SVR_ML = server_mainloop.c
SVR_MD = server_method.c
SVR_NS = server_nodeset.c
SVR_RS = server_readspeed.c
SVR_RJ = server_repeated_job.c
SVR_UDP = server_udp.c
SVR_VAR = server_variable.c

CFLAG = -Wall -std=c99 -g
LIB = -lopen62541
LIB_PATH = -L $(shell pwd)/../
INCLUDE_PATH = -I $(shell pwd)/../include
CC = gcc
TARGET = ExSvr
TARGET += ExSvr_dataSource
TARGET += ExSvr_firstStep
TARGET += ExSvr_mainLoop
TARGET += ExSvr_method
#TARGET += ExSvr_nodeSet
TARGET += ExSvr_readSpeed
TARGET += ExSvr_repeat_job
#TARGET += ExSvr_udp
TARGET += ExSvr_var
TARGET += ExClt
TARGET += ExClt_firstStep
#TARGET += ExClt_stateLess

all : $(TARGET)
	mkdir ../$(BUILD)
	mv $(TARGET) ../$(BUILD)

ExSvr: $(SVR)
	$(CC) $(CFLAG) $(INCLUDE_PATH) -o $@ $(SVR) $(LIB_PATH) $(LIB)

ExSvr_dataSource: $(SVR_DS)
	$(CC) $(CFLAG) $(INCLUDE_PATH) -o $@ $(SVR_DS) $(LIB_PATH) $(LIB)

ExSvr_firstStep: $(SVR_FS)
	$(CC) $(CFLAG) $(INCLUDE_PATH) -o $@ $(SVR_FS) $(LIB_PATH) $(LIB)

ExSvr_mainLoop: $(SVR_ML)
	$(CC) $(CFLAG) $(INCLUDE_PATH) -o $@ $(SVR_ML) $(LIB_PATH) $(LIB)

ExSvr_method: $(SVR_MD)
	$(CC) $(CFLAG) $(INCLUDE_PATH) -o $@ $(SVR_MD) $(LIB_PATH) $(LIB)

ExSvr_nodeSet: $(SVR_NS)
	$(CC) $(CFLAG) $(INCLUDE_PATH) -o $@ $(SVR_NS) $(LIB_PATH) $(LIB)

ExSvr_readSpeed: $(SVR_RS)
	$(CC) $(CFLAG) $(INCLUDE_PATH) -o $@ $(SVR_RS) $(LIB_PATH) $(LIB)

ExSvr_repeat_job: $(SVR_RJ)
	$(CC) $(CFLAG) $(INCLUDE_PATH) -o $@ $(SVR_RJ) $(LIB_PATH) $(LIB)

ExSvr_udp: $(SVR_UDP)
	$(CC) $(CFLAG) $(INCLUDE_PATH) -o $@ $(SVR_UDP) $(LIB_PATH) $(LIB)

ExSvr_var: $(SVR_VAR)
	$(CC) $(CFLAG) $(INCLUDE_PATH) -o $@ $(SVR_VAR) $(LIB_PATH) $(LIB)

ExClt: $(CLT)
	$(CC) $(CFLAG) $(INCLUDE_PATH) -o $@ $(CLT) $(LIB_PATH) $(LIB)

ExClt_firstStep: $(CLT_FS)
	$(CC) $(CFLAG) $(INCLUDE_PATH) -o $@ $(CLT_FS) $(LIB_PATH) $(LIB)

ExClt_stateLess: $(CLT_SL)
	$(CC) $(CFLAG) $(INCLUDE_PATH) -o $@ $(CLT_SL) $(LIB_PATH) $(LIB)
	
clean:
	rm -rf ../$(BUILD)
