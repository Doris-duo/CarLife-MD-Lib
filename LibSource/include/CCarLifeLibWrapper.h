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
#ifndef C_CARLIFE_LIB_WRAPPER_H
#define C_CARLIFE_LIB_WRAPPER_H
#include<iostream>
#include<string>
using namespace std;

typedef unsigned char u8;
typedef unsigned int u32;
typedef int i32;
typedef double d64;
typedef unsigned long long u64;

namespace CommonUtilH{
/*******************************************************
STRUCT
*******************************************************/
//struct for cmd channel
typedef struct HUProtocolVersion{
	u32 majorVersion;
    	u32 minorVersion;

}S_HU_PROTOCOL_VERSION;

typedef struct ProtocolVersionMatchStatus{
	u32 matchStatus;
}S_PROTOCOL_VERSION_MATCH_SATUS;

//0x00018003
typedef struct HUInfo{
	string os;//1
	string board ;//2
	string bootloader ;//3
	string brand;//4
	string cpu_abi;//5
	string cpu_abi2 ;//6
	string device ;//7
	string display ;//8
	string fingerprint ;//9
	string hardware ;//10
	string host ;//11
	string cid ;//12
	string manufacturer ;//13
	string model ;//14
	string product ;//15
	string serial;//16
	string codename ;//17
	string incremental;//18
	string release ;//19
	string sdk ;//20
	u32 sdk_int;//21
	string token;//22

	string btaddress;//23

}S_HU_INFO;

//0x00010004
typedef struct MDInfo{
	string os;//1
	string board ;//2
	string bootloader ;//3
	string brand;//4
	string cpu_abi;//5
	string cpu_abi2 ;//6
	string device ;//7
	string display ;//8
	string fingerprint ;//9
	string hardware ;//10
	string host ;//11
	string cid ;//12
	string manufacturer ;//13
	string model ;//14
	string product ;//15
	string serial;//16
	string codename ;//17
	string incremental;//18
	string release ;//19
	string sdk ;//20
	u32 sdk_int;//21
	string token;//22

	string btaddress;//23

}S_MD_INFO;

//0x00018005 0x00010006
typedef struct BTPairInfo{
	string address ;
	string passKey ;
	string hash ;
	string randomizer;
	string uuid;
	string name;
	u32 status;
}S_BT_PAIR_INFO;

typedef struct VideoEncoderInit{
	u32 width ;
	u32 height ;
	u32 frameRate;
}S_VIDEO_ENCODER_INIT;

typedef struct VideoEncoderInitDone{
	u32 width ;
	u32 height ;
	u32 frameRate;
}S_VIDEO_ENCODER_INIT_DONE;

typedef struct VideoEncoderFrameRateChange{
	u32 frameRate;
}S_VIDEO_ENCODER_FRAME_RATE_CHANGE;

typedef struct VideoEncoderFrameRateChangeDone{
	u32 frameRate;
}S_VIDEO_ENCODER_FRAME_RATE_CHANGE_DONE;

//0x00018010
typedef struct CarVelocity{
	u32 speed;
	u64 timeStamp;
}S_CAR_VELOCITY;

//0x00018010
typedef struct CarGPS{
	u32 antennaState;
	u32 signalQuality;
	// dBHz
	u32 latitude;
	// 1/1,000,000 degrees
	u32 longitude;
	// 1/1,000,000 degrees
	u32 height ;
	// 0.1 meters
	u32 speed ;
	// 0.01 km/h units
	u32 heading;
	// 0.1 degrees
	u32 year;
	u32 month;
	u32 day;
	u32 hrs ;
	u32 min ;
	u32 sec ;
	u32 fix;
	u32 hdop;
	// units 0.1
	u32 pdop ;
	// units 0.1
	u32 vdop ;
	// units 0.1
	u32 satsUsed ;
	u32 satsVisible;
	u32 horPosError ;
	u32 vertPosError;
	u32 northSpeed;
	// 0.01m/s
	u32 eastSpeed;
	// 0.01m/s
	u32 vertSpeed; 
	// 0.01m/s

	u64 timeStamp;
}S_CAR_GPS;

//0x00018011
typedef struct CarGyroscope{
	i32 gyroType;
	d64 gyroX;
	d64 gyroY;
	d64 gyroZ;
	u64 timeStamp;
}S_CAR_GYROSCOPE;

//0x00018012
typedef struct CarAcceleration{
	d64 accX ;
	d64 accY ;
	d64 accZ ;

	u64 timeStamp ;

}S_CAR_ACCELERATION;

//0x00018013
typedef struct CarOil{
	i32 level;
	i32 range;
	bool lowFullWarning;
}S_CAR_OIL;

//struct for media && tts channel
typedef struct AudioInitParameter{
	u32 sampleRate;
	u32 channelConfig;
	u32 sampleFormat;
}S_AUDIO_INIT_PARAMETER;

//struct for ctrl channel
typedef struct TouchAction{
	u32 action;
	u32 x ;
	u32 y ;

}S_TOUCH_ACTION;

typedef struct TouchActionDown{
	u32 x ;
	u32 y ;
}S_TOUCH_ACTION_DOWN;

typedef struct TouchActionUp{
	u32 x ;
	u32 y ;
}S_TOUCH_ACTION_UP;

typedef struct TouchActionMove{
	u32 x ;
	u32 y ;
}S_TOUCH_ACTION_MOVE;

typedef struct TouchSingleClick{
	u32 x;
	u32 y;
}S_TOUCH_SIGNAL_CLICK;

typedef struct TouchDoubleClick{
	u32 x;
	u32 y;
}S_TOUCH_DOUBLE_CLICK;

typedef struct TouchLongPress{
	u32 x;
	u32 y;
}S_TOUCH_LONG_PRESS;

typedef struct TouchCarHardkeyCode{
	u32 keycode;
}S_TOUCH_CAR_HARD_KEY_CODE;

typedef struct TouchUIActionSound{
	//reserved
}S_TOUCH_UI_ACTION_SOUND;

//0x00018025

//0x00010026
typedef struct ModuleStatusMobile{
	u32 moduleID;
	u32 statusID;
	struct ModuleStatusMobile* next;
}S_MODULE_STATUS_MOBILE;

typedef struct ModuleStatusListMobile{
	u32	cnt ;
	S_MODULE_STATUS_MOBILE* moduleStatus;
}S_MODULE_STATUS_LIST_MOBILE;

//0x00018027
typedef struct StatisticsInfo{
	string cuid;
	string versionName;
	u32 versionCode;
	string channel;
	u32 connectCount;
	u32 connectSuccessCount;
	u32 connectTime;
	string crashLog;
}S_STATISTICS_INFO;

//0x00018028
typedef struct ModuleStatusControl{
	u32 moduleID;
        u32 statusID;
}S_MODULE_STATUS_CONTROL;

//0x00018029
typedef struct GearInfo
{
	u32 gear;
}S_GEAR_INFO;

//0x00010030
typedef struct NaviNextTurnInfo
{
	u32 action ;
	u32 nextTurn;
	string roadName ;
	u32 totalDistance ;
	u32 remainDistance ;
	u32 time;
}S_NAVI_NEXT_TURN_INFO;

//0x00010031
//0x00010032
//0x00010033
//0x00010034
typedef struct VehicleInfo{
	u32 moduleID;
	i32 flag;
	u32 frequency;

	struct VehicleInfo* pNext;
}S_VEHICLE_INFO;

typedef struct VehicleInfoList{
	u32	cnt ;
	S_VEHICLE_INFO* pVehicleInfo;
}S_VEHICLE_INFO_LIST;

//0x00010035
typedef struct MediaInfo
{
	string source ;
	string song ;
	string artist ;
	string album ;
	string albumArt ;
	u32 duration ;
	u32 playlistNum ;
	string songId ;
	u32 mode ;
}S_MEDIA_INFO;

//0x00010036
typedef struct MediaProgressBar{
	u32 progressBar;
}S_MEDIA_PROGRESS_BAR;

//0x00010037
typedef struct ConnectException
{
    u32 exceptionType;
}S_CONNECTION_EXCEPTION;	

//0x00010038

//0x00010039

//0x00010040
typedef struct BTHfpRequest{
	u32 command;
	string phoneNum;
	u32 dtmfCode;
}S_BT_HFP_REQUEST;

//0x00018041
typedef struct BTHfpIndication{
	u32 state;
	string phoneNum;
	string name;
	string address;
}S_BT_HFP_INDICATION;

//0x00018042
typedef struct BTHfpConnection{
	u32 state;
	string address;
	string name;
}S_BT_HFP_CONNECTION;

//0x00018043
//0x00010044
//0x00018045
//0x00018046
typedef struct MobileCarLifeInfo{
	u32 moduleID;
	bool supportFlag;
	u32 frequency;

	struct MobileCarLifeInfo *pNext; 
}S_MOBILE_CARLIFE_INFO;

typedef struct SubscribeMobileCarLifeInfoList{
	u32 cnt;
	S_MOBILE_CARLIFE_INFO *pMobileCarLifeInfo;
}S_SUBSCRIBE_MOBILE_CARLIFE_INFO_LIST;

//0x00010047
typedef struct NaviAssitantGuideInfo{
	u32 action;
	u32 assistantType;
	u32 trafficSignType;
	u32 totalDistance;
	u32 remainDistance;
	u32 cameraSpeed;
}S_NAVI_ASSITANT_GUIDE_INFO;

//0x00018048
typedef struct AuthenRequest{
	string randomValue;
}S_AUTHEN_REQUEST;

//0x00010049
typedef struct AuthenResponse{
	string encryptValue;
}S_AUTHEN_RESPONSE;

//0x0001004A
typedef struct HUAuthenResult{
	bool authenResult;
}S_HU_AUTHEN_RESULT;

//0x0001804B
typedef struct MDAuthenResult{
	bool authenResult;
}S_MD_AUTHEN_RESULT;

//0x0001004C
//none

//0x0001004D
typedef struct BTStartPairReq{
	u32 osType;
	string address;
}S_BT_START_PAIR_REQ;

//0x0001804E
typedef struct BTHfpResponse{
	u32 status;
	u32 cmd;
	u32 dtmfCode;
}S_BT_HFP_RESPONSE;

//0x0001004F
typedef struct BTHfpStatusRequest{
	u32 type;
}S_BT_HFP_STATUS_REQUEST;

//0x00018050
typedef struct BTHfpStatusResponse{
	u32 status;
	u32 type;
}S_BT_HFP_STATUS_RESPONSE;

//0x00018051
//none

//0x00018052
typedef struct FeatureConfig{
	string key;
	u32 value;

	struct FeatureConfig *pNext;
}S_FEATURE_CONFIG;

typedef struct FeatureConfigList{
	u32 cnt;

	S_FEATURE_CONFIG *pFeatureConfig;
}S_FEATURE_CONFIG_LIST;

//0x00018053
typedef struct BTStartIdentifyReq{
	string address;
}S_BT_START_IDENTIFY_REQ;

//0x00010054
typedef struct BTIdentifyResultInd{
	u32 status;
	string address;
}S_BT_INDENTIFY_RESULT_IND;

//0x00018055
typedef struct ErrorCode{
	string errorCode;
}S_ERROR_CODE;

//0x00010058
typedef struct BtHfpCallStatusCover{
	int callStatus;
	string phoneNum;
	string name;
}S_CALL_STATUS_COVER;



}

