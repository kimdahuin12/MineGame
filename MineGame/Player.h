#pragma once
#include "MyItem.h"

class Player
{
private:
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

	const char* getCharacter();
	//������ ���� �κе� �� ����
	void AddMineral(char* mineralName);
	void Inventory();
	char* MineAuthorityCheck(int mineIdx);
};

