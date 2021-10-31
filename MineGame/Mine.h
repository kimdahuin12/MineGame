//����. ������ �κ�
#pragma once
#include "gameGlobal.h"
#include "mineralInfo.h"
#include "MineralManager.h" //������ �߰��Ҷ� ���ȴ�.
#include "Player.h"
#include "global.h"
#include "Enemy.h"

//���� ��ü
class Mine
{
	/*
	1 ~ 6�� ��. �������
	DARK_BLUE
	DARK_GREEN
	DARK_SKYBLUE
	DARK_RED
	DARK_VIOLET
	DAKR_YELLOW
	*/
private:
	const char* ground[GAMEPLAY_GROUND_HEIGHT*GAMEPLAY_GROUND_WIDTH]; //������ �����ϴ� ����
	int item[GAMEPLAY_GROUND_HEIGHT][GAMEPLAY_GROUND_WIDTH]; //������ ���� �����ϴ� ����
	
	int id;
	char* mineName;										//���� �̸�
	int produceMineralSec = 1;							//���ʻ��̸��� �������� ������ ����������
	int deleteMineralSec = 1;							//���ʻ��̸��� �������� ������ ��������
	float mineralPercentage[MINERAL_ITEM_COUNT+1];	//���� ���� ���� Ȯ�� ����(�ε��� �� ��) //MINERAL_ITEM_COUNT�� ���� �� ����.

	//���� ����
	MineralManager mineralManager; //���� ���� ����
	char mineral[30] = "";
	int mineralX = 0;
	int mineralY = 0;

	//�÷��̾� ����
	Player* player;
	int playerX;
	int playerY;

	//����
	Enemy enemy;

	//�ð�
	clock_t prevTime_render;
	clock_t currentTime_render;
	int renderTime = 3;
	int renderTimeCheck;
	clock_t prevTime_render_delete;
	clock_t renderTime_delete;
	int renderTimeCheck_delete;
	//�� ����
	char fileName[10];
public:

	bool mineBool;//���� 

	Mine(Player* player, int id);
	~Mine();
	void SetMineInfo(char* name, int produceSec, int deleteSec, float* percentage);
	void MineInit();
	int KeyInputRelated();
	char* randomMineral(int mineralItem);
	void Update();
	void Render();

};

