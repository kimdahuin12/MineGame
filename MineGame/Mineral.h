#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "mineralInfo.h"
#include <iostream>

class Mineral
{
private:
	char* name;				// ���� �̸�
	unsigned int price;		// ���� ����
	float rarity;			// ���� ��͵�
	int deleteTime;			// ������ �� �� �ڿ� ���������
public:
	Mineral(int mineralItem);
	~Mineral();
};

