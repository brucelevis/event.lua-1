#ifndef CONSTANSTS_H
#define CONSTANSTS_H


#define kCACHED             1024 * 1024
#define kERROR              64
#define kMAX_IPC            64
#define kCLIENT_HEADER      2
#define kSERVER_HEADER      4
#define kNETD_HEADER        4
#define kMAX_SERVER         64
#define kMAX_NETD           16

#define kWARN_OUTPUT_FLOW 	1024 * 10
#define kMAX_CLIENT_PACKET  1024 * 6
#define kMAX_SERVER_PACKET  1024 * 1024 * 16

#define kCMD_REGISTER             0
#define kCMD_LOGIN_REGISTER       1
#define kCMD_SCENE_REGISTER       2
#define kCMD_SET_SERVER           3
#define kCMD_START_KCP            4
#define kCMD_CLIENT_CLOSE         5
#define kCMD_CLIENT_SEND          6
#define kCMD_CLIENT_BROAD         7
#define kCMD_SERVER_DOWN          8
#define kCMD_SERVER_REPEAT        9
#define kCMD_UPDATE_LOGIN_MASTER  10
#define kCMD_UPDATE_SCENE_MASTER  11
#define kCMD_CLIENT_ENTER         12
#define kCMD_CLIENT_LEAVE         13
#define kCMD_CLIENT_DATA          14

#endif