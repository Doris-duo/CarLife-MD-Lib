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

#include"CCarLifeLibWrapper.h"
#include<pthread.h>
#include<unistd.h>

using namespace CCarLifeLibH;

/*************************************************
 MACRO
 *************************************************/
// connection pattern setting
#define ADB_CONNECTION 0
#define IOS_WIFI_CONNECTION 1
#define CONNECTION_PATTERN ADB_CONNECTION

/****************************************
CALLBACK FUNCTIONS DECLARE
*****************************************/
// Video channel
void videoDataReceive(u8 *data, u32 len);
void videoHeartBeat();

// Media channel
void mediaInit(S_AUDIO_INIT_PARAMETER *initParam);
void mediaNormalData(u8 *data, u32 len);
void mediaStop();
void mediaPause();
void mediaResume();
void mediaSeek();

// Navi TTS channel
void ttsInit(S_AUDIO_INIT_PARAMETER *initParam);
void ttsNormalData(u8 *data, u32 len);
void ttsStop();

//Vr channel
void vrInit(S_AUDIO_INIT_PARAMETER *initParam);
void vrNormalData(u8 *data, u32 len);
void vrStop();

// CMD channel
void *cmdReceiveThread(void *arg);
void *videoReceiveThread(void *arg);
void *mediaReceiveThread(void *arg);
void *ttsReceiveThread(void *arg);
void *vrReceiveThread(void *arg);

void cmdProtocolVersionMatchStatus(S_PROTOCOL_VERSION_MATCH_SATUS* status);
void cmdMDInfro(S_MD_INFO*);
void cmdMDBTPairInfro(BTPairInfo*);
void cmdVideoEncoderInitDone(S_VIDEO_ENCODER_INIT_DONE*);
void cmdVideoEncoderFrameRateChangeDone(S_VIDEO_ENCODER_FRAME_RATE_CHANGE_DONE*);
void cmdTelStateChangeIncoming();
void cmdTelStateChangeOutGoing();
void cmdTelStateChangeIdle();
void cmdTelStateChangeInCalling();
void cmdScreenOn();
void cmdScreenOff();
void cmdScreenUserPresent();
void cmdForeground();
void cmdBackground();
void cmdGoToDeskTop();
void cmdMicRecordWakeupStart();
void cmdMicRecordEnd();
void cmdMicRecordRecogStart();
// 0x00010026
void cmdModuleStatus(S_MODULE_STATUS_LIST_MOBILE*);
// 0x00010030
void cmdNaviNextTurnInfo(S_NAVI_NEXT_TURN_INFO*);
// 0x00010031
void cmdCarDataSubscribe(S_VEHICLE_INFO_LIST*);	
// 0x00010033
void cmdCarDataSubscribeStart(S_VEHICLE_INFO_LIST*);
// 0x00010034
void cmdCarDataSubscribeStop(S_VEHICLE_INFO_LIST*);
// 0x00010035
void cmdMediaInfo(S_MEDIA_INFO*);
// 0x00010036
void cmdMediaProgressBar(S_MEDIA_PROGRESS_BAR*);
// 0x00010037
void cmdRegisterConnectException(S_CONNECTION_EXCEPTION*);
// 0x00010038
void cmdRegisterRequestGoToForeground(void);
// 0x00010039
void cmdRegisterUIActionSound(void);

// 0x00010049
void cmdRegisterMdAuthenResponse(S_AUTHEN_RESPONSE* response);

// 0x00010051
void cmdRegisterFeatureConfigRequest();

// 0x00010057
void cmdRegisterVideoEncoderJPEGAck();

// 0x00010058(Deprecated)

// 0x00010059
void cmdRegisterMdExit();

/******************************************
INIT PARAMETER
*******************************************/
S_HU_PROTOCOL_VERSION huProtocolVersion={1,0};

S_VIDEO_ENCODER_INIT initVideoParam={768, 480,30};

u8 vrData[1024]={1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9};

S_TOUCH_ACTION touchAction={1, 12 ,34};

S_TOUCH_CAR_HARD_KEY_CODE touchCarHardKeyCode={0x00000010};//next song

// anthorization
S_AUTHEN_REQUEST authenRequest={"CarLife_1.0.0"};

S_FEATURE_CONFIG_LIST configList;
S_FEATURE_CONFIG featureConfigFocusUI;

