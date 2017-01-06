#include <windows.h>
#include <string>
#include <functional>
#include "teamspeak/public_errors.h"
#include "teamspeak/public_errors_rare.h"
#include "teamspeak/public_definitions.h"
#include "teamspeak/public_rare_definitions.h"
#include "teamspeak/clientlib_publicdefinitions.h"
#include "ts3_functions.h"

extern TS3Functions ts3Functions;
void getNowDate(char* buffer);

void changeChannelTopicFromServer(uint64 server){
	anyID user;
	uint64 channel;
	char date[11] = {0};
	
	getNowDate(date);
	
	if(ts3Functions.getClientID(server, &user) != ERROR_ok){
		return;
	}
	if(ts3Functions.getChannelOfClient(server, user, &channel) != ERROR_ok){
		return;
	}
	if(ts3Functions.setChannelVariableAsString(server, channel, CHANNEL_TOPIC, date) != ERROR_ok){
		return;
	}
	if(ts3Functions.flushChannelUpdates(server, channel, 0) != ERROR_ok){
		return;
	}
}

extern "C" void ts3plugin_onConnectStatusChangeEvent(uint64 serverConnectionHandlerID, int newStatus, unsigned int errorNumber){
	if(STATUS_CONNECTION_ESTABLISHED == newStatus){
		changeChannelTopicFromServer(serverConnectionHandlerID);
	}
}

int init(){
	return 0;
}
int shutdown(){
	return 0;
}