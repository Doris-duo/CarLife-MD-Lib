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
#include "CVideoChannelModule.h"
#include "CConnectManager.h"
#include<iostream>

using namespace std;

CVideoChannelModule* CVideoChannelModule::pInstance=NULL;

CVideoChannelModule::~CVideoChannelModule() {
	pInstance=NULL;
}

CVideoChannelModule* CVideoChannelModule::getInstance() {
	if(NULL==pInstance) {
		pInstance= new CVideoChannelModule();
		}

	return pInstance;
}

bool CVideoChannelModule::receiveVideoPackageHead() {
	return tranRecvPackageProcess.receivePackageHead();
}

void CVideoChannelModule::videoPackageHeadAnalysis() {
	tranRecvPackageProcess.packageHeadAnalysis();
}

bool CVideoChannelModule::receiveVideoData() {
	return tranRecvPackageProcess.receivePackageData();
}

void CVideoChannelModule::videoDataAnalysis() {
	tranRecvPackageProcess.packageDataAnalysis();
}

void CVideoChannelModule::videoRegisterDataReceive(void (*pFunc)(u8 *data, u32 len)) {
	tranRecvPackageProcess.videoRegisterDataReceive(pFunc);
}

void CVideoChannelModule::videoRegisterHeartBeat(void (*pFunc)(void)) {
	tranRecvPackageProcess.videoRegisterHeartBeat(pFunc);
}


























