#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
//내가 가지고 있는 물건의 갯수를 세기 위한 클래스

//아이템의 갯수를 저장
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

