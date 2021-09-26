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

const char* Player::getCharacter() {
	return playerCharacter;
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
		std::cout << inventory[i]->getName();
		for (int i = 0; i < (40 - strlen(inventory[i]->getName())); i++) {
			std::cout << " ";
		}
		std::cout << inventory[i]->getCount()<<"개";
		std::cout << std::endl;
	}
	
}

char* Player::MineAuthorityCheck(int mineIdx) {
	//광산에 들어갈 수 있는지 체크
	// 0 : 일반 광산 1: 중급 광산 3: 고급 광산
	
	char mineName[10] = "\0";
	if (mineIdx == 1) {
		//일반광산. 누구나 들어갈 수 있음
		strcpy(mineName, "일반 광산");
	}
	else {

		//모든 아이템 갯수를 구한다.
		int allItemCount = 0;
		for (int i = 0; i < ItemCount; i++) {
			allItemCount += inventory[i]->getCount();
		}

		switch (mineIdx)
		{
		case 2:
			//중급 광산
			if (allItemCount >= 10) {
				strcpy(mineName, "중급 광산");
			}
			break;
		case 3:
			//고급 광산
			if (allItemCount >= 20) {
				strcpy(mineName, "고급 광산");
			}
			break;
		default:
			std::cout << "오류" << std::endl;
			break;
		}
	}

	return mineName;
}