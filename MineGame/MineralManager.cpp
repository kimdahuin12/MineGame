#include "MineralManager.h"

void LoadMineralInfo(const char* filename) {
	//FILE* fp = fopen(filename, "rt");

	/*
		광물의 색은
		DARK_BLUE,
		DARK_GREEN,
		DARK_SKYBLUE,
		DARK_RED,
		DARK_VIOLET,
		DAKR_YELLOW
		순으로 1 ~ 6.

		*파일 내용 형식*
		광물색 광물이름 광물가격 광물희귀도 광물이사라지는시간 코멘트(선택)
	*/

	//지금은 그냥 배열로 정보들이 저장되어있음


}

MineralManager::MineralManager() {
	mineralIdx = 0;
}

MineralManager::~MineralManager() {
	for (int i = 0; i < mineralIdx; i++) {
		delete mineralManager[i];
	}
}

void MineralManager::AddMineral(const char* mineralName, int x, int y) {
	mineralManager[mineralIdx++] = new Mineral(mineralName, x, y);
}
void MineralManager::RandomMineralDel(const char* ground[][GAMEPLAY_GROUND_WIDTH], int item[][GAMEPLAY_GROUND_WIDTH]) {
	//있는 광물중 랜덤으로 삭제를 시킨다.
	if (mineralIdx != 0) { //광물이 하나보다 많이 있을 때 가능.
		int randomIdx = rand() % mineralIdx; //0 ~ mineralIdx-1
		int x, y;
		x = mineralManager[randomIdx]->getX();
		y = mineralManager[randomIdx]->getY();
		delete mineralManager[randomIdx]; //랜덤한 광물을 삭제한다.

		//삭제한 광물의 뒤에 있는 광물을 배열의 앞부분으로 이동시킨다.
		for (int i = randomIdx; i < mineralIdx - 1; i++) {
			mineralManager[i] = mineralManager[i + 1];
		}
		mineralManager[mineralIdx - 1] = nullptr; //마지막에 똑같은 광물이 2개이니 주소를 없애고 광물 갯수를 -1한다.
		mineralIdx--;

		//삭제한 광물의 자리를 초기화
		ground[y][x] = "  ";
		item[y][x] = EMPTY;
		gotoXY(x * 2, COORDINATE_TOP + y);
		std::cout << ground[y * GAMEPLAY_GROUND_WIDTH + x];
	}
}

char* MineralManager::MineralCheck(int x, int y) {
	//플레이어가 어떤 광물에 닿으면 그 광물이 어느 위치에 있는지 체크하는 함수이다.
	//그 위치에 있는 광물의 이름을 가져와서 반환해준다. 그럼 플레이어의 가방에 그 광물이 저장됨
	for (int i = 0; i < mineralIdx; i++) {
		if ((mineralManager[i]->getX() == x) && (mineralManager[i]->getY() == y)) {
			//플레이어가 먹은 광물의 이름을 반환
			return mineralManager[i]->getName();
		}
	}
}
