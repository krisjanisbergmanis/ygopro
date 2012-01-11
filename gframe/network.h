#ifndef NETWORK_H
#define NETWORK_H

#include "config.h"
#include <set>
#include <vector>

namespace ygo {

struct HostInfo {
	unsigned char rule;
	unsigned char mode;
	unsigned int lflist;
	bool no_check_deck;
	bool no_shuffle_deck;
	unsigned int start_lp;
	unsigned char start_hand;
	unsigned char draw_count;
};

struct HostPacket {
	unsigned short identifier;
	unsigned short version;
	unsigned int address;
	unsigned short port;
	HostInfo host;
};

struct HostRequest {
	unsigned short identifier;
};

struct CTOS_Response {
};
struct CTOS_ChangeDeck {
};
struct CTOS_PlayerInfo {
	unsigned short name[20];
};
struct CTOS_CreateGame {
	HostInfo info;
	unsigned short name[20];
	unsigned short pass[20];
};
struct CTOS_JoinGame {
	unsigned int gameid;
	unsigned short pass[20];
};
struct STOC_DeckError {
	unsigned char reason;
	unsigned int code;
};
struct STOC_CreateGame {
	unsigned int gameid;
};
struct STOC_JoinGame {
	HostInfo info;
	unsigned char type;
};
struct STOC_ExitGame {
};
struct STOC_JoinFail {
	//0 - common error
	//1 - password incorrect
	//2 - host denied
	unsigned int reason;
};
struct STOC_HS_PlayerEnter {
	unsigned short name[20];
	unsigned char pos;
};
struct STOC_HS_PlayerChange {
	//pos<<4 | state
	unsigned char status;
};
struct STOC_HS_WatchChange {
	unsigned short watch_count;
};

}

#define NETWORK_SERVER_ID	0x7428
#define NETWORK_CLIENT_ID	0xdef6

#define CTOS_RESPONSE		0x1
#define CTOS_CHANGEDECK		0x2
#define CTOS_PLAYER_INFO	0x10
#define CTOS_CREATE_GAME	0x11
#define CTOS_JOIN_GAME		0x12
#define CTOS_EXIT_GAME		0x13
#define CTOS_HS_TODUELIST	0x20
#define CTOS_HS_TOOBSERVER	0x21
#define CTOS_HS_READY		0x22
#define CTOS_HS_KICK1		0x23
#define CTOS_HS_KICK2		0x24
#define CTOS_HS_START		0x25

#define STOC_GAME_MSG		0x1
#define STOC_DECK_ERROR		0x2
#define STOC_CREATE_GAME	0x11
#define STOC_JOIN_GAME		0x12
#define STOC_EXIT_GAME		0x13
#define STOC_JOIN_FAIL		0x14
#define STOC_GAME_START		0x15
#define STOC_HS_PLAYER_ENTER	0x20
#define STOC_HS_PLAYER_CHANGE	0x21
#define STOC_HS_WATCH_CHANGE	0x22

#define PLAYERCHANGE_READY		0x1
#define PLAYERCHANGE_NOTREADY	0x2
#define PLAYERCHANGE_LEAVE		0x3
#define PLAYERCHANGE_OBSERVE	0x4

#define MODE_SINGLE		0x1
#define MODE_MATCH		0x2
#endif //NETWORK_H
