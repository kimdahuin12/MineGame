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

}
MineralManager::~MineralManager() {
	for (int i = 0; i < mineralIdx; i++) {
		delete mineralManager[i];
	}
}

void MineralManager::AddMineral(const char* mineralName, int x, int y) {
	mineralManager[mineralIdx++] = new Mineral(mineralName, x, y);
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

int MineralManager::mineralIdx = 0;