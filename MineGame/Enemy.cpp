#include "Enemy.h"

Enemy::Enemy() {
	x = 5;
	y = 5;
	playerMoveIdx = 20; //0, 1���濡�� �̹� �����س��� ������ 2������� �÷��̾��� ��ġ�� �����صд�.
	enemyMoveIdx = 0;
	prevTime = clock();//�����ð�

	//ó���� �÷��̾������� ������ ����
	for (int i = 0; i < playerMoveIdx; i++) {
		playerMove[i][0] = 6+i;
		playerMove[i][1] = 5;
	}

	//�ٸ� �κ��� �������(-1)
	for (int i = playerMoveIdx; i < PLAYERMOVE_LENGTH; i++) {
		playerMove[i][0] = -1;
		playerMove[i][1] = -1;
	}

}

void Enemy::Update(const char* ground[], bool* mineBool) {
	//�÷��̾��� ��ġ�� ����
	
	//���� enemy ��ġ��Ű��
	ground[y * GAMEPLAY_GROUND_WIDTH + x] = ENEMY_SHAPE;

	currentTime = clock(); //���� �ð�
	lastTime = (currentTime - prevTime) / CLOCKS_PER_SEC;
	if (80 <= currentTime - prevTime) {
		//0.000001�ʸ��� ������.

		//ť
		if (playerMove[enemyMoveIdx][0] != -1 || playerMove[enemyMoveIdx][1] != -1) { //playerMove[enemyMoveIdx]�迭 �� �ϳ��� -1�� ������ִٸ�(��ǥ�� ������ �ȵ��ִٴ¶�)
			
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