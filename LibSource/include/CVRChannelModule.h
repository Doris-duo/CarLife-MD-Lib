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
#ifndef C_VR_CHANNEL_MODULE_H
#define C_VR_CHANNEL_MODULE_H

#include "CTranRecvPackageProcess.h"

class CVRChannelModule{
	public:
		~CVRChannelModule();
		static CVRChannelModule* getInstance();
		int sendVRRecordData(u8* data, u32 size, u32 timeStamp);

		bool receiveVRPackageHead();
		void vrPackageHeadAnalysis();

		bool receiveVRData();
		void vrDataAnalysis();

		void vrRegisterInit(void (*pFunc)(S_AUDIO_INIT_PARAMETER*));
		void vrRegisterNormalData(void (*pFunc)(u8 *data, u32 len));
		void vrRegisterStop(void (*pFunc)(void));

	private:
		CVRChannelModule():tranRecvPackageProcess(VR_CHANNEL){
			}
		
		static CVRChannelModule* pInstance;

		CTranRecvPackageProcess tranRecvPackageProcess;
};

























































#endif
































