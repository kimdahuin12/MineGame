#include "MyItem.h"

//���� ������ �ִ� ������ ������ ���� ����

MyItem::MyItem(char* name) {
	//ù��° �������� �߰��� �� ������ �Ѵ�.
	//�ڿ� ������ �׳� ���ǰ��� �������� �� MyItem�� ����ؼ� ���� ���� �� ����.
	this->name = new char[strlen(name)];
	strcpy(this->name, name);
	count = 1;
}
MyItem::~MyItem() {
	delete name;
}


char* MyItem::getName() {
	return name;
}

void MyItem::increaseCount() {
	count++;
}
