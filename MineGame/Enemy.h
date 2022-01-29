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

	const char* ENEMY_SHAPE = "♠";
	clock_t prevTime;
	clock_t currentTime;
	float lastTime;

	//bool curLocState;

	//플레이어 움직임 저장 관련
	int playerMove[100][2];//player의 위치를 저장. 
	int playerMoveIdx;//player의 위치를 저장할 idx
	int enemyMoveIdx; //enemy가 따라갈 player위치의 idx 
	int moveX;
	int moveY;
	bool saveLoc;
	queue<Pos> _positions;

	void BFS(Pos start, Pos dest, const char* ground[GAMEPLAY_GROUND_HEIGHT][GAMEPLAY_GROUND_WIDTH]);
public:
	/*
		몬스터의 x, y 좌표
		플레이어의 
	*/
	Enemy();
	void Update(int curPlayerX, int curPlayerY, const char* ground[GAMEPLAY_GROUND_HEIGHT][GAMEPLAY_GROUND_WIDTH], bool* mineBool);
	void Render(const char* ground[GAMEPLAY_GROUND_HEIGHT][GAMEPLAY_GROUND_WIDTH]);
	void playerMoveSave(int playerMoveX, int playerMoveY);
	
};

