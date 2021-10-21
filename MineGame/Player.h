#pragma once
#include "MyItem.h"

class Player
{
private:
	const char* id;
	//��
	//���� �� �ִ� ������ ����.(MINERAL_ITEM_COUNT) ����� ������ ������ 18�θ�
	MyItem* inventory[18];
	static int ItemCount;
	//int myBag[����, ���� ��� ��� �������� ����(��ũ�� ���� ����)];

	const char* playerCharacter = "��";
	//����
	//���̵�
	//���
public:
	Player();
	~Player();

	void setId(const char* id) {
		this->id = id;
	}
	const char* getCharacter();
	//������ ���� �κе� �� ����
	void AddMineral(char* mineralName);
	void Inventory();
	char* MineAuthorityCheck(int mineIdx);
};

