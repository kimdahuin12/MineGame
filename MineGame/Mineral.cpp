#include "Mineral.h"
Mineral::Mineral(const char* mineralName, int x, int y) {
	this->x = x;
	this->y = y;
	this->name = new char[strlen(mineralName)+1];
	strcpy(this->name, mineralName);

}

Mineral::~Mineral() {
	delete name; //�̸��� �������� ������.
}


int Mineral::getX() {
	return x;
}
int Mineral::getY() {
	return y;
}
char* Mineral::getName() {
	return name;
}

