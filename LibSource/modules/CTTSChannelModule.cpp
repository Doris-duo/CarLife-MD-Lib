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
#include "CTTSChannelModule.h"
#include "CConnectManager.h"
#include<iostream>

using namespace std;

CTTSChannelModule* CTTSChannelModule::pInstance=NULL;

CTTSChannelModule::~CTTSChannelModule() {
	pInstance=NULL;
}

CTTSChannelModule* CTTSChannelModule::getInstance() {
	if(NULL==pInstance) {
		pInstance= new CTTSChannelModule();
		}

	return pInstance;
}

bool CTTSChannelModule::receiveTTSPackageHead() {
	return tranRecvPackageProcess.receivePackageHead();
}

void CTTSChannelModule::ttsPackageHeadAnalysis() {
	tranRecvPackageProcess.packageHeadAnalysis();
}

bool CTTSChannelModule::receiveTTSData() {
	return tranRecvPackageProcess.receivePackageData();
}

void CTTSChannelModule::ttsDataAnalysis() {
	tranRecvPackageProcess.packageDataAnalysis();
}

void CTTSChannelModule::ttsRegisterInit(void (*pFunc)(S_AUDIO_INIT_PARAMETER*)) {
	tranRecvPackageProcess.ttsRegisterInit(pFunc);
}

void CTTSChannelModule::ttsRegisterNormalData(void (*pFunc)(u8 *data, u32 len)) {
	tranRecvPackageProcess.ttsRegisterNormalData(pFunc);
}
void CTTSChannelModule::ttsRegisterStop(void (*pFunc)(void)) {
	tranRecvPackageProcess.ttsRegisterStop(pFunc);
}






