namespace CCarLifeLibH{
using namespace CommonUtilH;
/**********************************************************
CLASS
**********************************************************/
class CCarLifeLib{
public:
	~CCarLifeLib();
/*==============================================
				initialization process
===============================================*/
	static CCarLifeLib* getInstance();
	int carLifeLibInit();
	void carLifeLibDestory();
	
/*=====================================================
			connection/disconnection between head unit and mobile phone
=======================================================*/
	int connectionSetup();
	int connectionSetup(string mdIP);
	int connectionSetup(string mdIP, string interfaceName);

	void disconnect();

/*==============================================================
		command channel: send method && receive call back register method
===============================================================*/
	int cmdHUProtoclVersion(S_HU_PROTOCOL_VERSION* version);
	int cmdHUInfro(S_HU_INFO* huInfo);
	int cmdHUBTPairInfro(S_BT_PAIR_INFO* info);
	int cmdVideoEncoderInit(S_VIDEO_ENCODER_INIT* initParam);
	int cmdVideoEncoderStart();
	int cmdVideoEncoderPause();
	int cmdVideoEncoderReset();
	int cmdVideoEncoderFrameRateChange(S_VIDEO_ENCODER_FRAME_RATE_CHANGE* videoParam);
	int cmdPauseMedia();
	int cmdCarVelocity(S_CAR_VELOCITY* carVelocity);
	int cmdCarGPS(S_CAR_GPS* cps);
	int cmdCarGyroscope(S_CAR_GYROSCOPE* cyro);
	int cmdCarAcceleration(S_CAR_ACCELERATION* acceleration);
	int cmdCarOil(S_CAR_OIL*);
	int cmdLaunchModeNormal();
	int cmdLaunchModePhone();
	int cmdLaunchModeMap();
	int cmdLaunchModeMusic();
	int cmdReceiveOperation();
	void cmdRegisterProtocolVersionMatchStatus(void (*pFunc)(S_PROTOCOL_VERSION_MATCH_SATUS*));
	void cmdRegisterMDInfro(void (*pFunc)(S_MD_INFO*));
	void cmdRegisterMDBTPairInfro(void (*pFunc)(S_BT_PAIR_INFO*));
	void cmdRegisterVideoEncoderInitDone(void (*pFunc)(S_VIDEO_ENCODER_INIT_DONE*));
	void cmdRegisterVideoEncoderFrameRateChangeDone(void (*pFunc)(S_VIDEO_ENCODER_FRAME_RATE_CHANGE_DONE*));
	void cmdRegisterTelStateChangeIncoming(void (*pFunc)(void));
	void cmdRegisterTelStateChangeOutGoing(void (*pFunc)(void));
	void cmdRegisterTelStateChangeIdle(void (*pFunc)(void));
	void cmdRegisterTelStateChangeInCalling(void (*pFunc)(void));
	void cmdRegisterScreenOn(void (*pFunc)(void));
	void cmdRegisterScreenOff(void (*pFunc)(void));
	void cmdRegisterScreenUserPresent(void (*pFunc)(void));
	void cmdRegisterForeground(void (*pFunc)(void));
	void cmdRegisterBackground(void (*pFunc)(void));
	void cmdRegisterGoToDeskTop(void (*pFunc)(void));
	void cmdRegisterMicRecordWakeupStart(void (*pFunc)(void));
	void cmdRegisterMicRecordEnd(void (*pFunc)(void));
	void cmdRegisterMicRecordRecogStart(void (*pFunc)(void));

