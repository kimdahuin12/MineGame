#include "Enemy.h"

Enemy::Enemy() {
	x = 5;
	y = 5;
	playerMoveIdx = 20;
	enemyMoveIdx = 0;
	prevTime = clock();//이전시각

	//처음에 플레이어쪽으로 가도록 설정
	for (int i = 0; i < playerMoveIdx; i++) {
		playerMove[i][0] = 6+i;
		playerMove[i][1] = 5;
	}

	//비워놓기(-1)
	for (int i = playerMoveIdx; i < PLAYERMOVE_LENGTH; i++) {
		playerMove[i][0] = -1;
		playerMove[i][1] = -1;
	}

}

void Enemy::Update(int curPlayerX, int curPlayerY, const char* ground[], bool* mineBool) {
	//플레이어의 위치를 따라감
	
	saveLoc = false;//처음에는 false

//enemy가 움직을 좌표들을 플레이어의 좌표에 따라 저장해둔다
//x좌표를 먼저 움직임.
//enemy의 좌표와 player의 좌표가 같지 않을때만 player 좌표를 저장
	//if (!curLocState) {
//		if (curPlayerX != x) {
//			if (!saveLoc && curPlayerX > x) { //몬스터의 x좌표가 현재 플레이어의 x좌표보다 작을때
//				if ((ground[y * GAMEPLAY_GROUND_WIDTH + (x + 1)] == ROAD) || (ground[y * GAMEPLAY_GROUND_WIDTH + (x + 1)] == PLAYER_CHARACTER))
//				{
//					//저장할 위치가 갈 수 있는 길이면 저장
//					playerMove[playerMoveIdx][0] = x + 1; playerMove[playerMoveIdx][1] = y;
//					saveLoc = true;
//				}
//			}
//
//			if (!saveLoc && curPlayerX < x) { //몬스터의 x좌표가 현재 플레이어의 x좌표보다 클때
//				if ((ground[y * GAMEPLAY_GROUND_WIDTH + (x - 1)] == ROAD) || (ground[y * GAMEPLAY_GROUND_WIDTH + (x - 1)] == PLAYER_CHARACTER))
//				{
//					//저장할 위치가 갈 수 있는 길이면 저장
//					playerMove[playerMoveIdx][0] = x - 1; playerMove[playerMoveIdx][1] = y;
//					saveLoc = true;
//				}
//			}
//		}
//		else if (curPlayerY != y) {
//			if (!saveLoc && curPlayerY > y) { //몬스터의 y좌표가 현재 플레이어의 y좌표보다 작을때
//				if ((ground[(y + 1) * GAMEPLAY_GROUND_WIDTH + x] == ROAD) || (ground[(y + 1) * GAMEPLAY_GROUND_WIDTH + x] == PLAYER_CHARACTER))
//				{
//					//저장할 위치가 갈 수 있는 길이면 저장
//					playerMove[playerMoveIdx][0] = x; playerMove[playerMoveIdx][1] = y + 1;
//					saveLoc = true;
//				}
//			}
//			if (!saveLoc && curPlayerY < y) { //몬스터의 y좌표가 현재 플레이어의 y좌표보다때 클때
//				if ((ground[(y - 1) * GAMEPLAY_GROUND_WIDTH + x] == ROAD) || (ground[(y - 1) * GAMEPLAY_GROUND_WIDTH + x] == PLAYER_CHARACTER))
//				{
//					//저장할 위치가 갈 수 있는 길이면 저장
//					playerMove[playerMoveIdx][0] = x; playerMove[playerMoveIdx][1] = y - 1;
//					saveLoc = true;
//				}
//			}
//		}
//	//}
//	//else {
//	//	int tempX = playerMove[playerMoveIdx][0];
//	//	int tempY = playerMove[playerMoveIdx][1];
//
//	//	//가려는 곳이 못가는 곳이면
//	//	if ((ground[tempY * GAMEPLAY_GROUND_WIDTH + tempX] != ROAD) && (ground[tempY * GAMEPLAY_GROUND_WIDTH + tempX] != PLAYER_CHARACTER)) {
//	//		//갈 수 있는 곳으로 가기
//	//		if ((ground[y * GAMEPLAY_GROUND_WIDTH + (x + 1)] == ROAD) || (ground[y * GAMEPLAY_GROUND_WIDTH + (x + 1)] == PLAYER_CHARACTER)) {
//	//			playerMove[playerMoveIdx][0] = x + 1; playerMove[playerMoveIdx][1] = y; saveLoc = true;
//	//		}
//	//		else if ((ground[(y + 1) * GAMEPLAY_GROUND_WIDTH + x] == ROAD) || (ground[(y + 1) * GAMEPLAY_GROUND_WIDTH + x] == PLAYER_CHARACTER)) {
//	//			playerMove[playerMoveIdx][0] = x; playerMove[playerMoveIdx][1] = y + 1; saveLoc = true;
//	//		}
//	//		else if ((ground[y * GAMEPLAY_GROUND_WIDTH + (x - 1)] == ROAD) || (ground[y * GAMEPLAY_GROUND_WIDTH + (x - 1)] == PLAYER_CHARACTER)) {
//	//			playerMove[playerMoveIdx][0] = x - 1; playerMove[playerMoveIdx][1] = y; saveLoc = true;
//	//		}
//	//		else if ((ground[(y - 1) * GAMEPLAY_GROUND_WIDTH + x] == ROAD) || (ground[(y - 1) * GAMEPLAY_GROUND_WIDTH + x] == PLAYER_CHARACTER)) {
//	//			playerMove[playerMoveIdx][0] = x; playerMove[playerMoveIdx][1] = y - 1; saveLoc = true;
//	//		}
//
//	//	}
//	//}
// ////플레이어의 좌표와 같다면 플레이어의 현재 좌표를 저장
//	//if ( !saveLoc && curPlayerX == x )
//	//{
//	//	playerMove[playerMoveIdx][0] = curPlayerX; playerMove[playerMoveIdx][1] = y;
//	//	saveLoc = true;
//	//}
//	//if (!saveLoc && curPlayerY == y)
//	//{
//	//	playerMove[playerMoveIdx][0] = x; playerMove[playerMoveIdx][1] = curPlayerY;
//	//	saveLoc = true;
//	//}
//
//	//
//	
//
//
//
////enemy(몬스터)가 움직일 위치를 저장했다면 인덱스를 증가
//	if (saveLoc) { 
//		playerMoveIdx++;
//		if (playerMoveIdx == PLAYERMOVE_LENGTH) {
//			playerMoveIdx = 0;
//		}
//	}

	//enemy가 움직일 좌표
	int tempX = playerMove[enemyMoveIdx][0];
	int tempY = playerMove[enemyMoveIdx][1];

	//땅에 enemy 위치시키기
	ground[y * GAMEPLAY_GROUND_WIDTH + x] = ENEMY_SHAPE;

	currentTime = clock(); //지금 시각
	lastTime = (currentTime - prevTime) / CLOCKS_PER_SEC;
	if (80 <= currentTime - prevTime) {

		//큐
		if (tempX != -1 || tempY != -1) { //playerMove[enemyMoveIdx]배열 중 하나라도 -1이 저장돼있다면(좌표가 저장이 안돼있다는뜻)
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