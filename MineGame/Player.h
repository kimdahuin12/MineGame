#pragma once
//#include "mineralInfo.h"
#include <map>
class Player
{
private:
	//��
	//������ �ִ� ����
	std::map<char*, int> myMineral[6];
	//std::map<char*, int> myMineral[MINERAL_ITEM_COUNT];


	//����
	//���̵�
	//���
public:
	Player();
	~Player();

	void AddMineral(char* mineralName);
};

