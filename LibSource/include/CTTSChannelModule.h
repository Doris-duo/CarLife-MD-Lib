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
#ifndef C_TTS_CHANNEL_MODULE_H
#define C_TTS_CHANNEL_MODULE_H
#include "CTranRecvPackageProcess.h"

class CTTSChannelModule{
	public:
		~CTTSChannelModule();
		static CTTSChannelModule* getInstance();

		bool receiveTTSPackageHead();
		void ttsPackageHeadAnalysis();

		bool receiveTTSData();
		void ttsDataAnalysis();

		void ttsRegisterInit(void (*pFunc)(S_AUDIO_INIT_PARAMETER*));
		void ttsRegisterNormalData(void (*pFunc)(u8 *data, u32 len));
		void ttsRegisterStop(void (*pFunc)(void));

	private:
		CTTSChannelModule():tranRecvPackageProcess(TTS_CHANNEL){
			}
		
		static CTTSChannelModule* pInstance;

		CTranRecvPackageProcess tranRecvPackageProcess;
};





































#endif








































