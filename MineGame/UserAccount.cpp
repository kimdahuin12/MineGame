#include "UserAccount.h"
#include <iostream>

UserAccount::UserAccount()
{

}

UserAccount::UserAccount(char id[], char pw[])
{
	this->id = new char[strlen(id) + 1];
	this->pw = new char[strlen(pw) + 1];
	//�����ͺ��̽��� id, pw ����
	//�ϴ� �޸��忡 ����

	
}
UserAccount::~UserAccount()
{
	delete[] id;
	delete[] pw;
}