void setFocusUIConfig(int val) {
	configList.cnt=1;
	configList.pFeatureConfig=&featureConfigFocusUI;
	featureConfigFocusUI.key="FOCUS_UI";
	featureConfigFocusUI.value=val;
	featureConfigFocusUI.pNext = NULL;
}

/****************************************
 FUNCTIONS
 ****************************************/
int main(int argc, char *const argv[]) {
	int ret;
	pthread_t id;
	int item;

	//parameter check
   if(CONNECTION_PATTERN==IOS_WIFI_CONNECTION) {
	   if(argc!=2) {
			cout<<"use method:"<<endl;
			cout<<"\t ./libtest IPAddress"<<endl;
			return -1;
	   }
   }


	cout<<"CarLife library test"<<endl;

	cout<<"CarLifeLib initialization && connection set up test:"<<endl;
	// initialize CarLife libaray
	CCarLifeLib::getInstance()->carLifeLibInit();

	// set up connection between head unit and mobile device
	// support WI-FI connection
	if(CONNECTION_PATTERN==IOS_WIFI_CONNECTION) {
		if(0==CCarLifeLib::getInstance()->connectionSetup(argv[1])) {
			cout<<"command/video/media/tts/vr/control channel connection have been set up!"<<endl;
		}else{
				cout<<"connection set up failed!"<<endl;
		}
	}

	// support ADB connection
	if(CONNECTION_PATTERN==ADB_CONNECTION) {
		if(0==CCarLifeLib::getInstance()->connectionSetup()) {
			cout<<"command/video/media/tts/vr/control channel connection have been set up!"<<endl;
		}else{
				cout<<"connection set up failed!"<<endl;
		}

//		//carLifeLibDestory() test
//		sleep(2);//sleep 2s
//		cout<<"carLifeLibDestory()"<<endl;
//		CCarLifeLib::getInstance()->carLifeLibDestory();
//
//		sleep(2);//sleep 2s
//		cout<<"connectionSetup()"<<endl;
//		CCarLifeLib::getInstance()->connectionSetup();
//
//		//carLifeLibDestory() test
//		sleep(2);//sleep 2s
//		cout<<"carLifeLibDestory()"<<endl;
//		CCarLifeLib::getInstance()->carLifeLibDestory();
//
//		sleep(2);//sleep 2s
//		cout<<"connectionSetup()"<<endl;
//		CCarLifeLib::getInstance()->connectionSetup();
//
//		//disconnect() test
//		sleep(2);//sleep 2s
//		cout<<"disconnect()"<<endl;
//		CCarLifeLib::getInstance()->disconnect();
//		sleep(2);//sleep 2s
//		cout<<"connectionSetup()"<<endl;
//		CCarLifeLib::getInstance()->connectionSetup();
	}
	
	// create receive thread for cmd, video, media, navi tts, vr, control channels
	ret=pthread_create(&id, NULL, cmdReceiveThread, NULL);
	if(ret!=0) {
		cout<<"cmdReceiveThread create failed!"<<endl;
	}else{
	cout<<"cmdReceiveThread create!"<<endl;
	}

	ret=pthread_create(&id, NULL, videoReceiveThread, NULL);
	if(ret!=0) {
		cout<<"videoReceivThread create failed!"<<endl;
	}else{
	cout<<"videoReceivThread create !"<<endl;
	}

	ret=pthread_create(&id, NULL, mediaReceiveThread, NULL);
	if(ret!=0) {
		cout<<"mediaReceivThread create failed!"<<endl;
	}else{
	cout<<"mediaReceivThread create !"<<endl;
	}

	ret=pthread_create(&id, NULL, ttsReceiveThread, NULL);
	if(ret!=0) {
		cout<<"ttsReceivThread create failed!"<<endl;
	}else{
	cout<<"ttsReceivThread create !"<<endl;
	}

	ret=pthread_create(&id, NULL, vrReceiveThread, NULL);
	if(ret!=0) {
		cout<<"vrReceivThread create failed!"<<endl;
	}else{
	cout<<"vrReceivThread create !"<<endl;
	}

	// channel test
	cout<<"CarLifeLib test item: "<<endl;
	cout<<"\t1. command channel test;"<<endl;
	cout<<"\t2. video channel test;"<<endl;
	cout<<"\t3. media channel test;"<<endl;
	cout<<"\t4. tts channel test;"<<endl;
	cout<<"\t5. vr channel test;"<<endl;
	cout<<"\t6. control channel test;"<<endl;
	cout<<">>";
	cin>>item;

	switch(item) {
		// cmd channel test
		case 1:
			// head unit send protocol version information to mobile device
			CCarLifeLib::getInstance()->cmdHUProtoclVersion(&huProtocolVersion);

			// 0x00018048 
			// CCarLifeLib::getInstance()->cmdHuAuthenRequest(&authenRequest);

			// setFocusUIConfig(1);
			// 0x00018052
			// CCarLifeLib::getInstance()->cmdFeatureConfigResponse(&configList);

			// 0x00018056
//			CCarLifeLib::getInstance()->cmdVideoEncoderJPEG();
			break;
		//video channel test
		case 2:
			// it is necessary to send MSG_CMD_HU_PROTOCOL_VERSION(0x00018001) message
			CCarLifeLib::getInstance()->cmdHUProtoclVersion(&huProtocolVersion);
			
			CCarLifeLib::getInstance()->cmdVideoEncoderInit(&initVideoParam);
			sleep(2);//sleep 2s
			CCarLifeLib::getInstance()->cmdVideoEncoderStart();
			break;
		// media channel test
		case 3:
			// it is necessary to send MSG_CMD_HU_PROTOCOL_VERSION(0x00018001) message
			CCarLifeLib::getInstance()->cmdHUProtoclVersion(&huProtocolVersion);
			// receive media data
			break;
		//navi tts channel test
		case 4:
			// it is necessary to send MSG_CMD_HU_PROTOCOL_VERSION(0x00018001) message
			CCarLifeLib::getInstance()->cmdHUProtoclVersion(&huProtocolVersion);
			// receive tts data
			break;
		// vr channel test
		case 5:
			// it is necessary to send MSG_CMD_HU_PROTOCOL_VERSION(0x00018001) message
			CCarLifeLib::getInstance()->cmdHUProtoclVersion(&huProtocolVersion);

			CCarLifeLib::getInstance()->sendVRRecordData(vrData, 1024, 0);
			break;
		// control channel test
		case 6:
			// it is necessary to send MSG_CMD_HU_PROTOCOL_VERSION(0x00018001) message
			CCarLifeLib::getInstance()->cmdHUProtoclVersion(&huProtocolVersion);

			// CCarLifeLib::getInstance()->ctrlTouchAction(&touchAction);
			// CCarLifeLib::getInstance()->ctrlTouchCarHardKeyCode(0x0000000F);//previous song
			CCarLifeLib::getInstance()->ctrlTouchCarHardKeyCode(&touchCarHardKeyCode);//next song
			break;
		default:
			break;
	}
	
	while(1) {
		sleep(1);
	}

	// release CarLifeVehicleLib resources
	CCarLifeLib *pCCarLifeLib=CCarLifeLib::getInstance();
	pCCarLifeLib->carLifeLibDestory();
	
	return 0;
}

