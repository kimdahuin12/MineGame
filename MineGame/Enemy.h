#pragma once
#include "gameGlobal.h"
#include <queue>
#include <vector>
#define PLAYERMOVE_LENGTH 100 

void gotoXY(int x, int y);
class Pos {
public:
	int _x;
	int _y;
	Pos() { _x = 0; _y = 0; }
	Pos(int x, int y) :_x(x), _y(y) {}
	~Pos() {}
	void setPos(int x, int y);
};
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
	int moveX;
	int moveY;
	bool saveLoc;
	queue<Pos> _positions;

	void BFS(Pos start, Pos dest, const char* ground[GAMEPLAY_GROUND_HEIGHT][GAMEPLAY_GROUND_WIDTH]);
public:
	/*
		������ x, y ��ǥ
		�÷��̾��� 
	*/
	Enemy();
	void Update(int curPlayerX, int curPlayerY, const char* ground[GAMEPLAY_GROUND_HEIGHT][GAMEPLAY_GROUND_WIDTH], bool* mineBool);
	void Render(const char* ground[GAMEPLAY_GROUND_HEIGHT][GAMEPLAY_GROUND_WIDTH]);
	void playerMoveSave(int playerMoveX, int playerMoveY);
	
};

