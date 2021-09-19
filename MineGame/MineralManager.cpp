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

}
MineralManager::~MineralManager() {
	for (int i = 0; i < mineralIdx; i++) {
		delete mineralManager[i];
	}
}

void MineralManager::AddMineral(const char* mineralName, int x, int y) {
	mineralManager[mineralIdx++] = new Mineral(mineralName, x, y);
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

int MineralManager::mineralIdx = 0;