// cmd channel receive thread
void *cmdReceiveThread(void *arg) {
	// register call back
	CCarLifeLib::getInstance()->cmdRegisterProtocolVersionMatchStatus(cmdProtocolVersionMatchStatus);
	CCarLifeLib::getInstance()->cmdRegisterMDInfro(cmdMDInfro);
	CCarLifeLib::getInstance()->cmdRegisterMDBTPairInfro(cmdMDBTPairInfro);
	CCarLifeLib::getInstance()->cmdRegisterVideoEncoderInitDone(cmdVideoEncoderInitDone);
	CCarLifeLib::getInstance()->cmdRegisterVideoEncoderFrameRateChangeDone(cmdVideoEncoderFrameRateChangeDone);
	CCarLifeLib::getInstance()->cmdRegisterTelStateChangeIncoming(cmdTelStateChangeIncoming);
	CCarLifeLib::getInstance()->cmdRegisterTelStateChangeOutGoing(cmdTelStateChangeOutGoing);
	CCarLifeLib::getInstance()->cmdRegisterTelStateChangeIdle(cmdTelStateChangeIdle);
	CCarLifeLib::getInstance()->cmdRegisterTelStateChangeInCalling(cmdTelStateChangeInCalling);
	CCarLifeLib::getInstance()->cmdRegisterScreenOn(cmdScreenOn);
	CCarLifeLib::getInstance()->cmdRegisterScreenOff(cmdScreenOff);
	CCarLifeLib::getInstance()->cmdRegisterScreenUserPresent(cmdScreenUserPresent);
	CCarLifeLib::getInstance()->cmdRegisterForeground(cmdForeground);
	CCarLifeLib::getInstance()->cmdRegisterBackground(cmdBackground);
	CCarLifeLib::getInstance()->cmdRegisterGoToDeskTop(cmdGoToDeskTop);
	CCarLifeLib::getInstance()->cmdRegisterMicRecordWakeupStart(cmdMicRecordWakeupStart);
	CCarLifeLib::getInstance()->cmdRegisterMicRecordEnd(cmdMicRecordEnd);
	CCarLifeLib::getInstance()->cmdRegisterMicRecordRecogStart(cmdMicRecordRecogStart);
	// 0x00010026
	CCarLifeLib::getInstance()->cmdRegisterModuleStatus(cmdModuleStatus);
	// 0x00010030
	CCarLifeLib::getInstance()->cmdRegisterNaviNextTurnInfo(cmdNaviNextTurnInfo);
	// 0x00010031
	CCarLifeLib::getInstance()->cmdRegisterCarDataSubscribe(cmdCarDataSubscribe);	
	// 0x00010033
	CCarLifeLib::getInstance()->cmdRegisterCarDataSubscribeStart(cmdCarDataSubscribeStart);
	// 0x00010034
	CCarLifeLib::getInstance()->cmdRegisterCarDataSubscribeStop(cmdCarDataSubscribeStop);
	// 0x00010035
	CCarLifeLib::getInstance()->cmdRegisterMediaInfo(cmdMediaInfo);
	// 0x00010036
	CCarLifeLib::getInstance()->cmdRegisterMediaProgressBar(cmdMediaProgressBar);
	// 0x00010037
	CCarLifeLib::getInstance()->cmdRegisterConnectException(cmdRegisterConnectException);
	// 0x00010038
	CCarLifeLib::getInstance()->cmdRegisterRequestGoToForeground(cmdRegisterRequestGoToForeground);
	// 0x00010039
	CCarLifeLib::getInstance()->cmdRegisterUIActionSound(cmdRegisterUIActionSound);

	// 0x00010049 
	CCarLifeLib::getInstance()->cmdRegisterMdAuthenResponse(cmdRegisterMdAuthenResponse);

	// 0x00010051
	CCarLifeLib::getInstance()->cmdRegisterFeatureConfigRequest(cmdRegisterFeatureConfigRequest);

	// 0x00010057
	CCarLifeLib::getInstance()->cmdRegisterVideoEncoderJPEGAck(cmdRegisterVideoEncoderJPEGAck);

	// 0x00010058(Deprecated)

	// 0x00010059
	CCarLifeLib::getInstance()->cmdRegisterMdExit(cmdRegisterMdExit);

	while(1) {
		//receive data from command channel
		if(-1==CCarLifeLib::getInstance()->cmdReceiveOperation()) {

			cout<<"command channel receive thread exit!"<<endl;
				
			break;
			}
	}
}

