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
#ifndef C_SOCKET_CONNECTOR_H
#define C_SOCKET_CONNECTOR_H

#include"socket.h"
#include"socketv6.h"
#include <string>
#include "CommonUtil.h"
#include "ISocket.h"

using namespace std;

class CSocketConnector{
public:
	CSocketConnector(string, u32, string);
	~CSocketConnector();
	
    	bool connectToServer();

   	 bool getConnectStatus();
  	 void setConnectStatus(bool status) { isConnected = status;}

public:
	ISocket *iSocket;
       Socket socket;
	Socketv6 socketv6;
	   
private:
   	 string mdServerIP;
   	 u32 mdServerPort;
	 string networkCardInterfaceName;
   	 bool isConnected;
};

























































#endif






















