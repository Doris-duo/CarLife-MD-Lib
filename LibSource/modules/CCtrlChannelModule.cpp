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
#include "CCtrlChannelModule.h"
#include<iostream>

using namespace std;

CCtrlChannelModule* CCtrlChannelModule::pInstance=NULL;

CCtrlChannelModule::~CCtrlChannelModule() {
	pInstance=NULL;
}

CCtrlChannelModule* CCtrlChannelModule::getInstance() {
	if(NULL==pInstance) {
		pInstance= new CCtrlChannelModule();
		}

	return pInstance;
}

bool CCtrlChannelModule::receiveCtrlPackageHead() {
	return tranRecvPackageProcess.receivePackageHead();
}
void CCtrlChannelModule::ctrlPackageHeadAnalysis() {
	tranRecvPackageProcess.packageHeadAnalysis();
}

bool CCtrlChannelModule::receiveCtrlData() {
	return tranRecvPackageProcess.receivePackageData();
}

void CCtrlChannelModule::ctrlDataAnalysis() {
	tranRecvPackageProcess.packageDataAnalysis();
}

int CCtrlChannelModule::ctrlTouchAction(S_TOUCH_ACTION* touchAction) {
	return tranRecvPackageProcess.sendCtrlTouchAction(touchAction);
}
int CCtrlChannelModule::ctrlTouchActionDown(S_TOUCH_ACTION_DOWN* touchActionDown) {
	return tranRecvPackageProcess.sendCtrlTouchActionDown(touchActionDown);
}
int CCtrlChannelModule::ctrlTouchActionUp(S_TOUCH_ACTION_UP* touchActionUp) {
	return tranRecvPackageProcess.sendCtrlTouchActionUp(touchActionUp);
}
int CCtrlChannelModule::ctrlTouchActionMove(S_TOUCH_ACTION_MOVE* touchActionMove) {
	return tranRecvPackageProcess.sendCtrlTouchActionMove(touchActionMove);
}
int CCtrlChannelModule::ctrlTouchSigleClick(S_TOUCH_SIGNAL_CLICK* touchSingleClick) {
	return tranRecvPackageProcess.sendCtrlTouchSigleClick(touchSingleClick);
}
int CCtrlChannelModule::ctrlTouchDoubleClick(S_TOUCH_DOUBLE_CLICK* touchDoubleClick) {
	return tranRecvPackageProcess.sendCtrlTouchDoubleClick(touchDoubleClick);
}
int CCtrlChannelModule::ctrlTouchLongPress(S_TOUCH_LONG_PRESS* touchLongPress) {
	return tranRecvPackageProcess.sendCtrlTouchLongPress(touchLongPress);
}
int CCtrlChannelModule::ctrlTouchCarHardKeyCode(S_TOUCH_CAR_HARD_KEY_CODE* touchCarHardKeyCode) {
	return tranRecvPackageProcess.sendCtrlTouchCarHardKeyCode(touchCarHardKeyCode);
}
void CCtrlChannelModule::ctrlRegisterUIActionSound(void (*pFunc)(void)) {
	tranRecvPackageProcess.ctrlRegisterUIActionSound(pFunc);
}






















