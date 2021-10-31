//광산. 게임의 부분
#pragma once
#include "gameGlobal.h"
#include "mineralInfo.h"
#include "MineralManager.h" //광물을 추가할때 사용된다.
#include "Player.h"
#include "global.h"
#include "Enemy.h"

//광산 객체
class Mine
{
	/*
	1 ~ 6번 색. 순서대로
	DARK_BLUE
	DARK_GREEN
	DARK_SKYBLUE
	DARK_RED
	DARK_VIOLET
	DAKR_YELLOW
	*/
private:
	const char* ground[GAMEPLAY_GROUND_HEIGHT*GAMEPLAY_GROUND_WIDTH]; //광물을 수집하는 구역
	int item[GAMEPLAY_GROUND_HEIGHT][GAMEPLAY_GROUND_WIDTH]; //광물의 색을 저장하는 구역
	
	int id;
	char* mineName;										//광산 이름
	int produceMineralSec = 1;							//몇초사이마다 랜덤으로 광물이 나오게할지
	int deleteMineralSec = 1;							//몇초사이마다 랜덤으로 광물을 삭제할지
	float mineralPercentage[MINERAL_ITEM_COUNT+1];	//광물 색에 따른 확률 저장(인덱스 의 색) //MINERAL_ITEM_COUNT은 광물 색 갯수.

	//광물 관련
	MineralManager mineralManager; //광물 관리 생성
	char mineral[30] = "";
	int mineralX = 0;
	int mineralY = 0;

	//플레이어 정보
	Player* player;
	int playerX;
	int playerY;

	//몬스터
	Enemy enemy;

	//시간
	clock_t prevTime_render;
	clock_t currentTime_render;
	int renderTime = 3;
	int renderTimeCheck;
	clock_t prevTime_render_delete;
	clock_t renderTime_delete;
	int renderTimeCheck_delete;
	//맵 관련
	char fileName[10];
public:

	bool mineBool;//광산 

	Mine(Player* player, int id);
	~Mine();
	void SetMineInfo(char* name, int produceSec, int deleteSec, float* percentage);
	void MineInit();
	int KeyInputRelated();
	char* randomMineral(int mineralItem);
	void Update();
	void Render();

};

