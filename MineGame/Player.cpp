#include "Player.h"

int Player::ItemCount = 0;

Player::Player() {
	//파일에서 불러와서 아래처럼 모든 아이템의 이름을 넣어주고 카운트를 0으로 초기화할 예정
	//for (int i = 0; i < 18; i++)//18은 광물, 물약 등등 모든 아이템의 갯수
	//{
	//	inventory[i] = new MyItem();
	//}
}
Player::~Player() {
	for (int i = 0; i < ItemCount; i++) {
		delete inventory[i];
	}
}

void Player::AddMineral(char* mineralName) {
	//광물 이름이 같은 myMineral의 count를 1 증가시킨다.
	for (int i = 0; i < ItemCount; i++) {
		if (strcmp(inventory[i]->getName(), mineralName) == 0) {
			//이미 같은 이름의 광물이 인벤토리에 있다.
			inventory[i]->increaseCount(); //그 아이템 갯수 증가.
			return; //함수를 빠져나간다..
		}
	}
	
	//지금 추가한 아이템이 처음 들어온 아이템이다. 그래서 생성한다. 그럼 그 아이템이 하나 추가된다.
	inventory[ItemCount++] = new MyItem(mineralName);
}

void Player::Inventory() {
	for(int i = 0; i < ItemCount; i++){
		std::cout << "광물 이름 : " << inventory[i]->getName() << std::endl;
		std::cout << "광물 갯수 : " << inventory[i]->getCount() << std::endl;
		std::cout << std::endl;
	}
	
}