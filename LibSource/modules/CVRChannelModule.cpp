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
#include "CVRChannelModule.h"
#include<iostream>

using namespace std;

CVRChannelModule* CVRChannelModule::pInstance=NULL;
CVRChannelModule::~CVRChannelModule() {
	pInstance=NULL;
}

CVRChannelModule* CVRChannelModule::getInstance() {
	if(NULL==pInstance) {
		pInstance= new CVRChannelModule();
		}

	return pInstance;
}

bool CVRChannelModule::receiveVRPackageHead() {
	return tranRecvPackageProcess.receivePackageHead();
}

void CVRChannelModule::vrPackageHeadAnalysis() {
	tranRecvPackageProcess.packageHeadAnalysis();
}

bool CVRChannelModule::receiveVRData() {
	return tranRecvPackageProcess.receivePackageData();
}

void CVRChannelModule::vrDataAnalysis() {
	tranRecvPackageProcess.packageDataAnalysis();
}

int CVRChannelModule::sendVRRecordData(u8* data, u32 size, u32 timeStamp) {
	return tranRecvPackageProcess.sendMicData(data, size, timeStamp);
}

void CVRChannelModule::vrRegisterInit(void (*pFunc)(S_AUDIO_INIT_PARAMETER*)) {
	tranRecvPackageProcess.vrRegisterInit(pFunc);
}

void CVRChannelModule::vrRegisterNormalData(void (*pFunc)(u8 *data, u32 len)) {
	tranRecvPackageProcess.vrRegisterNormalData(pFunc);
}
void CVRChannelModule::vrRegisterStop(void (*pFunc)(void)) {
	tranRecvPackageProcess.vrRegisterStop(pFunc);
}



















