#pragma once
//게임에서 미네랄을 관리하기 위한.. Mineral 클래스(광물)을 관리합니다.

#include "Mineral.h"
#include "gameGlobal.h"
class Mineral;
class MineralManager
{
private:
	int mineralIdx;
	Mineral* mineralManager[GAMEPLAY_GROUND_WIDTH * GAMEPLAY_GROUND_HEIGHT]; //광물은 게임 구역을 넘어가지 않음
	//Mineral* mineralManager[GAMEPLAY_GROUND_WIDTH * GAMEPLAY_GROUND_HEIGHT];
	
	void LoadMineralInfo(); //광물의 정보를 파일에서 가져온다.
public:
	MineralManager();
	~MineralManager();

	void AddMineral(const char* mineralName, int x, int y);
	void RandomMineralDel(const char* ground[], int item[][GAMEPLAY_GROUND_WIDTH]);
	char* MineralCheck(int x, int y);
};

void gotoXY(int x, int y);