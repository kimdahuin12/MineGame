#include "UserAccount.h"
#include <iostream>

UserAccount::UserAccount()
{

}

UserAccount::UserAccount(char id[], char pw[])
{
	this->id = new char[strlen(id) + 1];
	this->pw = new char[strlen(pw) + 1];
	//데이터베이스에 id, pw 저장
	//일단 메모장에 저장

	
}
UserAccount::~UserAccount()
{
	delete[] id;
	delete[] pw;
}