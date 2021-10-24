#pragma once
#include "MyItem.h"

class Player
{
private:
	const char* id;
	unsigned int money;
	//��
	//���� �� �ִ� ������ ����.(MINERAL_ITEM_COUNT) ����� ������ ������ 18�θ�
	MyItem* inventory[18];
	static int ItemCount;
	//int myBag[����, ���� ��� ��� �������� ����(��ũ�� ���� ����)];
	
	//����
	//���̵�
	//���
public:
	Player();
	~Player();

	void setId(const char* id) {
		this->id = id;
	}

	//������ ���� �κе� �� ����
	void AddMineral(char* mineralName);
	void Inventory();
	char* MineAuthorityCheck(int mineIdx);
};

