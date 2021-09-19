#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "mineralInfo.h"
#include <iostream>

class Mineral
{
private:
	char* name;				// 광물 이름
	unsigned int price;		// 광물 가격
	float rarity;			// 광물 희귀도
	int deleteTime;			// 광물이 몇 초 뒤에 사라지는지
public:
	Mineral(int mineralItem);
	~Mineral();
};