	//added on 9th Semptember 2015
	//0x00018025
	int cmdGoToForeground();

	//0x00010026
	void cmdRegisterModuleStatus(void (*pFunc)(S_MODULE_STATUS_LIST_MOBILE*));

	//0x00018027
	int cmdStatisticInfo(S_STATISTICS_INFO*);

	//0x00018028
	int cmdModuleControl(S_MODULE_STATUS_CONTROL*);

	//0x00018029
	int cmdCarDataGear(S_GEAR_INFO*);

	//0x00010030
	void cmdRegisterNaviNextTurnInfo(void (*pFunc)(S_NAVI_NEXT_TURN_INFO*));

	//0x00010031
	void cmdRegisterCarDataSubscribe(void (*pFunc)(S_VEHICLE_INFO_LIST*));

	//0x00018032
	int cmdCarDataSubscribeDone(S_VEHICLE_INFO_LIST*);

	//0x00010033
	void cmdRegisterCarDataSubscribeStart(void (*pFunc)(S_VEHICLE_INFO_LIST*));

	//0x00010034
	void cmdRegisterCarDataSubscribeStop(void (*pFunc)(S_VEHICLE_INFO_LIST*));

	//0x00010035
	void cmdRegisterMediaInfo(void (*pFunc)(S_MEDIA_INFO*));