//video channel receive thread
void *videoReceiveThread(void *arg) {
	CCarLifeLib::getInstance()->videoRegisterDataReceive(videoDataReceive);
	CCarLifeLib::getInstance()->videoRegisterHeartBeat(videoHeartBeat);

	while(1) {
		if(-1==CCarLifeLib::getInstance()->videoReceiveOperation()) {
			cout<<"video channel receive thread exit!"<<endl;
			break;
		}
	}
}

//media channel receive tread
void *mediaReceiveThread(void *arg) {
	CCarLifeLib::getInstance()->mediaRegisterInit(mediaInit);
	CCarLifeLib::getInstance()->mediaRegisterNormalData(mediaNormalData);
	CCarLifeLib::getInstance()->mediaRegisterStop(mediaStop);
	CCarLifeLib::getInstance()->mediaRegisterPause(mediaPause);
	CCarLifeLib::getInstance()->mediaRegisterResume(mediaResume);
	CCarLifeLib::getInstance()->mediaRegisterSeek(mediaSeek);

	while(1) {
		if(-1==CCarLifeLib::getInstance()->mediaReceiveOperation()) {
			cout<<"media channel thread exit!"<<endl;
			break;
		}
	}
}

//tts channel receive thread
void *ttsReceiveThread(void *arg) {
	CCarLifeLib::getInstance()->ttsRegisterInit(ttsInit);
	CCarLifeLib::getInstance()->ttsRegisterNormalData(ttsNormalData);
	CCarLifeLib::getInstance()->ttsRegisterStop(ttsStop);

	while(1) {
		if(-1==CCarLifeLib::getInstance()->ttsReceiveOperation()) {
			cout<<"tts channel thread exit!"<<endl;
			break;
		}
	}
}

