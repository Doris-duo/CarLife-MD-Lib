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
#ifndef C_CTRL_CHANNEL_MODULE_H
#define C_CTRL_CHANNEL_MODULE_H

#include "CTranRecvPackageProcess.h"

class CCtrlChannelModule{
	public:
		~CCtrlChannelModule();
		static CCtrlChannelModule* getInstance();

		bool receiveCtrlPackageHead();
		void ctrlPackageHeadAnalysis();

		bool receiveCtrlData();
		void ctrlDataAnalysis();

		int ctrlTouchAction(S_TOUCH_ACTION* touchAction);
		int ctrlTouchActionDown(S_TOUCH_ACTION_DOWN* touchActionDown);
		int ctrlTouchActionUp(S_TOUCH_ACTION_UP* touchActionUp);
		int ctrlTouchActionMove(S_TOUCH_ACTION_MOVE* touchActionMove);
		int ctrlTouchSigleClick(S_TOUCH_SIGNAL_CLICK* touchSingleClick);
		int ctrlTouchDoubleClick(S_TOUCH_DOUBLE_CLICK* touchDoubleClick);
		int ctrlTouchLongPress(S_TOUCH_LONG_PRESS* touchLongPress);
		int ctrlTouchCarHardKeyCode(S_TOUCH_CAR_HARD_KEY_CODE* touchCarHardKeyCode);
		void ctrlRegisterUIActionSound(void (*pFunc)(void));

	private:
		CCtrlChannelModule():tranRecvPackageProcess(CTRL_CHANNEL){
			}
		
		static CCtrlChannelModule* pInstance;

		CTranRecvPackageProcess tranRecvPackageProcess;
};

























































#endif
