	//0x00010036
	void cmdRegisterMediaProgressBar(void (*pFunc)(S_MEDIA_PROGRESS_BAR*));

	//0x00010037
	void cmdRegisterConnectException(void (*pFunc)(S_CONNECTION_EXCEPTION*));

	//0x00010038
	void cmdRegisterRequestGoToForeground(void (*pFunc)(void));

	//0x00010039
	void cmdRegisterUIActionSound(void (*pFunc)(void));

	//added on 5th January 2016
	//0x00010040
	void cmdRegisterBtHfpRequest(void (*pFunc)(S_BT_HFP_REQUEST*));

	//0x00018041
	int cmdBtHfpIndication(S_BT_HFP_INDICATION*);

	//0x00018042
	int cmdBtHfpConnection(S_BT_HFP_CONNECTION*);

	//0x00018043 
	int cmdCarLifeDataSubscribe(S_SUBSCRIBE_MOBILE_CARLIFE_INFO_LIST*);

	//0x00010044 
	void cmdRegisterCarLifeDataSubscribeDone(void (*pFunc)(S_SUBSCRIBE_MOBILE_CARLIFE_INFO_LIST*));

	//0x00018045 
	int cmdCarLifeDataSubscribeStart(S_SUBSCRIBE_MOBILE_CARLIFE_INFO_LIST*);

	//0x00018046 
	int cmdCarLifeDataSubscribeStop(S_SUBSCRIBE_MOBILE_CARLIFE_INFO_LIST*);

	//0x00010047 
	void cmdRegisterNaviAssistantGuideInfo(void (*pFunc)(S_NAVI_ASSITANT_GUIDE_INFO*));

	//0x00018048 
	int cmdHuAuthenRequest(S_AUTHEN_REQUEST*);

	//0x00010049 
	void cmdRegisterMdAuthenResponse(void (*pFunc)(S_AUTHEN_RESPONSE*));