//vr channel receive thread
void *vrReceiveThread(void *arg) {
	CCarLifeLib::getInstance()->vrRegisterInit(vrInit);
	CCarLifeLib::getInstance()->vrRegisterNormalData(vrNormalData);
	CCarLifeLib::getInstance()->vrRegisterStop(vrStop);

	while(1) {
		if(-1==CCarLifeLib::getInstance()->vrReceiveOperation()) {
			cout<<"vr channel thread exit!"<<endl;
			break;
		}
	}
}

/**
 CALLBACK FUNCTION IMPLEMENT
 */
//video channel callback functions
void videoDataReceive(u8 *data, u32 len) {
	cout<<"videoDataReceive() is invoked"<<endl;
	cout<<"\treceive video data: "<<len<<" bytes"<<endl;
/*
	for(int i=0;i<len;i++) {
		cout<<data[i]<<" ";
	}

	cout<<endl;
*/
}

void videoHeartBeat() {
	cout<<"videoHeartBeat() is invoked"<<endl;
	cout<<"\tvideo heart beat received!";
}






//media channel callback functions
void mediaInit(S_AUDIO_INIT_PARAMETER *initParam) {
	cout<<"mediaInit() is invoked"<<endl;
	cout<<"\tsampleRate: "<<initParam->sampleRate<<endl;
	cout<<"\tchannelConfig: "<<initParam->channelConfig<<endl;
	cout<<"\tsampleFormat: "<<initParam->sampleFormat<<endl;
}

void mediaNormalData(u8 *data, u32 len) {
	cout<<"mediaNormalData() is invoked"<<endl;
	cout<<"\treceive media data: "<<len<<" bytes"<<endl;
/*
	for(int i=0;i<len;i++) {
		cout<<data[i]<<" ";
	}

	cout<<endl;
*/
}

void mediaStop() {
	cout<<"mediaStop() is invoked"<<endl;
	cout<<"\tmedia stop status received!"<<endl;
}

void mediaPause() {
	cout<<"mediaPause() is invoked"<<endl;
	cout<<" \tmedia pause status received!"<<endl;
}

void mediaResume() {
	cout<<"mediaResume() is invoked"<<endl;
	cout<<"\tmedia resume status received!"<<endl;
}

void mediaSeek() {
	cout<<"mediaSeek() is invoked"<<endl;
	cout<<"\tmedia seek status received!"<<endl;
}




//tts channel callback functions
void ttsInit(S_AUDIO_INIT_PARAMETER *initParam) {
	cout<<"ttsInit() is invoked"<<endl;
	cout<<"\tsampleRate: "<<initParam->sampleRate<<endl;
	cout<<"\tchannelConfig: "<<initParam->channelConfig<<endl;
	cout<<"\tsampleFormat: "<<initParam->sampleFormat<<endl;
}

void ttsNormalData(u8 *data, u32 len) {
	cout<<"ttsNormalData() is invoked"<<endl;
	cout<<"\treceive tts data: "<<len<<" bytes"<<endl;
/*
	for(int i=0;i<len;i++) {
		cout<<data[i]<<" ";
	}

	cout<<endl;
*/
}

void ttsStop() {
	cout<<"ttsStop() is invoked"<<endl;
	cout<<"\ttts stop status received!"<<endl;
}


//vr channel callback functions
void vrInit(S_AUDIO_INIT_PARAMETER *initParam) {
	cout<<"vrInit() is invoked"<<endl;
	cout<<"\tsampleRate: "<<initParam->sampleRate<<endl;
	cout<<"\tchannelConfig: "<<initParam->channelConfig<<endl;
	cout<<"\tsampleFormat: "<<initParam->sampleFormat<<endl;
}

