/******************************************************************************
 * Copyright 2018 The Baidu Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#include "CSocketConnector.h"
#include "CCarLifeLog.h"

using namespace std;

CSocketConnector::CSocketConnector(string serverIP, u32 port, string interfaceName)
{
    if(serverIP.find(":",0)!=string::npos) {
	CCarLifeLog::carLifeLogLnWithPrefix("iSockset=&socketv6");
	iSocket=&socketv6;
    }else{
    	CCarLifeLog::carLifeLogLnWithPrefix("iSockset=&socket");
    	iSocket=&socket;
    }
	
    setConnectStatus(false);

    mdServerIP = serverIP;
    mdServerPort = port;
    networkCardInterfaceName=interfaceName;
}
CSocketConnector::~CSocketConnector()
{

}

bool CSocketConnector::getConnectStatus()
{
    return isConnected;
}

bool CSocketConnector::connectToServer()
{
    if ( ! iSocket->create() )
    {
	CCarLifeLog::carLifeLogLnWithPrefix("socket.create fail!");
        return false;
    }

    if ( ! iSocket->connect ( mdServerIP, mdServerPort, networkCardInterfaceName ) )
    {	
	CCarLifeLog::carLifeLogWithPrefix("mdServerIP: ");
	CCarLifeLog::carLifeLog(mdServerIP);
	CCarLifeLog::carLifeLog(" mdServerPort: ");
	CCarLifeLog::carLifeLog(mdServerPort);
	CCarLifeLog::carLifeLog("\n");
	
	CCarLifeLog::carLifeLogLnWithPrefix("socket.connect fail!");
        return false;
    }
    setConnectStatus(true);
    return true;
}

























