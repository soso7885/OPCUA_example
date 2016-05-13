#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "ua_types.h"
#include "ua_server.h"
#include "logger_stdout.h"
#include "networklayer_tcp.h"
#include "ua_config_standard.h"

UA_Boolean isRunning;

static void stopHandler(int signal)
{
	printf("\nClosing Server....\n");
	isRunning = false;
}

int main(void)
{
	UA_ServerNetworkLayer nl;	//Server interface
	UA_Server *svr;		//server
	UA_ServerConfig conf;	//Server config
	UA_Int32 val;	//the var value
	UA_VariableAttributes attr;	//the var attribues
	UA_NodeId selfNodeId, parentNodeId, parRefNodeId, varType;//the node-ID
	UA_QualifiedName bName;	//browse-name

	signal(SIGINT, stopHandler);
	signal(SIGTERM, stopHandler);

	/*
	 * Step 1.
	 *	init the server
	*/	
	//fill in the `UA_ServerNetworkLayer` structure member
	nl = UA_ServerNetworkLayerTCP(UA_ConnectionConfig_standard, 16664);
	//the server config setting
	conf = UA_ServerConfig_standard;
	conf.logger = Logger_Stdout;
	conf.networkLayers = &nl;
	conf.networkLayersSize = 1;
	svr = UA_Server_new(conf);
	/*
	 * Step 2.
	 *  Set the variable and variable attribute
	*/
	val = 5566;
	UA_String str = UA_STRING_ALLOC("Hello, world");
	UA_VariableAttributes_init(&attr);	
//	UA_Variant_setScalar(&attr.value, &val, &UA_TYPES[UA_TYPES_INT32]);	
	UA_Variant_setScalarCopy(&attr.value, &str, &UA_TYPES[UA_TYPES_STRING]);
	attr.displayName = UA_LOCALIZEDTEXT("TW", "the fucker");
	/*
	 * Step 3.
	 *  Define the variable shall be add with which `browsname`
	*/
	selfNodeId = UA_NODEID_STRING(1, "the.fucker");
	parentNodeId = UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER);
	parRefNodeId = UA_NODEID_NUMERIC(0, UA_NS0ID_ORGANIZES);
	varType = UA_NODEID_NULL; //no variable type defined
	bName = UA_QUALIFIEDNAME(1, "the fucker");
	/*
	 * Step 4.
	 * Add the node
	*/
	UA_Server_addVariableNode(svr, selfNodeId, parentNodeId, parRefNodeId,
							bName, varType, attr, NULL, NULL);
	/*
	 * Step 5.
	 * Run server
	*/
	isRunning = true;	// the switch
	UA_Server_run(svr, &isRunning);
	UA_Server_delete(svr);
	
	return 0;
}	
