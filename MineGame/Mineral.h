#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

class Mineral
{
private:
	char* name;				// 광물 이름
	//unsigned int price;		// 광물 가격
	//float rarity;			// 광물 희귀도
	//int deleteTime;			// 광물이 몇 초 뒤에 사라지는지
	int x;
	int y;
public:
	Mineral(const char* mineralName, int x, int y);
	~Mineral();
	
	int getX();
	int getY();
	char* getName();
};

