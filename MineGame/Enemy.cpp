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

#pragma region 플레이어를 따라가는 적 테스트해봄

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
#pragma endregion
	
////enemy가 움직일 좌표
//	int tempX = playerMove[enemyMoveIdx][0];
//	int tempY = playerMove[enemyMoveIdx][1];

	//땅에 enemy 위치시키기
	ground[y * GAMEPLAY_GROUND_WIDTH + x] = ENEMY_SHAPE;

	currentTime = clock(); //지금 시각
	lastTime = (currentTime - prevTime) / CLOCKS_PER_SEC;
	if (80 <= currentTime - prevTime) {
		prevTime = clock();

		BFS( Pos(curPlayerX, curPlayerY), Pos(x, y), ground);//플레이어한테로 가도록 _positions에 넣어줌

		if (!_positions.empty()) {
			moveX = _positions.front()._x;
			moveY = _positions.front()._y;
			_positions.pop();
		}
		else {
			return;
		}

		//현재 위치 비우기
		ground[y * GAMEPLAY_GROUND_WIDTH + x] = ROAD;
		gotoXY(x * 2, COORDINATE_TOP + y);
		cout << ground[y * GAMEPLAY_GROUND_WIDTH + x];

		if (ground[moveX * GAMEPLAY_GROUND_WIDTH + moveY] == PLAYER_CHARACTER) {
			//enemy가 가려는 곳에 플레이어가 있다면 enemy가 플레이어를 먹음
			*mineBool = false;
		}

		//저장된 위치 enemy 위치로 저장
		x = moveX;
		y = moveY;

		ground[y * GAMEPLAY_GROUND_WIDTH + x] = ENEMY_SHAPE;

		prevTime = clock();

		
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

void Enemy::BFS(Pos start, Pos dest, const char* ground[])
{
	//start는 플레이어의 위치, dest는 적의 위치로 넣어줘야 적의 위치가 나옴

	int deltaY[4] = { -1, 0, 1, 0 };
	int deltaX[4] = { 0, -1, 0, 1 };
	bool found[GAMEPLAY_GROUND_HEIGHT * GAMEPLAY_GROUND_WIDTH] = {false, };
	int parentX[GAMEPLAY_GROUND_HEIGHT*GAMEPLAY_GROUND_WIDTH] = {0,};
	int parentY[GAMEPLAY_GROUND_HEIGHT * GAMEPLAY_GROUND_WIDTH] = {0,};
	queue<Pos> q;

	q.push(Pos(start._x, start._y));
	found[y * GAMEPLAY_GROUND_WIDTH + x] = true;

	while (!q.empty()) 
	{
		//위, 왼쪽, 아래, 오른쪽
		Pos now = q.front();
		int nowX = now._x;
		int nowY = now._y;
		q.pop();
		int nextX, nextY;
		found[nowY * GAMEPLAY_GROUND_WIDTH + nowX] = true;
		parentX[nowY * GAMEPLAY_GROUND_WIDTH + nowX] = nowX;
		parentY[nowY * GAMEPLAY_GROUND_WIDTH + nowX] = nowY;
		for (int i = 0; i < 4; i++)
		{
			nextX = nowX+deltaX[i];
			nextY = nowY+deltaY[i];
			
			if (nextX < 0 || nextX >= GAMEPLAY_GROUND_WIDTH || nextY < 0 || nextY >= GAMEPLAY_GROUND_HEIGHT) { continue; }
			if (ground[nextY * GAMEPLAY_GROUND_WIDTH + nextX] != ROAD
				&& ground[nextY * GAMEPLAY_GROUND_WIDTH + nextX] != PLAYER_CHARACTER) { continue; }
			if (found[nextY * GAMEPLAY_GROUND_WIDTH + nextX]) { continue; }
			found[nextY * GAMEPLAY_GROUND_WIDTH + nextX] = true;
			parentX[nextY * GAMEPLAY_GROUND_WIDTH + nextX] = nowX;
			parentY[nextY * GAMEPLAY_GROUND_WIDTH + nextX] = nowY;
			q.push(Pos(nextX, nextY));
		}
	}

	int x = dest._x;
	int y = dest._y;
	//도착지점에서 역추적
	//하나만 넣어봄
	if (parentX[y * GAMEPLAY_GROUND_WIDTH + x] != x || parentY[y * GAMEPLAY_GROUND_WIDTH + x] != y) {
		_positions.push(Pos(x, y));
		x = parentX[y * GAMEPLAY_GROUND_WIDTH + x];
		y = parentY[y * GAMEPLAY_GROUND_WIDTH + x];
	}
	_positions.push(Pos(x, y));
}
