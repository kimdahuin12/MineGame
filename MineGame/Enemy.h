#pragma once
#include "gameGlobal.h"
#include <queue>
#include <algorithm>
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

	queue<Pos> BFS(Pos start, Pos dest, const char* ground[]);
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

class Pos {
public:
	int _x;
	int _y;
	Pos() {}
	Pos(int x, int y) :_x(x), _y(y) {}
	
};