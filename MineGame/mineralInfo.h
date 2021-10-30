#pragma once

//광물의 정보들

/*
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VIOLET,
	DAKR_YELLOW,
*/

/*
광물 색이랑 이름 정하고
*/

/*
	광물의 종류

	파일에 광물을 

*/

//파란색 광물
static const char* BlueMineralName[] = { "◆ BLUE광물-1", "◎ BLUE광물-2", "▲ BLUE광물-3"}; //포인터배열. 포인터를 담고 있는 배열.
static const int BlueMineralCount = sizeof(BlueMineralName) / sizeof(char*);

//초록색 광물
static const char* GreenMineralName[] = { "◀ GREEN광물-1", "♣ GREEN광물-2", "※ GREEN광물-3" }; //포인터배열. 포인터를 담고 있는 배열.
static const int GreenMineralCount = sizeof(GreenMineralName) / sizeof(char*);

//하늘색 광물
static const char* SkyBlueMineralName[] = { "◆ SKYBLUE광물-1", "◆ SKYBLUE광물-2", "◆ SKYBLUE광물-3" }; //포인터배열. 포인터를 담고 있는 배열.
static const int SkyBlueMineralCount = sizeof(SkyBlueMineralName) / sizeof(char*);

//빨강색 광물
static const char* RedMineralName[] = { "◆ RED광물-1", "◆ RED광물-2", "◆ RED광물-3" }; //포인터배열. 포인터를 담고 있는 배열.
static const int RedMineralCount = sizeof(RedMineralName) / sizeof(char*);

//보라색 광물
static const char* VioletMineralName[] = { "◆ VIOLET광물-1", "◆ VIOLET광물-2", "◆ VIOLET광물-3" }; //포인터배열. 포인터를 담고 있는 배열.
static const int VioletMineralCount = sizeof(VioletMineralName) / sizeof(char*);

//노랑색 광물
static const char* YellowMineralName[] = { "◆ YELLOW광물-1", "◆ YELLOW광물-2", "◆ YELLOW광물-3" }; //포인터배열. 포인터를 담고 있는 배열.
static const int YellowMineralCount = sizeof(YellowMineralName) / sizeof(char*);