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
#include "CMediaChannelModule.h"
#include "CConnectManager.h"
#include<iostream>

using namespace std;

CMediaChannelModule* CMediaChannelModule::pInstance=NULL;

CMediaChannelModule::~CMediaChannelModule(){
	pInstance=NULL;
}

CMediaChannelModule* CMediaChannelModule::getInstance(){
	if(NULL==pInstance){
		pInstance= new CMediaChannelModule();
		}

	return pInstance;
}

bool CMediaChannelModule::receiveMediaPackageHead(){
	return tranRecvPackageProcess.receivePackageHead();
}

void CMediaChannelModule::mediaPackageHeadAnalysis(){
	tranRecvPackageProcess.packageHeadAnalysis();
}

bool CMediaChannelModule::receiveMediaData(){
	return tranRecvPackageProcess.receivePackageData();
}

void CMediaChannelModule::mediaDataAnalysis(){
	tranRecvPackageProcess.packageDataAnalysis();
}

void CMediaChannelModule::mediaRegisterInit(void (*pFunc)(S_AUDIO_INIT_PARAMETER*)){
	tranRecvPackageProcess.mediaRegisterInit(pFunc);
}

void CMediaChannelModule::mediaRegisterNormalData(void (*pFunc)(u8 *data, u32 len)){
	tranRecvPackageProcess.mediaRegisterNormalData(pFunc);
}
void CMediaChannelModule::mediaRegisterStop(void (*pFunc)(void)){
	tranRecvPackageProcess.mediaRegisterStop(pFunc);
}
void CMediaChannelModule::mediaRegisterPause(void (*pFunc)(void)){
	tranRecvPackageProcess.mediaRegisterPause(pFunc);
}
void CMediaChannelModule::mediaRegisterResume(void (*pFunc)(void)){
	tranRecvPackageProcess.mediaRegisterResume(pFunc);
}
void CMediaChannelModule::mediaRegisterSeek(void (*pFunc)(void)){
	tranRecvPackageProcess.mediaRegisterSeek(pFunc);
}


















