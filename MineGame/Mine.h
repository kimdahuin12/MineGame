#pragma once
#include "gameGlobal.h"
#include "mineralInfo.h"
#include "MineralManager.h" //������ �߰��Ҷ� ���ȴ�.
#include "Player.h"

void gotoXY(int x, int y);

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
	const char* ground[GAMEPLAY_GROUND_HEIGHT][GAMEPLAY_GROUND_WIDTH]; //������ �����ϴ� ����
	int item[GAMEPLAY_GROUND_HEIGHT][GAMEPLAY_GROUND_WIDTH]; //������ ���� �����ϴ� ����

	char* mineName;									//���� �̸�
	int produceMineralSec = 1;							//���ʻ��̸��� �������� ������ ����������
	int deleteMineralSec = 1;							//���ʻ��̸��� �������� ������ ��������
	//MINERAL_ITEM_COUNT�� ���� �� ����.
	float mineralPercentage[MINERAL_ITEM_COUNT+1];	//���� ���� ���� Ȯ�� ����(�ε��� �� ��)
	
	//���� ����
	MineralManager mineralManager;
	char mineral[30] = "";
	int mineralX = 0;
	int mineralY = 0;

	//�÷��̾� ����
	Player player;
	int playerX;
	int playerY;

	//�ð�
	clock_t prevTime_render;
	clock_t currentTime_render;
	int renderTime = 3;
	int renderTimeCheck;
	clock_t prevTime_render_delete;
	int renderTime_delete = 10;
	int renderTimeCheck_delete;
public:
	Mine(const char* mineName, Player &player);
	~Mine();
	void MineInit();
	int KeyInputRelated();
	char* randomMineral(int mineralItem);
	void Update();
	void Render();

};

