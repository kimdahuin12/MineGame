#pragma once
#include "MyItem.h"
class Player
{
private:
	//돈
	//가지고 있는 아이템 갯수.(MINERAL_ITEM_COUNT) 현재는 광물의 갯수인 18로만
	MyItem* inventory[18];
	static int ItemCount;
	//int myBag[광물, 물약 등등 모든 아이템의 갯수(매크로 설정 예정)];

	//순위
	//아이디
	//등등
public:
	Player();
	~Player();

	void AddMineral(char* mineralName);
};

