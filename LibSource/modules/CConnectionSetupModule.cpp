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
#include "CConnectionSetupModule.h"
#include "CConnectManager.h"
#include "CCarLifeLog.h"

using namespace std;

CConnectionSetupModule* CConnectionSetupModule::pInstance;

CConnectionSetupModule::CConnectionSetupModule() {
	CConnectionSetupModule::pInstance=NULL;
}

CConnectionSetupModule::~CConnectionSetupModule() {
	pInstance=NULL;
}

CConnectionSetupModule* CConnectionSetupModule::getInstance() {
	if(NULL==pInstance) {
		pInstance= new CConnectionSetupModule();
		}

	return pInstance;
}

int CConnectionSetupModule::connectionSetup() {
	//adb forward for video, media, tts, vr, touch channels
	CConnectManager::getInstance()->execSocketForward();

	//create socket for channels
	if(CConnectManager::getInstance()->createCmdSocket()) {
		CCarLifeLog::carLifeLogLnWithPrefix("cmd channel socket create successfully!");
		}else{
		CCarLifeLog::carLifeLogLnWithPrefix("cmd channel socket create failed!");
		return -1;
			}
	if(CConnectManager::getInstance()->createVideoSocket()) {
		CCarLifeLog::carLifeLogLnWithPrefix("video channel socket create successfully!");	
		}else{
		CCarLifeLog::carLifeLogLnWithPrefix("video channel socket create failed!");
		return -1;
			}
	if(CConnectManager::getInstance()->createMediaSocket()) {
		CCarLifeLog::carLifeLogLnWithPrefix("media channel socket create successfully!");
		}else{
		CCarLifeLog::carLifeLogLnWithPrefix("media channel socket create failed!");
		return -1;
			}
	if(CConnectManager::getInstance()->createTTSSocket()) {
		CCarLifeLog::carLifeLogLnWithPrefix("tts channel socket create successfully!");
		}else{
		CCarLifeLog::carLifeLogLnWithPrefix("tts channel socket create failed!");
		return -1;
			}
	if(CConnectManager::getInstance()->createVRSocket()) {
		CCarLifeLog::carLifeLogLnWithPrefix("vr channel socket create successfully!");
		}else{
		CCarLifeLog::carLifeLogLnWithPrefix("vr channel socket create failed!");
		return -1;
			}
	if(CConnectManager::getInstance()->createTouchSocket()) {
		CCarLifeLog::carLifeLogLnWithPrefix("ctrl channel socket create successfully!");
		}else{
		CCarLifeLog::carLifeLogLnWithPrefix("ctrl channel socket create failed!");
		return -1;
			}

	return 0;
}

int CConnectionSetupModule::connectionSetup(string mdIPAddress) {
	//create socket for channels
	if(CConnectManager::getInstance()->createCmdSocket(mdIPAddress)) {
		CCarLifeLog::carLifeLogLnWithPrefix("cmd channel socket create successfully!");
		}else{
		CCarLifeLog::carLifeLogLnWithPrefix("cmd channel socket create failed!");
		return -1;
			}
	if(CConnectManager::getInstance()->createVideoSocket(mdIPAddress)) {
		CCarLifeLog::carLifeLogLnWithPrefix("video channel socket create successfully!");
		}else{
		CCarLifeLog::carLifeLogLnWithPrefix("video channel socket create failed!");
		return -1;
			}
	if(CConnectManager::getInstance()->createMediaSocket(mdIPAddress)) {
		CCarLifeLog::carLifeLogLnWithPrefix("media channel socket create successfully!");
		}else{
		CCarLifeLog::carLifeLogLnWithPrefix("media channel socket create failed!");
		return -1;
			}
	if(CConnectManager::getInstance()->createTTSSocket(mdIPAddress)) {
		CCarLifeLog::carLifeLogLnWithPrefix("tts channel socket create successfully!");
		}else{
		CCarLifeLog::carLifeLogLnWithPrefix("tts channel socket create failed!");
		return -1;
			}
	if(CConnectManager::getInstance()->createVRSocket(mdIPAddress)) {
		CCarLifeLog::carLifeLogLnWithPrefix("vr channel socket create successfully!");
		}else{
		CCarLifeLog::carLifeLogLnWithPrefix("vr channel socket create failed!");
		return -1;
			}
	if(CConnectManager::getInstance()->createTouchSocket(mdIPAddress)) {
		CCarLifeLog::carLifeLogLnWithPrefix("ctrl channel socket create successfully!");
		}else{
		CCarLifeLog::carLifeLogLnWithPrefix("ctrl channel socket create failed!");
		return -1;
			}

	return 0;
}

int CConnectionSetupModule::connectionSetup(string mdIPAddress, string interfaceName) {
	//create socket for channels
	if(CConnectManager::getInstance()->createCmdSocket(mdIPAddress, interfaceName)) {
		CCarLifeLog::carLifeLogLnWithPrefix("cmd channel socket create successfully!");
		}else{
		CCarLifeLog::carLifeLogLnWithPrefix("cmd channel socket create failed!");
		return -1;
			}
	if(CConnectManager::getInstance()->createVideoSocket(mdIPAddress, interfaceName)) {
		CCarLifeLog::carLifeLogLnWithPrefix("video channel socket create successfully!");
		}else{
		CCarLifeLog::carLifeLogLnWithPrefix("video channel socket create failed!");
		return -1;
			}
	if(CConnectManager::getInstance()->createMediaSocket(mdIPAddress, interfaceName)) {
		CCarLifeLog::carLifeLogLnWithPrefix("media channel socket create successfully!");
		}else{
		CCarLifeLog::carLifeLogLnWithPrefix("media channel socket create failed!");
		return -1;
			}
	if(CConnectManager::getInstance()->createTTSSocket(mdIPAddress, interfaceName)) {
		CCarLifeLog::carLifeLogLnWithPrefix("tts channel socket create successfully!");
		}else{
		CCarLifeLog::carLifeLogLnWithPrefix("tts channel socket create failed!");
		return -1;
			}
	if(CConnectManager::getInstance()->createVRSocket(mdIPAddress, interfaceName)) {
		CCarLifeLog::carLifeLogLnWithPrefix("vr channel socket create successfully!");
		}else{
		CCarLifeLog::carLifeLogLnWithPrefix("vr channel socket create failed!");
		return -1;
			}
	if(CConnectManager::getInstance()->createTouchSocket(mdIPAddress, interfaceName)) {
		CCarLifeLog::carLifeLogLnWithPrefix("ctrl channel socket create successfully!");
		}else{
		CCarLifeLog::carLifeLogLnWithPrefix("ctrl channel socket create failed!");
		return -1;
			}

	return 0;
}




































