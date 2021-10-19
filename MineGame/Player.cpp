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

		//����,
		int nameLen = strlen(inventory[i]->getName());
		for (int i = 0; i < (30 - nameLen); i++) { std::cout << " "; }
		
		std::cout << inventory[i]->getCount()<<"��"<<std::endl;
		std::cout << std::endl;
	}
	
}

char* Player::MineAuthorityCheck(int mineIdx) {
	//���꿡 �� �� �ִ��� üũ
	// 0 : �Ϲ� ���� 1: �߱� ���� 3: ��� ����
	
	char* mineName = nullptr;
	if (mineIdx == 1) {
		//�Ϲݱ���. ������ �� �� ����
		mineName = new char[strlen("�Ϲ� ����") + 1];
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
				mineName = new char[strlen("�߱� ����") + 1];
				strcpy(mineName, "�߱� ����");
			}
			break;
		case 3:
			//��� ����
			if (allItemCount >= 20) {
				mineName = new char[strlen("��� ����") + 1];
				strcpy(mineName, "��� ����");
			}
			break;
		case 4:
			//��� ����
			if (allItemCount >= 20) {
				mineName = new char[strlen("�׽�Ʈ1 ����") + 1];
				strcpy(mineName, "�׽�Ʈ1 ����");
			}
			break;
		case 5:
			//��� ����
			if (allItemCount >= 20) {
				mineName = new char[strlen("�׽�Ʈ2 ����") + 1];
				strcpy(mineName, "�׽�Ʈ2 ����");
			}
			break;
		default:
			std::cout << "����" << std::endl;
			break;
		}
	}

	return mineName;
}