	//0x0001804A 
	int cmdHuAuthenResult(S_HU_AUTHEN_RESULT*);

	//0x0001804B
	void cmdRegisterMdAuthenResult(void (*pFunc)(S_MD_AUTHEN_RESULT*));

	//0x0001004C 
	void cmdRegisterGotoForgroundResponse(void (*pFunc)(void));

	//0x0001004D 
	void cmdRegisterStartBtAutoPairRequest(void (*pFunc)(S_BT_START_PAIR_REQ*));

	//0x0001804E
	int cmdBTHfpResponse(S_BT_HFP_RESPONSE*);

	//0x0001004F
	void cmdRegisterBTHfpStatusRequest(void (*pFunc)(S_BT_HFP_STATUS_REQUEST*));
	
	//0x00018050
	int cmdBTHfpStatusResponse(S_BT_HFP_STATUS_RESPONSE*);

	//added on 3th March 2016
	//0x00010051
	void cmdRegisterFeatureConfigRequest(void (*pFunc)(void));

	//0x00018052
	int cmdFeatureConfigResponse(S_FEATURE_CONFIG_LIST*);

	//0x00018053
	int cmdBTStartIdentifyReq(S_BT_START_IDENTIFY_REQ*);

	//0x00010054
	void cmdRegisterBTIdentifyResultInd(void (*pFunc)(S_BT_INDENTIFY_RESULT_IND*));

	//0x00018055
	int cmdErrorCode(S_ERROR_CODE*);

	// added on 31th October 2016
	//0x00018056
	int cmdVideoEncoderJPEG();

	//0x00010057
	void cmdRegisterVideoEncoderJPEGAck(void (*pFunc)(void));

	//0x00010058(Deprecated)
	void cmdRegisterBtHfpCallStatusCover(void (*pFunc)(S_CALL_STATUS_COVER*));

	//0x00010059
	void cmdRegisterMdExit(void (*pFunc)(void));

/*=============================================================
				video channel: receive call back register method
==============================================================*/
	int videoReceiveOperation();
	void videoRegisterDataReceive(void (*pFunc)(u8 *data, u32 len));
	void videoRegisterHeartBeat(void (*pFunc)(void));

/*=============================================================
				media channel: receive call back register method
==============================================================*/
	int mediaReceiveOperation();
	void mediaRegisterInit(void (*pFunc)(S_AUDIO_INIT_PARAMETER*));
	void mediaRegisterNormalData(void (*pFunc)(u8 *data, u32 len));
	void mediaRegisterStop(void (*pFunc)(void));
	void mediaRegisterPause(void (*pFunc)(void));
	void mediaRegisterResume(void (*pFunc)(void));
	void mediaRegisterSeek(void (*pFunc)(void));
	
/*=============================================================
				tts channel: receive call back register method
==============================================================*/
	int ttsReceiveOperation();
	void ttsRegisterInit(void (*pFunc)(S_AUDIO_INIT_PARAMETER*));
	void ttsRegisterNormalData(void (*pFunc)(u8 *data, u32 len));
	void ttsRegisterStop(void (*pFunc)(void));

/*=============================================================
				vr channel: send method
==============================================================*/
	int sendVRRecordData(u8* data, u32 size, u32 timeStamp);
	int vrReceiveOperation();
	void vrRegisterInit(void (*pFunc)(S_AUDIO_INIT_PARAMETER*));
	void vrRegisterNormalData(void (*pFunc)(u8 *data, u32 len));
	void vrRegisterStop(void (*pFunc)(void));

/*=============================================================
				control channel: send method
==============================================================*/
	int ctrlTouchAction(S_TOUCH_ACTION* touchAction);
	int ctrlTouchActionDown(S_TOUCH_ACTION_DOWN* touchActionDown);
	int ctrlTouchActionUp(S_TOUCH_ACTION_UP* touchActionUp);
	int ctrlTouchActionMove(S_TOUCH_ACTION_MOVE* touchActionMove);
	int ctrlTouchSigleClick(S_TOUCH_SIGNAL_CLICK* touchSingleClick);
	int ctrlTouchDoubleClick(S_TOUCH_DOUBLE_CLICK* touchDoubleClick);
	int ctrlTouchLongPress(S_TOUCH_LONG_PRESS* touchLongPress);
	int ctrlTouchCarHardKeyCode(S_TOUCH_CAR_HARD_KEY_CODE* touchCarHardKeyCode);
	int ctrlReceiveOperation();
	void ctrlRegisterUIActionSound(void (*pFunc)(void));
private:
	CCarLifeLib();
	static CCarLifeLib* pInstance;

};
}


























#endif













































