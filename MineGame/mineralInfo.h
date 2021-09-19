#pragma once

#define MINERAL_ITEM_COUNT 6 //광물 색 종류 갯수

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
const char* BlueMineralName[] = { "BLUE광물-1", "BLUE광물-2", "BLUE광물-3"}; //포인터배열. 포인터를 담고 있는 배열.
const int BlueMineralCount = sizeof(BlueMineralName) / sizeof(char*);

unsigned int BlueMineralPrice[BlueMineralCount] = { 200, 300, 400};
float BlueMineralRarity[BlueMineralCount] = { 1.4, 2.3, 4.3};
int BlueMineralDelTime[BlueMineralCount] = { 2, 3, 4}; //없애고 희귀도에 따라 해도 될 듯하다.

//초록색 광물
const char* GreenMineralName[] = { "GREEN광물-1", "GREEN광물-2", "GREEN광물-3" }; //포인터배열. 포인터를 담고 있는 배열.
const int GreenMineralCount = sizeof(GreenMineralName) / sizeof(char*);

unsigned int GreenMineralPrice[GreenMineralCount] = { 200, 300, 400 };
float GreenMineralRarity[GreenMineralCount] = { 1.4, 2.3, 4.3 };
int GreenMineralDelTime[GreenMineralCount] = { 2, 3, 4 }; //없애고 희귀도에 따라 해도 될 듯하다.

//하늘색 광물
const char* SkyBlueMineralName[] = { "SKYBLUE광물-1", "SKYBLUE광물-2", "SKYBLUE광물-3" }; //포인터배열. 포인터를 담고 있는 배열.
const int SkyBlueMineralCount = sizeof(SkyBlueMineralName) / sizeof(char*);

unsigned int SkyBlueMineralPrice[SkyBlueMineralCount] = { 200, 300, 400 };
float SkyBlueMineralRarity[SkyBlueMineralCount] = { 1.4, 2.3, 4.3 };
int SkyBlueMineralDelTime[SkyBlueMineralCount] = { 2, 3, 4 }; //없애고 희귀도에 따라 해도 될 듯하다.


//빨강색 광물
const char* RedMineralName[] = { "RED광물-1", "RED광물-2", "RED광물-3" }; //포인터배열. 포인터를 담고 있는 배열.
const int RedMineralCount = sizeof(RedMineralName) / sizeof(char*);

unsigned int RedMineralPrice[RedMineralCount] = { 200, 300, 400 };
float RedMineralRarity[RedMineralCount] = { 1.4, 2.3, 4.3 };
int RedMineralDelTime[RedMineralCount] = { 2, 3, 4 }; //없애고 희귀도에 따라 해도 될 듯하다.

//보라색 광물
const char* VioletMineralName[] = { "VIOLET광물-1", "VIOLET광물-2", "VIOLET광물-3" }; //포인터배열. 포인터를 담고 있는 배열.
const int VioletMineralCount = sizeof(VioletMineralName) / sizeof(char*);

unsigned int VioletMineralPrice[VioletMineralCount] = { 200, 300, 400 };
float VioletMineralRarity[VioletMineralCount] = { 1.4, 2.3, 4.3 };
int VioletMineralDelTime[VioletMineralCount] = { 2, 3, 4 }; //없애고 희귀도에 따라 해도 될 듯하다.

//노랑색 광물
const char* YellowMineralName[] = { "YELLOW광물-1", "YELLOW광물-2", "YELLOW광물-3" }; //포인터배열. 포인터를 담고 있는 배열.
const int YellowMineralCount = sizeof(YellowMineralName) / sizeof(char*);

unsigned int YellowMineralPrice[YellowMineralCount] = { 200, 300, 400 };
float YellowMineralRarity[YellowMineralCount] = { 1.4, 2.3, 4.3 };
int YellowMineralDelTime[YellowMineralCount] = { 2, 3, 4 }; //없애고 희귀도에 따라 해도 될 듯하다.