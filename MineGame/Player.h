#pragma once
#include "MyItem.h"
#include "global.h"
#define MineralMax 18
class Player
{
private:
	const char* id;
	unsigned long money;
	//��
	//���� �� �ִ� ������ ����.(MINERAL_ITEM_COUNT) ����� ������ ������ 18�θ�
	MyItem* inventory[MineralMax];
	static int itemCount;
	//int myBag[����, ���� ��� ��� �������� ����(��ũ�� ���� ����)];
	
	//����
	//���̵�
	//���
public:
	Player(char* id, unsigned long money);
	~Player();

	const char* getId();
	unsigned long getMoney();
	bool decreaseMoney(long money);
	void increaseMoney(long money);

	//������ ���� �κе� �� ����
	void AddMineral(char* mineralName);
	void Inventory();
	bool MineAuthorityCheck(int mineralCount);
	MyItem** getInventory();
	int getItemCount();
};