void vrNormalData(u8 *data, u32 len) {
	cout<<"vrNormalData() is invoked"<<endl;
	cout<<"\treceive vr data: "<<len<<" bytes"<<endl;
/*
	for(int i=0;i<len;i++) {
		cout<<data[i]<<" ";
	}

	cout<<endl;
*/
}

void vrStop() {
	cout<<"vrStop() is invoked"<<endl;
	cout<<"\tvr stop status received!"<<endl;
}

//cmd channel
void cmdProtocolVersionMatchStatus(S_PROTOCOL_VERSION_MATCH_SATUS* status) {
	cout<<"cmdProtocolVersionMatchStatus() is invoked"<<endl;
	cout<<"\tprotocol version match status: "<<status->matchStatus<<endl;
}

void cmdMDInfro(S_MD_INFO* mdInfro) {
	cout<<"cmdMDInfro() is invoked"<<endl;
	cout<<"\tos: "<<mdInfro->os<<endl;
	cout<<"\tboard: "<<mdInfro->board<<endl;
	cout<<"\tbootloader: "<<mdInfro->bootloader<<endl;
	cout<<"\tbrand: "<<mdInfro->brand<<endl;
	cout<<"\tcpu_abi: "<<mdInfro->cpu_abi<<endl;
	cout<<"\tcpu_abi2: "<<mdInfro->cpu_abi2<<endl;
	cout<<"\tdevice: "<<mdInfro->device<<endl;
	cout<<"\tdisplay: "<<mdInfro->display<<endl;
	cout<<"\tfingerprint: "<<mdInfro->fingerprint<<endl;
	cout<<"\thardware: "<<mdInfro->hardware<<endl;
	cout<<"\thost: "<<mdInfro->host<<endl;
	cout<<"\tcid: "<<mdInfro->cid<<endl;
	cout<<"\tmanufacturer: "<<mdInfro->manufacturer<<endl;
	cout<<"\tmodel: "<<mdInfro->model<<endl;
	cout<<"\tproduct: "<<mdInfro->product<<endl;
	cout<<"\tserial: "<<mdInfro->serial<<endl;
	cout<<"\tcodename: "<<mdInfro->codename<<endl;
	cout<<"\tincremental: "<<mdInfro->incremental<<endl;
	cout<<"\trelease: "<<mdInfro->release<<endl;
	cout<<"\tsdk: "<<mdInfro->sdk<<endl;
	cout<<"\tsdk_int: "<<mdInfro->sdk_int<<endl;
	
}

void cmdMDBTPairInfro(BTPairInfo* info) {
	cout<<"cmdMDBTPairInfro() is invoked"<<endl;
	cout<<"/taddress: "<<info->address<<endl;
	cout<<"/tpassKey: "<<info->passKey<<endl;
	cout<<"/thash: "<<info->hash<<endl;
	cout<<"/trandomizer: "<<info->randomizer<<endl;
	cout<<"/tuuid: "<<info->uuid<<endl;
	cout<<"/tname: "<<info->name<<endl;
	cout<<"/tstatus: "<<info->status<<endl;
}

void cmdVideoEncoderInitDone(S_VIDEO_ENCODER_INIT_DONE* videoEncoderInitDone) {
	cout<<"cmdVideoEncoderInitDone() is invoked"<<endl;
	cout<<"\twidth: "<<videoEncoderInitDone->width<<endl;
	cout<<"\theight: "<<videoEncoderInitDone->height<<endl;
	cout<<"\tframeRate: "<<videoEncoderInitDone->frameRate<<endl;
}

void cmdVideoEncoderFrameRateChangeDone(S_VIDEO_ENCODER_FRAME_RATE_CHANGE_DONE* videoEncoderFrameRateChangeDone) {
	cout<<"cmdVideoEncoderFrameRateChangeDone() is invoked"<<endl;
	cout<<"\tframeRate: "<<videoEncoderFrameRateChangeDone->frameRate<<endl;
}

void cmdTelStateChangeIncoming() {
	cout<<"cmdTelStateChangeIncoming() is invoked"<<endl;
}

void cmdTelStateChangeOutGoing() {
	cout<<"cmdTelStateChangeOutGoing() is invoked"<<endl;
}

void cmdTelStateChangeIdle() {
	cout<<"cmdTelStateChangeIdle() is invoked"<<endl;
}
void cmdTelStateChangeInCalling() {
	cout<<"cmdTelStateChangeInCalling() is invoked"<<endl;
}

