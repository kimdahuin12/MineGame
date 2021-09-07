#pragma once
using namespace std;

class UserAccount
{
private:
	char* id;
	char* pw;
public:
	UserAccount();
	UserAccount(char id[], char pw[]);
	~UserAccount();
};