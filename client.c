#include <stdio.h>
#include "ua_types.h"
#include "ua_server.h"
#include "logger_stdout.h"
#include "networklayer_tcp.h"
#include "ua_config_standard.h"

#define URL "opc.tcp://localhost:16664"

int main(void)
{
	UA_Client *clt;	//client
	UA_StatusCode retval;
	UA_ReadRequest req;	//read request
	UA_ReadResponse resp; //response
	/*
	 * Step 1.
	 *	create & init the client
	*/
	clt = UA_Client_new(UA_ClientConfig_standard);
	retval = UA_Client_connect(clt, URL);
	if(retval != UA_STATUSCODE_GOOD){
		UA_Client_delete(clt);
		return retval;
	}
	/*
	 * Step 2.
	 *	Create read request
	*/
	UA_ReadRequest_init(&req);	// memset 0 in req
	req.nodesToRead = UA_Array_new(1, &UA_TYPES[UA_TYPES_READVALUEID]);
	req.nodesToReadSize = 1;
	/*
	 * Step 3.
	 *	define which node and attribute to be read
	*/
	req.nodesToRead[0].nodeId = UA_NODEID_STRING_ALLOC(1, "the.fucker");
	req.nodesToRead[0].attributeId = UA_ATTRIBUTEID_VALUE;
	/*
	 * Step 4.
	 *	call the `UA_Client_Service_read` to read
	*/
	resp = UA_Client_Service_read(clt, req);
	if(resp.responseHeader.serviceResult == UA_STATUSCODE_GOOD &&
		resp.resultsSize > 0 &&
		resp.results[0].hasValue &&
		UA_Variant_isScalar(&resp.results[0].value) &&
		resp.results[0].value.type == &UA_TYPES[UA_TYPES_INT32])
	{
		UA_Int32 *val = (UA_Int32 *)resp.results[0].value.data;
		printf("The value is: %d\n", *val);
	}
	/*
	 * Step 5.
	 *	free resource
	*/
	UA_ReadRequest_deleteMembers(&req);
	UA_ReadResponse_deleteMembers(&resp);
	UA_Client_disconnect(clt);
	UA_Client_delete(clt);
	
	return UA_STATUSCODE_GOOD;
}
	
