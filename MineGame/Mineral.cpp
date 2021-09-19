#include "Mineral.h"
Mineral::Mineral(int mineralItem) {

	//���� �ٲ���� �� ����.

	//������ ���� ���� ������ �������� �����Ѵ�.
	int randomIdx;
	//srand(time(NULL));�� ���ο�..
	switch (mineralItem) {
	case 1:
		//DARK_BLUE

		//���� �ε��� ����
		randomIdx = rand() % BlueMineralCount; // �Ķ��� ������ ���� ���̿��� �����ϰ� ����

		//�̸� 
		this->name = new char[strlen(BlueMineralName[randomIdx])];
		strcpy(this->name, BlueMineralName[randomIdx]);
		//����
		this->price = BlueMineralPrice[randomIdx];
		//��͵�
		this->rarity = BlueMineralRarity[randomIdx];
		//�� �� �� ���������
		this->deleteTime = BlueMineralDelTime[randomIdx];

		break;
	case 2:
		//DARK_GREEN

		randomIdx = rand() % GreenMineralCount;

		this->name = new char[strlen(GreenMineralName[randomIdx])];
		strcpy(this->name, GreenMineralName[randomIdx]);

		this->price = GreenMineralPrice[randomIdx];
		this->rarity = GreenMineralRarity[randomIdx];
		this->deleteTime = GreenMineralDelTime[randomIdx];

		break;
	case 3:
		//DARK_SKYBLUE

		randomIdx = rand() % SkyBlueMineralCount;

		this->name = new char[strlen(SkyBlueMineralName[randomIdx])];
		strcpy(this->name, SkyBlueMineralName[randomIdx]);

		this->price = SkyBlueMineralPrice[randomIdx];
		this->rarity = SkyBlueMineralRarity[randomIdx];
		this->deleteTime = SkyBlueMineralDelTime[randomIdx];

		break;
	case 4:
		//DARK_RED

		randomIdx = rand() % RedMineralCount;

		this->name = new char[strlen(RedMineralName[randomIdx])];
		strcpy(this->name, RedMineralName[randomIdx]);

		this->price = RedMineralPrice[randomIdx];
		this->rarity = RedMineralRarity[randomIdx];
		this->deleteTime = RedMineralDelTime[randomIdx];

		break;
	case 5:
		//DARK_VIOLET

		randomIdx = rand() % VioletMineralCount;

		this->name = new char[strlen(VioletMineralName[randomIdx])];
		strcpy(this->name, VioletMineralName[randomIdx]);

		this->price = VioletMineralPrice[randomIdx];
		this->rarity = VioletMineralRarity[randomIdx];
		this->deleteTime = VioletMineralDelTime[randomIdx];

		break;
	case 6:
		//DAKR_YELLOW

		randomIdx = rand() % YellowMineralCount;

		this->name = new char[strlen(YellowMineralName[randomIdx])];
		strcpy(this->name, YellowMineralName[randomIdx]);

		this->price = YellowMineralPrice[randomIdx];
		this->rarity = YellowMineralRarity[randomIdx];
		this->deleteTime = YellowMineralDelTime[randomIdx];

		break;
	}
}

Mineral::~Mineral() {
	delete name; //�̸��� �������� ������.
}


