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
#ifndef C_CARLIFE_LOG_H
#define C_CARLIFE_LOG_H

#include<iostream>
#include<string>
using namespace std;
class CCarLifeLog{
public:
	static void carLifeLog(string log);
	static void carLifeLog(int value);
	static void carLifeLogWithPrefix(string log);
	static void carLifeLogWithPrefix(int value);

	static void carLifeLogLn(string log);
	static void carLifeLogLn(int value);
	static void carLifeLogLnWithPrefix(string log);
	static void carLifeLogLnWithPrefix(int value);
};


















































#endif































