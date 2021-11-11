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
#include"CVirtualShell.h"
#include"CCarLifeLog.h"

CVirtualShell* CVirtualShell::pInstance=NULL;

CVirtualShell::CVirtualShell() {
}

CVirtualShell::~CVirtualShell() {
	pInstance=NULL;
}

CVirtualShell* CVirtualShell::getInstance() {
	if(NULL==pInstance) {
		pInstance=new CVirtualShell();
		}

	return pInstance;
}

bool CVirtualShell::doCmd(const string cmd) {
	if(""==cmd) {
		CCarLifeLog::carLifeLogLnWithPrefix("please input valid command!");	
		return false;
		}

	FILE *file=popen(cmd.c_str(), "r");

	if(NULL==file) {
		CCarLifeLog::carLifeLogLnWithPrefix("popen() excute failed!");
		
		return false;
		}

	//char retData[MAX_CMD_RET_LEN];
	//fread(retData, sizeof(char), MAX_CMD_RET_LEN-1, file);
	//retData[MAX_CMD_RET_LEN-1]='\0';

	//CCarLifeLog::carLifeLogLn(retData);
	
	return (pclose(file)==0);
}

void CVirtualShell::doCmdWithResult(const string cmd, CmdRet * cmdRet) {
	if(NULL!=cmdRet) {
		memset(cmdRet, '\0', sizeof(CmdRet));
		}else{
		CCarLifeLog::carLifeLogLnWithPrefix("cmdRet is NULL");
		
		return;
			}

		if(""==cmd) {
			cmdRet->ret=false;
			CCarLifeLog::carLifeLogLnWithPrefix("cmd is empty!");
			return;
			}

		FILE* file=popen(cmd.c_str(), "r");

		if(NULL==file) {
			cmdRet->ret=false;
			CCarLifeLog::carLifeLogLnWithPrefix("popen() is failed!");
			return;
			}
		
		cmdRet->len=fread(cmdRet->data, sizeof(char), MAX_CMD_RET_LEN-1, file);

		CCarLifeLog::carLifeLogWithPrefix("doCmdWithResult return len: ");
		CCarLifeLog::carLifeLogLn(cmdRet->len);

		cmdRet->ret=(pclose(file)==0);
}


























