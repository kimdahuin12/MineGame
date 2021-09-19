#pragma once
#include "Mineral.h"
class Mineral;
class MineralManager
{
private:
	static int mineralIdx;
	Mineral* mineralManager[35 * 35]; //������ ���� ������ �Ѿ�� ����
	//Mineral* mineralManager[GAMEPLAY_GROUND_WIDTH * GAMEPLAY_GROUND_HEIGHT];
	
	void LoadMineralInfo(); //������ ������ ���Ͽ��� �����´�.
public:
	MineralManager();
	~MineralManager();

	void AddMineral(const char* mineralName, int x, int y);
	char* MineralCheck(int x, int y);
};

