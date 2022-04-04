#include "Player.h"

int Player::itemCount = 0;
MyItem* Player::inventory[MineralMax] = {nullptr,}; //inventory는 player가 다시 생성될 때 초기화됨

Player::Player(char* id, unsigned long money) {
	this->id = id;
	this->money = money;
	for (int i = 0; i < 18; i++) {
		inventory[i] = nullptr;
	}
}

Player::~Player() {
	for (int i = 0; i < itemCount; i++) {
		delete inventory[i];
	}
	itemCount = 0;
}

const char* Player::getId() {
	return id;
}

unsigned long Player::getMoney() {
	return money;
}

bool Player::decreaseMoney(long money) {
	if (((long)this->money)-(money) >= 0) {
		this->money -= money;
		return true;
	}
	else {
		reverseScene();
		cout << "돈이 부족합니다." << endl;
		reverseScene();
	}
	return false;
}
void Player::increaseMoney(long money) {
	this->money += money;
}
void Player::AddMineral(char* mineralName) {
	//광물 이름이 같은 myMineral의 count를 1 증가시킨다.
	for (int i = 0; i < itemCount; i++) {
		if (strcmp(inventory[i]->getName(), mineralName) == 0) {
			//이미 같은 이름의 광물이 인벤토리에 있다.
			inventory[i]->increaseCount(); //그 아이템 갯수 증가.
			return; //함수를 빠져나간다..
		}
	}
	//지금 추가한 아이템이 처음 들어온 아이템이다. 그래서 생성한다. 그럼 그 아이템이 하나 추가된다.
	
	inventory[itemCount++] = new MyItem(mineralName);
}

bool Player::RemoveMineral(char* mineralName) { //삭제할 미네랄 이름
	//광물 이름이 같은 myMineral의 count를 1 증가시킨다.
	for (int i = 0; i < itemCount; i++) {
		if (strcmp(inventory[i]->getName(), mineralName) == 0) {
			//이미 같은 이름의 광물이 인벤토리에 있다.
			inventory[i]->decreaseCount(); //그 아이템 갯수 감소.
			if (inventory[i]->getCount()==0) {//하나도 없으면 삭제
				delete inventory[i];
				inventory[i] = nullptr;
				for (int j = i; j < itemCount - 1; j++) {
					inventory[j] = inventory[j + 1];
				}
				inventory[itemCount - 1] = nullptr;
				itemCount--;
			}
			return true; //함수를 빠져나간다..
		}
	}

	//삭제하려는 아이템이 없다. 그냥 끝.
	return false;
}

void Player::Inventory() {
	for(int i = 0; i < itemCount; i++){
		std::cout << inventory[i]->getName();

		//공백,
		int nameLen = strlen(inventory[i]->getName());
		for (int i = 0; i < (30 - nameLen); i++) { std::cout << " "; }
		
		std::cout << inventory[i]->getCount()<<"개"<<std::endl;
	}
}

bool Player::MineAuthorityCheck(int mineralCount) {
	//광산에 들어갈 수 있는지 체크
	//모든 아이템 갯수를 구한다.
	int allItemCount = 0;
	for (int i = 0; i < itemCount; i++) {
		allItemCount += inventory[i]->getCount();
	}
	if (allItemCount >= mineralCount) { return true; }
	else { return false; }
}

MyItem** Player::getInventory() {
	return inventory;
}

int Player::getItemCount() {
	return itemCount;
}

int Player::GetMineralCount(char* mineralName) {
	for (int i = 0; i < itemCount; i++) {
		if (inventory[i]->getName(), mineralName) {
			return inventory[i]->getCount();
		}
	}
	return 0;
}