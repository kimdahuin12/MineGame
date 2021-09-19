#pragma once
//#include "mineralInfo.h"
#include <map>
class Player
{
private:
	//돈
	//가지고 있는 광물
	std::map<char*, int> myMineral[6];
	//std::map<char*, int> myMineral[MINERAL_ITEM_COUNT];


	//순위
	//아이디
	//등등
public:
	Player();
	~Player();

	void AddMineral(char* mineralName);
};

