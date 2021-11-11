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
#ifndef C_CONNECTION_SETUP_MODULE
#define C_CONNECTION_SETUP_MODULE
#include "CTranRecvPackageProcess.h"

class CConnectionSetupModule{
	public:
		~CConnectionSetupModule();
		static CConnectionSetupModule* getInstance();

		int connectionSetup();
		int connectionSetup(string mdIPAddress);
		int connectionSetup(string mdIPAddress, string interfaceName);

	private:
		CConnectionSetupModule();
		
		static CConnectionSetupModule* pInstance;
};


































#endif