void cmdScreenOn() {
	cout<<"cmdScreenOn() is invoked"<<endl;
}
void cmdScreenOff() {
	cout<<"cmdScreenOff() is invoked"<<endl;
}
void cmdScreenUserPresent() {
	cout<<"cmdScreenUserPresent() is invoked"<<endl;
}

void cmdForeground() {
	cout<<"cmdForeground() is invoked"<<endl;
}

void cmdBackground() {
	cout<<"cmdBackground() is invoked"<<endl;
}

void cmdGoToDeskTop() {
	cout<<"cmdGoToDeskTop() is invoked"<<endl;
}

void cmdMicRecordWakeupStart() {
	cout<<"cmdMicRecordWakeupStart() is invoked"<<endl;
}
void cmdMicRecordEnd() {
	cout<<"cmdMicRecordEnd() is invoked"<<endl;
}

void cmdMicRecordRecogStart() {
	cout<<"cmdMicRecordRecogStart() is invoked"<<endl;
}

// 0x00010026
void cmdModuleStatus(S_MODULE_STATUS_LIST_MOBILE*) {
	cout<<"cmdModuleStatus is invoked"<<endl;
}

// 0x00010030
void cmdNaviNextTurnInfo(S_NAVI_NEXT_TURN_INFO*) {
	cout<<"cmdNaviNextTurnInfo is invoked"<<endl;
}

// 0x00010031
void cmdCarDataSubscribe(S_VEHICLE_INFO_LIST*) {
	cout<<"cmdCarDataSubscribe is invoked"<<endl;
}

// 0x00010033
void cmdCarDataSubscribeStart(S_VEHICLE_INFO_LIST*) {	
	cout<<"cmdCarDataSubscribeStart is invoked"<<endl;
}

// 0x00010034
void cmdCarDataSubscribeStop(S_VEHICLE_INFO_LIST*) {
	cout<<"cmdCarDataSubscribeStop is invoked"<<endl;
}

// 0x00010035
void cmdMediaInfo(S_MEDIA_INFO* info) {
	cout<<"cmdMediaInfo is invoked"<<endl;
	
	cout<<"source= "<<info->source<<endl;
	cout<<"song= "<<info->song<<endl;
	cout<<"artist= "<<info->artist<<endl;
	cout<<"album= "<<info->album<<endl;
	//cout<<"albumArt= "<<info->albumArt<<endl;
	cout<<"duration= "<<info->duration<<endl;
	cout<<"playlistNum= "<<info->playlistNum<<endl;
	cout<<"songId= "<<info->songId<<endl;
	cout<<"mode= "<<info->mode<<endl;
	
	
}

// 0x00010036
void cmdMediaProgressBar(S_MEDIA_PROGRESS_BAR*) {
	cout<<"cmdMediaProgressBar is invoked"<<endl;
}

// 0x00010037
void cmdRegisterConnectException(S_CONNECTION_EXCEPTION*) {
	cout<<"cmdRegisterConnectException is invoked"<<endl;
}

// 0x00010038
void cmdRegisterRequestGoToForeground(void) {
	cout<<"cmdRegisterRequestGoToForeground is invoked"<<endl;
}

// 0x00010039
void cmdRegisterUIActionSound(void) {
	cout<<"cmdRegisterUIActionSound is invoked"<<endl;
}

// 0x00010049
void cmdRegisterMdAuthenResponse(S_AUTHEN_RESPONSE* response) {
	cout<<"cmdRegisterMdAuthenResponse is invoked"<<endl;
	cout<<"encryptValue= "<<response->encryptValue<<endl;
}

// 0x00010051
void cmdRegisterFeatureConfigRequest() {
	cout<<"cmdRegisterFeatureConfigRequest is invoked"<<endl;

	setFocusUIConfig(1);
	// 0x00018052
	CCarLifeLib::getInstance()->cmdFeatureConfigResponse(&configList);
}

// 0x00010057
void cmdRegisterVideoEncoderJPEGAck() {
	cout<<"cmdRegisterVideoEncoderJPEGAck is invoked"<<endl;
}

// 0x00010058(Deprecated)

// 0x00010059
void cmdRegisterMdExit() {
	cout<<"cmdRegisterMdExit is invoked"<<endl;
}






