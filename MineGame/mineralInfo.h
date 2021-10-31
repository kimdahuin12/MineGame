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

//static const char* MineralName[] = {
//	"▲ 스캐폴라이트", "◈ 스미스소나이트", "◎ 시트린",
//	"◆ 플루라이트", "● 아메지스트", "▤ 래피도라이트",
//	"▣ 스피넬", "◐ 루비", "□ 가넷",
//	"＠ 터키석", "＃ 페리도트", "▶ 에메랄드",
//	"◀ 아쿠아마린", "■ 아주라이트", "¤ 사파이어",
//	"▽ 다이아몬드", "○ 그란디디어라이트", "◇ 배니토아이트",
//};
//
//static const int MineralColor[] = {
//	DARK_YELLOW, DARK_YELLOW, DARK_YELLOW,
//	VIOLET, VIOLET, VIOLET,
//	DARK_RED, DARK_RED, DARK_RED,
//	GREEN, GREEN, GREEN,
//	BLUE, BLUE, BLUE,
//	SKYBLUE, SKYBLUE, SKYBLUE
//};
//



//파란색 광물
static const char* BlueMineralName[] = { "◀ 아쿠아마린", "■ 아주라이트", "¤ 사파이어"}; //포인터배열. 포인터를 담고 있는 배열.
static const int BlueMineralCount = sizeof(BlueMineralName) / sizeof(char*);

//초록색 광물
static const char* GreenMineralName[] = { "＠ 터키석", "＃ 페리도트", "▶ 에메랄드" }; //포인터배열. 포인터를 담고 있는 배열.
static const int GreenMineralCount = sizeof(GreenMineralName) / sizeof(char*);

//하늘색 광물
static const char* SkyBlueMineralName[] = { "▽ 다이아몬드", "○ 그란디디어라이트", "◇ 배니토아이트" }; //포인터배열. 포인터를 담고 있는 배열.
static const int SkyBlueMineralCount = sizeof(SkyBlueMineralName) / sizeof(char*);

//빨강색 광물
static const char* RedMineralName[] = { "▣ 스피넬", "◐ 루비", "□ 가넷" }; //포인터배열. 포인터를 담고 있는 배열.
static const int RedMineralCount = sizeof(RedMineralName) / sizeof(char*);

//보라색 광물
static const char* VioletMineralName[] = { "◆ 플루라이트", "● 아메지스트", "▤ 래피도라이트" }; //포인터배열. 포인터를 담고 있는 배열.
static const int VioletMineralCount = sizeof(VioletMineralName) / sizeof(char*);

//노랑색 광물
static const char* YellowMineralName[] = { "▲ 스캐폴라이트", "◈ 스미스소나이트", "◎ 시트린" }; //포인터배열. 포인터를 담고 있는 배열.
static const int YellowMineralCount = sizeof(YellowMineralName) / sizeof(char*);