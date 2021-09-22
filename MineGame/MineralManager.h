#pragma once
#include "Mineral.h"
#include "gameGlobal.h"
class Mineral;
class MineralManager
{
private:
	int mineralIdx;
	Mineral* mineralManager[GAMEPLAY_GROUND_WIDTH * GAMEPLAY_GROUND_HEIGHT]; //������ ���� ������ �Ѿ�� ����
	//Mineral* mineralManager[GAMEPLAY_GROUND_WIDTH * GAMEPLAY_GROUND_HEIGHT];
	
	void LoadMineralInfo(); //������ ������ ���Ͽ��� �����´�.
public:
	
	
	
	MineralManager();
	~MineralManager();

	void AddMineral(const char* mineralName, int x, int y);
	void RandomMineralDel(const char* ground[][GAMEPLAY_GROUND_WIDTH], int item[][GAMEPLAY_GROUND_WIDTH]);
	char* MineralCheck(int x, int y);
};

void gotoXY(int x, int y);