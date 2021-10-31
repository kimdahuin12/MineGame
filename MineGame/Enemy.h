#pragma once
#include "gameGlobal.h"
#define PLAYERMOVE_LENGTH 100 

void gotoXY(int x, int y);
class Enemy
{
private:
	int x;
	int y;
	const char* ENEMY_SHAPE = "��";
	clock_t prevTime;
	clock_t currentTime;
	float lastTime;

	//bool curLocState;

	//�÷��̾� ������ ���� ����
	int playerMove[100][2];//player�� ��ġ�� ����. 
	int playerMoveIdx;//player�� ��ġ�� ������ idx
	int enemyMoveIdx; //enemy�� ���� player��ġ�� idx 
	bool saveLoc;
public:
	/*
		������ x, y ��ǥ
		�÷��̾��� 
	*/
	Enemy();
	void Update(int curPlayerX, int curPlayerY, const char* ground[], bool* mineBool);
	void Render(const char* ground[]);
	void playerMoveSave(int playerMoveX, int playerMoveY);
};

