#pragma once
#include "MyItem.h"

class Player
{
private:
	const char* id;
	unsigned int money;
	//돈
	//가질 수 있는 아이템 갯수.(MINERAL_ITEM_COUNT) 현재는 광물의 갯수인 18로만
	MyItem* inventory[18];
	static int ItemCount;
	//int myBag[광물, 물약 등등 모든 아이템의 갯수(매크로 설정 예정)];
	
	//순위
	//아이디
	//등등
public:
	Player();
	~Player();

	void setId(const char* id) {
		this->id = id;
	}

	//아이템 삭제 부분도 할 예정
	void AddMineral(char* mineralName);
	void Inventory();
	char* MineAuthorityCheck(int mineIdx);
};

