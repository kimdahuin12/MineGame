#include "MyItem.h"

//���� ������ �ִ� ������ ������ ���� ����

MyItem::MyItem(char* name) {
	//ù��° �������� �߰��� �� ������ �Ѵ�.
	//�ڿ� ������ �׳� ���ǰ��� �������� �� MyItem�� ����ؼ� ���� ���� �� ����.
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
	count = 1;
}
MyItem::~MyItem() {
	delete this->name;
}


char* MyItem::getName() {
	return name;
}

int MyItem::getCount() {
	return count;
}

void MyItem::increaseCount() {
	count++;
}

