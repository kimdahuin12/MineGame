#pragma once
#include "Mineral.h"
class Mineral;
class MineralManager
{
private:
	static int mineralIdx;
	Mineral* mineralManager[35 * 35]; //광물은 게임 구역을 넘어가지 않음
	//Mineral* mineralManager[GAMEPLAY_GROUND_WIDTH * GAMEPLAY_GROUND_HEIGHT];
	
	void LoadMineralInfo(); //광물의 정보를 파일에서 가져온다.
public:
	MineralManager();
	~MineralManager();

	void AddMineral(const char* mineralName, int x, int y);
	char* MineralCheck(int x, int y);
};

