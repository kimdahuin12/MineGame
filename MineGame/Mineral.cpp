#include "Mineral.h"
Mineral::Mineral(const char* mineralName, int x, int y) {
	this->x = x;
	this->y = y;
	this->name = new char[strlen(mineralName)];
	strcpy(this->name, mineralName);
	////���� �ٲ���� �� ����.��

	////������ ���� ���� ������ �������� �����Ѵ�.
	//int randomIdx;
	////srand(time(NULL));�� ���ο�..
	//switch (mineralItem) {
	//case 1:
	//	//DARK_BLUE

	//	//���� �ε��� ����
	//	randomIdx = 1;//rand() % BlueMineralCount; // �Ķ��� ������ ���� ���̿��� �����ϰ� ����

	//	//�̸� 
	//	this->name = new char[strlen(BlueMineralName[randomIdx])];
	//	strcpy(this->name, BlueMineralName[randomIdx]);
	//	////����
	//	//this->price = BlueMineralPrice[randomIdx];
	//	////��͵�
	//	//this->rarity = BlueMineralRarity[randomIdx];
	//	////�� �� �� ���������
	//	//this->deleteTime = BlueMineralDelTime[randomIdx];

	//	break;
	//case 2:
	//	//DARK_GREEN

	//	randomIdx = rand() % GreenMineralCount;

	//	this->name = new char[strlen(GreenMineralName[randomIdx])];
	//	strcpy(this->name, GreenMineralName[randomIdx]);

	//	break;
	//case 3:
	//	//DARK_SKYBLUE

	//	randomIdx = rand() % SkyBlueMineralCount;

	//	this->name = new char[strlen(SkyBlueMineralName[randomIdx])];
	//	strcpy(this->name, SkyBlueMineralName[randomIdx]);

	//	break;
	//case 4:
	//	//DARK_RED

	//	randomIdx = rand() % RedMineralCount;

	//	this->name = new char[strlen(RedMineralName[randomIdx])];
	//	strcpy(this->name, RedMineralName[randomIdx]);

	//	break;
	//case 5:
	//	//DARK_VIOLET

	//	randomIdx = rand() % VioletMineralCount;

	//	this->name = new char[strlen(VioletMineralName[randomIdx])];
	//	strcpy(this->name, VioletMineralName[randomIdx]);

	//	break;
	//case 6:
	//	//DAKR_YELLOW

	//	randomIdx = rand() % YellowMineralCount;

	//	this->name = new char[strlen(YellowMineralName[randomIdx])];
	//	strcpy(this->name, YellowMineralName[randomIdx]);

	//	break;
	//}
}

Mineral::~Mineral() {
	delete name; //�̸��� �������� ������.
}


int Mineral::getX() {
	return x;
}
int Mineral::getY() {
	return y;
}
char* Mineral::getName() {
	return name;
}

