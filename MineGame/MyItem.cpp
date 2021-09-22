#include "MyItem.h"

//내가 가지고 있는 물건의 갯수를 세기 위한

MyItem::MyItem(char* name) {
	//첫번째 아이템이 추가될 때 생성을 한다.
	//뒤에 광물과 그냥 포션같은 아이템을 이 MyItem을 상속해서 따로 만들 것 같다.
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

