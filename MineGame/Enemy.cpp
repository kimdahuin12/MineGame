#include "Enemy.h"

Enemy::Enemy() {
	x = 5;
	y = 5;
	playerMoveIdx = 20;
	enemyMoveIdx = 0;
	prevTime = clock();//�����ð�

	

	//ó���� �÷��̾������� ������ ����
	for (int i = 0; i < playerMoveIdx; i++) {
		playerMove[i][0] = 6+i;
		playerMove[i][1] = 5;
	}

	//�������(-1)
	for (int i = playerMoveIdx; i < PLAYERMOVE_LENGTH; i++) {
		playerMove[i][0] = -1;
		playerMove[i][1] = -1;
	}

}

void Enemy::Update(int curPlayerX, int curPlayerY, const char* ground[], bool* mineBool) {

	//�÷��̾��� ��ġ�� ����
	
	saveLoc = false;//ó������ false

#pragma region �÷��̾ ���󰡴� �� �׽�Ʈ�غ�

//enemy�� ������ ��ǥ���� �÷��̾��� ��ǥ�� ���� �����صд�
//x��ǥ�� ���� ������.
//enemy�� ��ǥ�� player�� ��ǥ�� ���� �������� player ��ǥ�� ����
	//if (!curLocState) {
//		if (curPlayerX != x) {
//			if (!saveLoc && curPlayerX > x) { //������ x��ǥ�� ���� �÷��̾��� x��ǥ���� ������
//				if ((ground[y * GAMEPLAY_GROUND_WIDTH + (x + 1)] == ROAD) || (ground[y * GAMEPLAY_GROUND_WIDTH + (x + 1)] == PLAYER_CHARACTER))
//				{
//					//������ ��ġ�� �� �� �ִ� ���̸� ����
//					playerMove[playerMoveIdx][0] = x + 1; playerMove[playerMoveIdx][1] = y;
//					saveLoc = true;
//				}
//			}
//
//			if (!saveLoc && curPlayerX < x) { //������ x��ǥ�� ���� �÷��̾��� x��ǥ���� Ŭ��
//				if ((ground[y * GAMEPLAY_GROUND_WIDTH + (x - 1)] == ROAD) || (ground[y * GAMEPLAY_GROUND_WIDTH + (x - 1)] == PLAYER_CHARACTER))
//				{
//					//������ ��ġ�� �� �� �ִ� ���̸� ����
//					playerMove[playerMoveIdx][0] = x - 1; playerMove[playerMoveIdx][1] = y;
//					saveLoc = true;
//				}
//			}
//		}
//		else if (curPlayerY != y) {
//			if (!saveLoc && curPlayerY > y) { //������ y��ǥ�� ���� �÷��̾��� y��ǥ���� ������
//				if ((ground[(y + 1) * GAMEPLAY_GROUND_WIDTH + x] == ROAD) || (ground[(y + 1) * GAMEPLAY_GROUND_WIDTH + x] == PLAYER_CHARACTER))
//				{
//					//������ ��ġ�� �� �� �ִ� ���̸� ����
//					playerMove[playerMoveIdx][0] = x; playerMove[playerMoveIdx][1] = y + 1;
//					saveLoc = true;
//				}
//			}
//			if (!saveLoc && curPlayerY < y) { //������ y��ǥ�� ���� �÷��̾��� y��ǥ���ٶ� Ŭ��
//				if ((ground[(y - 1) * GAMEPLAY_GROUND_WIDTH + x] == ROAD) || (ground[(y - 1) * GAMEPLAY_GROUND_WIDTH + x] == PLAYER_CHARACTER))
//				{
//					//������ ��ġ�� �� �� �ִ� ���̸� ����
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
//	//	//������ ���� ������ ���̸�
//	//	if ((ground[tempY * GAMEPLAY_GROUND_WIDTH + tempX] != ROAD) && (ground[tempY * GAMEPLAY_GROUND_WIDTH + tempX] != PLAYER_CHARACTER)) {
//	//		//�� �� �ִ� ������ ����
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
// ////�÷��̾��� ��ǥ�� ���ٸ� �÷��̾��� ���� ��ǥ�� ����
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
////enemy(����)�� ������ ��ġ�� �����ߴٸ� �ε����� ����
//	if (saveLoc) { 
//		playerMoveIdx++;
//		if (playerMoveIdx == PLAYERMOVE_LENGTH) {
//			playerMoveIdx = 0;
//		}
//	}
#pragma endregion
	
////enemy�� ������ ��ǥ
//	int tempX = playerMove[enemyMoveIdx][0];
//	int tempY = playerMove[enemyMoveIdx][1];

	//���� enemy ��ġ��Ű��
	ground[y * GAMEPLAY_GROUND_WIDTH + x] = ENEMY_SHAPE;

	currentTime = clock(); //���� �ð�
	lastTime = (currentTime - prevTime) / CLOCKS_PER_SEC;
	if (80 <= currentTime - prevTime) {
		prevTime = clock();

		BFS( Pos(curPlayerX, curPlayerY), Pos(x, y), ground);//�÷��̾����׷� ������ _positions�� �־���

		if (!_positions.empty()) {
			moveX = _positions.front()._x;
			moveY = _positions.front()._y;
			_positions.pop();
		}
		else {
			return;
		}

		//���� ��ġ ����
		ground[y * GAMEPLAY_GROUND_WIDTH + x] = ROAD;
		gotoXY(x * 2, COORDINATE_TOP + y);
		cout << ground[y * GAMEPLAY_GROUND_WIDTH + x];

		if (ground[moveX * GAMEPLAY_GROUND_WIDTH + moveY] == PLAYER_CHARACTER) {
			//enemy�� ������ ���� �÷��̾ �ִٸ� enemy�� �÷��̾ ����
			*mineBool = false;
		}

		//����� ��ġ enemy ��ġ�� ����
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
	//0������ x, 1������ y��ǥ�� �����صд�.
	playerMove[playerMoveIdx][0] = playerMoveX;
	playerMove[playerMoveIdx][1] = playerMoveY;
	playerMoveIdx++;
	if (playerMoveIdx == PLAYERMOVE_LENGTH) {
		playerMoveIdx = 0;
	}
}

void Enemy::BFS(Pos start, Pos dest, const char* ground[])
{
	//start�� �÷��̾��� ��ġ, dest�� ���� ��ġ�� �־���� ���� ��ġ�� ����

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
		//��, ����, �Ʒ�, ������
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
	//������������ ������
	//�ϳ��� �־
	if (parentX[y * GAMEPLAY_GROUND_WIDTH + x] != x || parentY[y * GAMEPLAY_GROUND_WIDTH + x] != y) {
		_positions.push(Pos(x, y));
		x = parentX[y * GAMEPLAY_GROUND_WIDTH + x];
		y = parentY[y * GAMEPLAY_GROUND_WIDTH + x];
	}
	_positions.push(Pos(x, y));
}
