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
		std::cout << "���� �̸� : " << inventory[i]->getName() << std::endl;
		std::cout << "���� ���� : " << inventory[i]->getCount() << std::endl;
		std::cout << std::endl;
	}
	
}