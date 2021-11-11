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
#ifndef C_VIRTUAL_SHELL_H
#define C_VIRTUAL_SHELL_H

#define MAX_CMD_RET_LEN 1024*20

#include<string>
#include<cstdio>
#include<cstdlib>
#include<string.h>
#include "CommonUtil.h"

using namespace std;

struct CmdRet{
	bool ret;
	u8 data[MAX_CMD_RET_LEN];
	u32 len;
};

class CVirtualShell{
	public:
		~CVirtualShell();
		static CVirtualShell* getInstance();

		bool doCmd(const string cmd);
		void doCmdWithResult(const string cmd, struct CmdRet* cmdRet);

	private:
		CVirtualShell();

		static CVirtualShell* pInstance;
		
};










































































#endif



























