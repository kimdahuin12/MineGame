#include "Player.h"

int Player::ItemCount = 0;

Player::Player() {
	//���Ͽ��� �ҷ��ͼ� �Ʒ�ó�� ��� �������� �̸��� �־��ְ� ī��Ʈ�� 0���� �ʱ�ȭ�� ����
	//for (int i = 0; i < 18; i++)//18�� ����, ���� ��� ��� �������� ����
	//{
	//	inventory[i] = new MyItem();
	//}
}
Player::~Player() {
	for (int i = 0; i < ItemCount; i++) {
		delete inventory[i];
	}
}

const char* Player::getCharacter() {
	return playerCharacter;
}

void Player::AddMineral(char* mineralName) {
	//���� �̸��� ���� myMineral�� count�� 1 ������Ų��.
	for (int i = 0; i < ItemCount; i++) {
		if (strcmp(inventory[i]->getName(), mineralName) == 0) {
			//�̹� ���� �̸��� ������ �κ��丮�� �ִ�.
			inventory[i]->increaseCount(); //�� ������ ���� ����.
			return; //�Լ��� ����������..
		}
	}
	
	//���� �߰��� �������� ó�� ���� �������̴�. �׷��� �����Ѵ�. �׷� �� �������� �ϳ� �߰��ȴ�.
	inventory[ItemCount++] = new MyItem(mineralName);
}

void Player::Inventory() {
	for(int i = 0; i < ItemCount; i++){
		std::cout << inventory[i]->getName();
		for (int i = 0; i < (40 - strlen(inventory[i]->getName())); i++) {
			std::cout << " ";
		}
		std::cout << inventory[i]->getCount()<<"��";
		std::cout << std::endl;
	}
	
}

char* Player::MineAuthorityCheck(int mineIdx) {
	//���꿡 �� �� �ִ��� üũ
	// 0 : �Ϲ� ���� 1: �߱� ���� 3: ��� ����
	
	char mineName[10] = "\0";
	if (mineIdx == 1) {
		//�Ϲݱ���. ������ �� �� ����
		strcpy(mineName, "�Ϲ� ����");
	}
	else {

		//��� ������ ������ ���Ѵ�.
		int allItemCount = 0;
		for (int i = 0; i < ItemCount; i++) {
			allItemCount += inventory[i]->getCount();
		}

		switch (mineIdx)
		{
		case 2:
			//�߱� ����
			if (allItemCount >= 10) {
				strcpy(mineName, "�߱� ����");
			}
			break;
		case 3:
			//��� ����
			if (allItemCount >= 20) {
				strcpy(mineName, "��� ����");
			}
			break;
		default:
			std::cout << "����" << std::endl;
			break;
		}
	}

	return mineName;
}