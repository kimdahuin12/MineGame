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

//파란색 광물
static const char* BlueMineralName[] = { "BLUE광물-1", "BLUE광물-2", "BLUE광물-3"}; //포인터배열. 포인터를 담고 있는 배열.
static const int BlueMineralCount = sizeof(BlueMineralName) / sizeof(char*);

static unsigned int BlueMineralPrice[BlueMineralCount] = { 200, 300, 400};
static float BlueMineralRarity[BlueMineralCount] = { 1.4, 2.3, 4.3};
static int BlueMineralDelTime[BlueMineralCount] = { 2, 3, 4}; //없애고 희귀도에 따라 해도 될 듯하다.

//초록색 광물
static const char* GreenMineralName[] = { "GREEN광물-1", "GREEN광물-2", "GREEN광물-3" }; //포인터배열. 포인터를 담고 있는 배열.
static const int GreenMineralCount = sizeof(GreenMineralName) / sizeof(char*);

static unsigned int GreenMineralPrice[GreenMineralCount] = { 200, 300, 400 };
static float GreenMineralRarity[GreenMineralCount] = { 1.4, 2.3, 4.3 };
static int GreenMineralDelTime[GreenMineralCount] = { 2, 3, 4 }; //없애고 희귀도에 따라 해도 될 듯하다.

//하늘색 광물
static const char* SkyBlueMineralName[] = { "SKYBLUE광물-1", "SKYBLUE광물-2", "SKYBLUE광물-3" }; //포인터배열. 포인터를 담고 있는 배열.
static const int SkyBlueMineralCount = sizeof(SkyBlueMineralName) / sizeof(char*);

static unsigned int SkyBlueMineralPrice[SkyBlueMineralCount] = { 200, 300, 400 };
static float SkyBlueMineralRarity[SkyBlueMineralCount] = { 1.4, 2.3, 4.3 };
static int SkyBlueMineralDelTime[SkyBlueMineralCount] = { 2, 3, 4 }; //없애고 희귀도에 따라 해도 될 듯하다.


//빨강색 광물
static const char* RedMineralName[] = { "RED광물-1", "RED광물-2", "RED광물-3" }; //포인터배열. 포인터를 담고 있는 배열.
static const int RedMineralCount = sizeof(RedMineralName) / sizeof(char*);

static unsigned int RedMineralPrice[RedMineralCount] = { 200, 300, 400 };
static float RedMineralRarity[RedMineralCount] = { 1.4, 2.3, 4.3 };
static int RedMineralDelTime[RedMineralCount] = { 2, 3, 4 }; //없애고 희귀도에 따라 해도 될 듯하다.

//보라색 광물
static const char* VioletMineralName[] = { "VIOLET광물-1", "VIOLET광물-2", "VIOLET광물-3" }; //포인터배열. 포인터를 담고 있는 배열.
static const int VioletMineralCount = sizeof(VioletMineralName) / sizeof(char*);

static unsigned int VioletMineralPrice[VioletMineralCount] = { 200, 300, 400 };
static float VioletMineralRarity[VioletMineralCount] = { 1.4, 2.3, 4.3 };
static int VioletMineralDelTime[VioletMineralCount] = { 2, 3, 4 }; //없애고 희귀도에 따라 해도 될 듯하다.

//노랑색 광물
static const char* YellowMineralName[] = { "YELLOW광물-1", "YELLOW광물-2", "YELLOW광물-3" }; //포인터배열. 포인터를 담고 있는 배열.
static const int YellowMineralCount = sizeof(YellowMineralName) / sizeof(char*);

static unsigned int YellowMineralPrice[YellowMineralCount] = { 200, 300, 400 };
static float YellowMineralRarity[YellowMineralCount] = { 1.4, 2.3, 4.3 };
static int YellowMineralDelTime[YellowMineralCount] = { 2, 3, 4 }; //없애고 희귀도에 따라 해도 될 듯하다.