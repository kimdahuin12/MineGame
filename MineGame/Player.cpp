#include "Player.h"

int Player::itemCount = 0;

Player::Player(char* id, unsigned long money) {
	this->id = id;
	this->money = money;
	for (int i = 0; i < 18; i++) {
		inventory[i] = nullptr;
	}
}

Player::~Player() {
	for (int i = 0; i < itemCount; i++) {
		delete inventory[i];
	}
	itemCount = 0;
}

const char* Player::getId() {
	return id;
}

unsigned long Player::getMoney() {
	return money;
}

bool Player::decreaseMoney(long money) {
	if (this->money - money >= 0) {
		this->money -= money;
		return true;
	}
	else {
		reverseScene();
		cout << "���� �����մϴ�." << endl;
		reverseScene();
	}
	return false;
}
void Player::increaseMoney(long money) {
	money += money;
}

void Player::AddMineral(char* mineralName) {
	//���� �̸��� ���� myMineral�� count�� 1 ������Ų��.
	for (int i = 0; i < itemCount; i++) {
		if (strcmp(inventory[i]->getName(), mineralName) == 0) {
			//�̹� ���� �̸��� ������ �κ��丮�� �ִ�.
			inventory[i]->increaseCount(); //�� ������ ���� ����.
			return; //�Լ��� ����������..
		}
	}
	
	//���� �߰��� �������� ó�� ���� �������̴�. �׷��� �����Ѵ�. �׷� �� �������� �ϳ� �߰��ȴ�.
	this->inventory[itemCount++] = new MyItem(mineralName);
}

void Player::Inventory() {
	for(int i = 0; i < itemCount; i++){
		std::cout << inventory[i]->getName();

		//����,
		int nameLen = strlen(inventory[i]->getName());
		for (int i = 0; i < (30 - nameLen); i++) { std::cout << " "; }
		
		std::cout << inventory[i]->getCount()<<"��"<<std::endl;
		std::cout << std::endl;
	}
}

bool Player::MineAuthorityCheck(int mineralCount) {
	//���꿡 �� �� �ִ��� üũ
	//��� ������ ������ ���Ѵ�.
	int allItemCount = 0;
	for (int i = 0; i < itemCount; i++) {
		allItemCount += inventory[i]->getCount();
	}
	if (allItemCount >= mineralCount) { return true; }
	else { return false; }


	// 0 : �Ϲ� ���� 1: �߱� ���� 3: ��� ����
	//
	//char* mineName = nullptr;
	//if (mineIdx == 1) {
	//	//�Ϲݱ���. ������ �� �� ����
	//	mineName = new char[strlen("�Ϲ� ����") + 1];
	//	strcpy(mineName, "�Ϲ� ����");
	//}
	//else {

	//	//��� ������ ������ ���Ѵ�.
	//	int allItemCount = 0;
	//	for (int i = 0; i < itemCount; i++) {
	//		allItemCount += inventory[i]->getCount();
	//	}

	//	switch (mineIdx)
	//	{
	//	case 2:
	//		//�߱� ����
	//		if (allItemCount >= 10) {
	//			mineName = new char[strlen("�߱� ����") + 1];
	//			strcpy(mineName, "�߱� ����");
	//		}
	//		break;
	//	case 3:
	//		//��� ����
	//		if (allItemCount >= 20) {
	//			mineName = new char[strlen("��� ����") + 1];
	//			strcpy(mineName, "��� ����");
	//		}
	//		break;
	//	case 4:
	//		//��� ����
	//		if (allItemCount >= 20) {
	//			mineName = new char[strlen("�׽�Ʈ1 ����") + 1];
	//			strcpy(mineName, "�׽�Ʈ1 ����");
	//		}
	//		break;
	//	case 5:
	//		//��� ����
	//		if (allItemCount >= 20) {
	//			mineName = new char[strlen("�׽�Ʈ2 ����") + 1];
	//			strcpy(mineName, "�׽�Ʈ2 ����");
	//		}
	//		break;
	//	default:
	//		std::cout << "����" << std::endl;
	//		break;
	//	}
	//}

	//return mineName;
}

MyItem** Player::getInventory() {
	return inventory;
}

int Player::getItemCount() {
	return itemCount;
}