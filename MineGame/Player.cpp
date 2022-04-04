#include "Player.h"

int Player::itemCount = 0;
MyItem* Player::inventory[MineralMax] = {nullptr,}; //inventory�� player�� �ٽ� ������ �� �ʱ�ȭ��

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
	if (((long)this->money)-(money) >= 0) {
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
	this->money += money;
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
	
	inventory[itemCount++] = new MyItem(mineralName);
}

bool Player::RemoveMineral(char* mineralName) { //������ �̳׶� �̸�
	//���� �̸��� ���� myMineral�� count�� 1 ������Ų��.
	for (int i = 0; i < itemCount; i++) {
		if (strcmp(inventory[i]->getName(), mineralName) == 0) {
			//�̹� ���� �̸��� ������ �κ��丮�� �ִ�.
			inventory[i]->decreaseCount(); //�� ������ ���� ����.
			if (inventory[i]->getCount()==0) {//�ϳ��� ������ ����
				delete inventory[i];
				inventory[i] = nullptr;
				for (int j = i; j < itemCount - 1; j++) {
					inventory[j] = inventory[j + 1];
				}
				inventory[itemCount - 1] = nullptr;
				itemCount--;
			}
			return true; //�Լ��� ����������..
		}
	}

	//�����Ϸ��� �������� ����. �׳� ��.
	return false;
}

void Player::Inventory() {
	for(int i = 0; i < itemCount; i++){
		std::cout << inventory[i]->getName();

		//����,
		int nameLen = strlen(inventory[i]->getName());
		for (int i = 0; i < (30 - nameLen); i++) { std::cout << " "; }
		
		std::cout << inventory[i]->getCount()<<"��"<<std::endl;
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
}

MyItem** Player::getInventory() {
	return inventory;
}

int Player::getItemCount() {
	return itemCount;
}

int Player::GetMineralCount(char* mineralName) {
	for (int i = 0; i < itemCount; i++) {
		if (inventory[i]->getName(), mineralName) {
			return inventory[i]->getCount();
		}
	}
	return 0;
}