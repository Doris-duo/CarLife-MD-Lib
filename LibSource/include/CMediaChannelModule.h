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
#ifndef C_MEDIA_CHANNEL_MODULE
#define C_MEDIA_CHANNEL_MODULE
#include "CTranRecvPackageProcess.h"

class CMediaChannelModule{
	public:
		~CMediaChannelModule();
		static CMediaChannelModule* getInstance();

		bool receiveMediaPackageHead();
		void mediaPackageHeadAnalysis();

		bool receiveMediaData();
		void mediaDataAnalysis();

		void mediaRegisterInit(void (*pFunc)(S_AUDIO_INIT_PARAMETER*));
		void mediaRegisterNormalData(void (*pFunc)(u8 *data, u32 len));
		void mediaRegisterStop(void (*pFunc)(void));
		void mediaRegisterPause(void (*pFunc)(void));
		void mediaRegisterResume(void (*pFunc)(void));
		void mediaRegisterSeek(void (*pFunc)(void));

	private:
		CMediaChannelModule():tranRecvPackageProcess(MEDIA_CHANNEL){
			}
		
		static CMediaChannelModule* pInstance;

		CTranRecvPackageProcess tranRecvPackageProcess;
};





































#endif








































