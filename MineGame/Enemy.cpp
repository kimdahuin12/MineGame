#include "Enemy.h"

Enemy::Enemy() {
	x = 5;
	y = 5;
	playerMoveIdx = 20; //0, 1번방에는 이미 저장해놨기 때문에 2번방부터 플레이어의 위치를 저장해둔다.
	enemyMoveIdx = 0;
	prevTime = clock();//이전시각

	//처음에 플레이어쪽으로 가도록 설정
	for (int i = 0; i < playerMoveIdx; i++) {
		playerMove[i][0] = 6+i;
		playerMove[i][1] = 5;
	}

	//다른 부분은 비워놓기(-1)
	for (int i = playerMoveIdx; i < PLAYERMOVE_LENGTH; i++) {
		playerMove[i][0] = -1;
		playerMove[i][1] = -1;
	}

}

void Enemy::Update(const char* ground[], bool* mineBool) {
	//플레이어의 위치를 따라감
	
	//땅에 enemy 위치시키기
	ground[y * GAMEPLAY_GROUND_WIDTH + x] = ENEMY_SHAPE;

	currentTime = clock(); //지금 시각
	lastTime = (currentTime - prevTime) / CLOCKS_PER_SEC;
	if (80 <= currentTime - prevTime) {
		//0.000001초마다 움직임.

		//큐
		if (playerMove[enemyMoveIdx][0] != -1 || playerMove[enemyMoveIdx][1] != -1) { //playerMove[enemyMoveIdx]배열 중 하나라도 -1이 저장돼있다면(좌표가 저장이 안돼있다는뜻)
			
			//현재 위치 비우기
			ground[y * GAMEPLAY_GROUND_WIDTH + x] = ROAD;
			gotoXY(x * 2, COORDINATE_TOP + y);
			cout << ground[y * GAMEPLAY_GROUND_WIDTH + x];

			if (ground[playerMove[enemyMoveIdx][1] * GAMEPLAY_GROUND_WIDTH + playerMove[enemyMoveIdx][0]] == PLAYER_CHARACTER) {
				//enemy가 가려는 곳에 플레이어가 있다면 enemy가 플레이어를 먹음
				*mineBool = false;
			}

			//저장된 위치 enemy 위치로 저장
			x = playerMove[enemyMoveIdx][0];
			y = playerMove[enemyMoveIdx][1];
			//저장돼있던 배열idx부분 비우기
			playerMove[enemyMoveIdx][0] = -1;
			playerMove[enemyMoveIdx][1] = -1;
			enemyMoveIdx++;
			if (enemyMoveIdx == PLAYERMOVE_LENGTH) { //맨끝까지 가면 다시 0번째방부터 저장이 돼있음
				enemyMoveIdx = 0;
			}

			//enemy 위치 저장
			ground[y * GAMEPLAY_GROUND_WIDTH + x] = ENEMY_SHAPE;

			prevTime = clock();
		}
	}

}

void Enemy::Render(const char* ground[]) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	gotoXY(x * 2, COORDINATE_TOP + y);
	cout << ground[y * GAMEPLAY_GROUND_WIDTH + x];

}

void Enemy::playerMoveSave(int playerMoveX, int playerMoveY) 
{
	//0번방은 x, 1번방은 y좌표를 저장해둔다.
	playerMove[playerMoveIdx][0] = playerMoveX;
	playerMove[playerMoveIdx][1] = playerMoveY;
	playerMoveIdx++;
	if (playerMoveIdx == PLAYERMOVE_LENGTH) {
		playerMoveIdx = 0;
	}
}