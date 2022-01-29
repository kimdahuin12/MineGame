#include "MineralManager.h"

void LoadMineralInfo(const char* filename) {
	//FILE* fp = fopen(filename, "rt");

	/*
		������ ����
		DARK_BLUE,
		DARK_GREEN,
		DARK_SKYBLUE,
		DARK_RED,
		DARK_VIOLET,
		DAKR_YELLOW
		������ 1 ~ 6.

		*���� ���� ����*
		������ �����̸� �������� ������͵� �����̻�����½ð� �ڸ�Ʈ(����)
	*/

	//������ �׳� �迭�� �������� ����Ǿ�����


}

MineralManager::MineralManager() {
	mineralIdx = 0;
}

MineralManager::~MineralManager() {
	for (int i = 0; i < mineralIdx; i++) {
		delete mineralManager[i];
	}
}

void MineralManager::AddMineral(const char* mineralName, int x, int y) {
	mineralManager[mineralIdx++] = new Mineral(mineralName, x, y);
}
void MineralManager::RandomMineralDel(const char* ground[][GAMEPLAY_GROUND_WIDTH], int item[][GAMEPLAY_GROUND_WIDTH]) {
	//�ִ� ������ �������� ������ ��Ų��.
	if (mineralIdx != 0) { //������ �ϳ����� ���� ���� �� ����.
		int randomIdx = rand() % mineralIdx; //0 ~ mineralIdx-1
		int x, y;
		x = mineralManager[randomIdx]->getX();
		y = mineralManager[randomIdx]->getY();
		delete mineralManager[randomIdx]; //������ ������ �����Ѵ�.

		//������ ������ �ڿ� �ִ� ������ �迭�� �պκ����� �̵���Ų��.
		for (int i = randomIdx; i < mineralIdx - 1; i++) {
			mineralManager[i] = mineralManager[i + 1];
		}
		mineralManager[mineralIdx - 1] = nullptr; //�������� �Ȱ��� ������ 2���̴� �ּҸ� ���ְ� ���� ������ -1�Ѵ�.
		mineralIdx--;

		//������ ������ �ڸ��� �ʱ�ȭ
		ground[y][x] = "  ";
		item[y][x] = EMPTY;
		gotoXY(x * 2, COORDINATE_TOP + y);
		std::cout << ground[y * GAMEPLAY_GROUND_WIDTH + x];
	}
}

char* MineralManager::MineralCheck(int x, int y) {
	//�÷��̾ � ������ ������ �� ������ ��� ��ġ�� �ִ��� üũ�ϴ� �Լ��̴�.
	//�� ��ġ�� �ִ� ������ �̸��� �����ͼ� ��ȯ���ش�. �׷� �÷��̾��� ���濡 �� ������ �����
	for (int i = 0; i < mineralIdx; i++) {
		if ((mineralManager[i]->getX() == x) && (mineralManager[i]->getY() == y)) {
			//�÷��̾ ���� ������ �̸��� ��ȯ
			return mineralManager[i]->getName();
		}
	}
}
