#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
//���� ������ �ִ� ������ ������ ���� ���� Ŭ����

//�������� ������ ����
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

