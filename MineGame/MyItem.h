#pragma once
#include <iostream>
//���� ������ �ִ� ������ ������ ���� ����(�ʿ��ϸ� �����̳� ��͵��� �߰� ����)
class MyItem
{
private:
	char* name;
	int count;
public:
	MyItem(char* name);
	~MyItem();
	char* getName();
	void increaseCount();
};

