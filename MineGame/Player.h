#pragma once
#include "MyItem.h"
class Player
{
private:
	//��
	//������ �ִ� ������ ����.(MINERAL_ITEM_COUNT) ����� ������ ������ 18�θ�
	MyItem* inventory[18];
	static int ItemCount;
	//int myBag[����, ���� ��� ��� �������� ����(��ũ�� ���� ����)];

	//����
	//���̵�
	//���
public:
	Player();
	~Player();

	void AddMineral(char* mineralName);
};

