#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
//내가 가지고 있는 물건의 갯수를 세기 위한(필요하면 가격이나 희귀도도 추가 예정)
class MyItem
{
private:
	char* name;
	int count;
public:
	MyItem(char* name);
	~MyItem();
	char* getName();
	int getCount();
	void increaseCount();
};

