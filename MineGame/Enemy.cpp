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

	//enemy�� ������ ��ǥ
	int tempX = playerMove[enemyMoveIdx][0];
	int tempY = playerMove[enemyMoveIdx][1];

	//���� enemy ��ġ��Ű��
	ground[y * GAMEPLAY_GROUND_WIDTH + x] = ENEMY_SHAPE;

	currentTime = clock(); //���� �ð�
	lastTime = (currentTime - prevTime) / CLOCKS_PER_SEC;
	if (80 <= currentTime - prevTime) {

		//ť
		if (tempX != -1 || tempY != -1) { //playerMove[enemyMoveIdx]�迭 �� �ϳ��� -1�� ������ִٸ�(��ǥ�� ������ �ȵ��ִٴ¶�)
			//���� ��ġ ����
			ground[y * GAMEPLAY_GROUND_WIDTH + x] = ROAD;
			gotoXY(x * 2, COORDINATE_TOP + y);
			cout << ground[y * GAMEPLAY_GROUND_WIDTH + x];

			if (ground[playerMove[enemyMoveIdx][1] * GAMEPLAY_GROUND_WIDTH + playerMove[enemyMoveIdx][0]] == PLAYER_CHARACTER) {
				//enemy�� ������ ���� �÷��̾ �ִٸ� enemy�� �÷��̾ ����
				*mineBool = false;
			}

			//����� ��ġ enemy ��ġ�� ����
			x = playerMove[enemyMoveIdx][0];
			y = playerMove[enemyMoveIdx][1];
			//������ִ� �迭idx�κ� ����
			playerMove[enemyMoveIdx][0] = -1;
			playerMove[enemyMoveIdx][1] = -1;
			enemyMoveIdx++;
			if (enemyMoveIdx == PLAYERMOVE_LENGTH) { //�ǳ����� ���� �ٽ� 0��°����� ������ ������
				enemyMoveIdx = 0;
			}

			//enemy ��ġ ����
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
	//0������ x, 1������ y��ǥ�� �����صд�.
	playerMove[playerMoveIdx][0] = playerMoveX;
	playerMove[playerMoveIdx][1] = playerMoveY;
	playerMoveIdx++;
	if (playerMoveIdx == PLAYERMOVE_LENGTH) {
		playerMoveIdx = 0;
	}
}