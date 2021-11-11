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

/******************************************************************************
 * Doris-duo fixed to implement CarLife protocol in MD devices
 * https://github.com/Doris-duo/CarLife-MD-Lib
 *****************************************************************************/
#ifndef CCONNECT_MANAGER_H
#define CCONNECT_MANAGER_H

#include "CVirtualShell.h"
#include "CSocketConnector.h"
#include "CommonUtil.h"

#define ADB_FORWARD_CMD	"adb forward tcp:7200 tcp:7240"
#define ADB_FORWARD_VIDEO	"adb forward tcp:8200 tcp:8240"
#define ADB_FORWARD_MEDIA	"adb forward tcp:9200 tcp:9240"
#define ADB_FORWARD_TTS	"adb forward tcp:9201 tcp:9241"
#define ADB_FORWARD_VR	"adb forward tcp:9202 tcp:9242"
#define ADB_FORWARD_TOUCH	"adb forward tcp:9300 tcp:9340"

#define LOCAL_IP_ADDR "127.0.0.1"

#define CMD_SOCKET_PORT_MD	7240
#define VIDEO_SOCKET_PORT_MD	8240
#define MEDIA_SOCKET_PORT_MD 9240
#define TTS_SOCKET_PORT_MD	9241
#define VR_SOCKET_PORT_MD	9242
#define TOUCH_SOCKET_PORT_MD		9340

#define CMD_SOCKET_PORT_HU	7200
#define VIDEO_SOCKET_PORT_HU	8200
#define MEDIA_SOCKET_PORT_HU 9200
#define TTS_SOCKET_PORT_HU	9201
#define VR_SOCKET_PORT_HU	9202
#define TOUCH_SOCKET_PORT_HU		9300

class CConnectManager{
public:
	~CConnectManager();
	static CConnectManager* getInstance();

	bool startBdclServerAsRoot();
	bool execGetDeviceCmd();
	bool execSocketForward();
	bool execGetPropCmd();
	bool execStartCarlife();
	bool execKillBdsc();
	bool execStartBdsc();
	
	bool createCmdSocket();
	bool createCmdSocket(string mdIPAddress);
	bool createCmdSocket(string mdIPAddress, string interfaceName);
	
	bool createVideoSocket();
	bool createVideoSocket(string mdIPAddress);
	bool createVideoSocket(string mdIPAddress, string interfaceName);
	
	bool createMediaSocket();
	bool createMediaSocket(string mdIPAddress);
	bool createMediaSocket(string mdIPAddress, string interfaceName);
	
	bool createTTSSocket();
	bool createTTSSocket(string mdIPAddress);
	bool createTTSSocket(string mdIPAddress, string interfaceName);
	
	bool createVRSocket();
	bool createVRSocket(string mdIPAddress);
	bool createVRSocket(string mdIPAddress, string interfaceName);
	
	bool createTouchSocket();
	bool createTouchSocket(string mdIPAddress);
	bool createTouchSocket(string mdIPAddress, string interfaceName);

	bool readCmdData(u8* data, u32 len);
	bool writeCmdData(u8* data, u32 len);

	bool readVideoData(u8* data, u32 len);

	bool readMediaData(u8*data, u32 len);
	bool readTTSData(u8*data, u32 len);

	bool readVRData(u8*data, u32 len);
	bool writeVRData(u8*data, u32 len);

	bool writeCtrlData(u8*data, u32 len);

	/*** Add MD interface  ***/
	bool writeVideoData(u8*data, u32 len);
	bool writeMediaData(u8*data, u32 len);
	bool writeTTSData(u8*data, u32 len);


private:
	CConnectManager();

	static CConnectManager* pInstance;

	static CmdRet cmdRet;

	CSocketConnector* cmdSocket;
	CSocketConnector* videoSocket;
	CSocketConnector* mediaSocket;
	CSocketConnector* ttsSocket;
	CSocketConnector* vrSocket;
	CSocketConnector* ctrlSocket;
};





































#endif





























