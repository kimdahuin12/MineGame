#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

class Mineral
{
private:
	char* name;				// ���� �̸�
	//unsigned int price;		// ���� ����
	//float rarity;			// ���� ��͵�
	//int deleteTime;			// ������ �� �� �ڿ� ���������
	int x;
	int y;
public:
	Mineral(const char* mineralName, int x, int y);
	~Mineral();
	
	int getX();
	int getY();
	char* getName();
};

