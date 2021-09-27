#include "Mine.h"
Mine::Mine(const char* mineName, Player* player) {
	this->player = player;
	playerX = 0;
	playerY = 0;

	//광산 이름
	this->mineName = new char[strlen(mineName) + 1];
	strcpy(this->mineName, mineName);
	cout << "헬로우" << endl;
	if (!strcmp(mineName, "일반 광산")) {
		produceMineralSec = 3;
		deleteMineralSec = 10;
		//광물 색에 따른 확률.
		mineralPercentage[DARK_BLUE] = 45.0f;
		mineralPercentage[DARK_VIOLET] = 45.0f;
		mineralPercentage[DARK_RED] = 4.9f;
		mineralPercentage[DARK_GREEN] = 2.5f;
		mineralPercentage[DAKR_YELLOW] = 2.5f;
		mineralPercentage[DARK_SKYBLUE] = 0.1f;
		
	}
	else if (!strcmp(mineName, "중급 광산")) {
		produceMineralSec = 4;
		deleteMineralSec = 8;
		mineralPercentage[DARK_BLUE] = 35.0f;
		mineralPercentage[DARK_VIOLET] = 35.0f;
		mineralPercentage[DARK_RED] = 23.5f;
		mineralPercentage[DARK_GREEN] = 3.0f;
		mineralPercentage[DAKR_YELLOW] = 3.0f;
		mineralPercentage[DARK_SKYBLUE] = 0.5f;
	}
	else if (!strcmp(mineName, "고급 광산")) {
		produceMineralSec = 5;
		deleteMineralSec = 6;
		mineralPercentage[DARK_BLUE] = 30.0f;
		mineralPercentage[DARK_VIOLET] = 30.0f;
		mineralPercentage[DARK_RED] = 29.0f;
		mineralPercentage[DARK_GREEN] = 5.0f;
		mineralPercentage[DAKR_YELLOW] = 5.0f;
		mineralPercentage[DARK_SKYBLUE] = 1.0f;
	}
}
Mine::~Mine() {
	delete mineName;
}
 
void Mine::MineInit() {
	//광산을 세팅한다.

	gotoXY(0, 0);
	cout << "수확한 광물>>" << endl << endl;

	//게임 플레이 부분의 모든 곳을 초기화
	for (int i = 0; i < GAMEPLAY_GROUND_HEIGHT; i++) {
		for (int j = 0; j < GAMEPLAY_GROUND_WIDTH; j++) {
			ground[i][j] = "  ";
			item[i][j] = EMPTY;
		}
	}

	//벽을 생성
	for (int i = -1; i < GAMEPLAY_GROUND_HEIGHT + 1; i++) {
		gotoXY((COORDINATE_LEFT - 1) * 2, COORDINATE_TOP + i); cout << "◆";
		gotoXY((COORDINATE_LEFT + GAMEPLAY_GROUND_WIDTH) * 2, COORDINATE_TOP + i); cout << "◆";
	}
	for (int i = -1; i < GAMEPLAY_GROUND_WIDTH + 1; i++) {
		gotoXY((COORDINATE_LEFT + i) * 2, COORDINATE_TOP - 1); cout << "◆";
		gotoXY((COORDINATE_LEFT + i) * 2, COORDINATE_TOP + GAMEPLAY_GROUND_HEIGHT); cout << "◆";
	}

	//플레이어의 위치를 세팅
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	ground[playerY][playerX] = (*player).getCharacter();
	gotoXY((COORDINATE_LEFT + playerX) * 2, COORDINATE_TOP + playerY); //왼쪽 위
	cout << (*player).getCharacter();

	prevTime_render = clock(); //시작했을 때의 시간 체크
}

int Mine::KeyInputRelated() {
	int input = _getch();
	if (input == 224) { //224는 방향키임을 알려주는 아스키코드값
		input = _getch();

		//지나간 자리를 다시 되돌린다.
		ground[playerY][playerX] = "  ";
		item[playerY][playerX] = EMPTY;
		gotoXY((COORDINATE_LEFT + playerX) * 2, COORDINATE_TOP + playerY);
		cout << ground[playerY][playerX];
		if ((input == UP) && ((playerY - 1) != -1)) { playerY -= 1; }
		else if ((input == DOWN) && ((playerY + 1) != GAMEPLAY_GROUND_HEIGHT)) { playerY += 1; }
		else if ((input == LEFT) && ((playerX - 1) != -1)) { playerX -= 1; }
		else if ((input == RIGHT) && ((playerX + 1) != GAMEPLAY_GROUND_WIDTH)) { playerX += 1; }

		if (strcmp(ground[playerY][playerX], "■") == 0) { //움직였는데 광물을 먹었다면
			//플레이어의 위치가 광물이 있는 위치라면
			//플레이어가 어떤 광물에 닿으면 그 광물이 어느 위치에 있는지 체크.
			strcpy(mineral, mineralManager.MineralCheck(playerX, playerY)); //그 위치에 있는 광물의 이름을 받아온다.
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), EMPTY);
			gotoXY(0, 0);
			cout << "수확한 광물>>  " << mineral << "                              ";
			(*player).AddMineral(mineral); //플레이어에게 그 광물을 추가한다.
		}
		//플레이어가 움직인 곳으로 세팅
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
		ground[playerY][playerX] = (*player).getCharacter();
		item[playerY][playerX] = EMPTY;
		gotoXY((COORDINATE_LEFT + playerX) * 2, COORDINATE_TOP + playerY);
		cout << ground[playerY][playerX];
	}
	return input;
}


char* Mine::randomMineral(int mineralItem) {
	//광물의 색에 따라 광물을 랜덤으로 생성한다.
	int randomIdx;
	char* res_mineralName;
	//srand(time(NULL));는 메인에..
	switch (mineralItem) {
	case 1:
		//DARK_BLUE

		//랜덤 인덱스 생성
		randomIdx = 1;//rand() % BlueMineralCount; // 파란색 광물의 갯수 사이에서 랜덤하게 생성

		//이름 
		res_mineralName = new char[strlen(BlueMineralName[randomIdx])];
		strcpy(res_mineralName, BlueMineralName[randomIdx]);
		break;
	case 2:
		//DARK_GREEN

		randomIdx = rand() % GreenMineralCount;

		res_mineralName = new char[strlen(GreenMineralName[randomIdx])];
		strcpy(res_mineralName, GreenMineralName[randomIdx]);

		break;
	case 3:
		//DARK_SKYBLUE

		randomIdx = rand() % SkyBlueMineralCount;

		res_mineralName = new char[strlen(SkyBlueMineralName[randomIdx])];
		strcpy(res_mineralName, SkyBlueMineralName[randomIdx]);

		break;
	case 4:
		//DARK_RED

		randomIdx = rand() % RedMineralCount;

		res_mineralName = new char[strlen(RedMineralName[randomIdx])];
		strcpy(res_mineralName, RedMineralName[randomIdx]);

		break;
	case 5:
		//DARK_VIOLET

		randomIdx = rand() % VioletMineralCount;

		res_mineralName = new char[strlen(VioletMineralName[randomIdx])];
		strcpy(res_mineralName, VioletMineralName[randomIdx]);

		break;
	case 6:
		//DAKR_YELLOW

		randomIdx = rand() % YellowMineralCount;

		res_mineralName = new char[strlen(YellowMineralName[randomIdx])];
		strcpy(res_mineralName, YellowMineralName[randomIdx]);

		break;
	default:
		res_mineralName = new char[strlen("알 수 없는 광물(오류)")+1];
		strcpy(res_mineralName, "알 수 없는 광물(오류)");
	}
	return res_mineralName;
}


void Mine::Update() {

	currentTime_render = clock(); //지금 시각

	renderTimeCheck = (currentTime_render - prevTime_render) / CLOCKS_PER_SEC; //지나간 시간

	if (renderTime <= renderTimeCheck) {
		//랜덤한 시간이 지나면(처음은 3초) 생성을 한다.
		renderTime = rand() % produceMineralSec + 1;//1 ~ produceMineralSec초 사이의 랜덤한 생성
		prevTime_render = clock();

		//생성
		//x, y값을 생성하고 item은 실제 광물의 역할을 하며 번호에 따른 색이 부여됨.
		//그리고 ground는 땅의 출력을 할 때 사용되는 정도
		mineralX = rand() % GAMEPLAY_GROUND_WIDTH;
		mineralY = rand() % GAMEPLAY_GROUND_HEIGHT;
		ground[mineralY][mineralX] = "■";

		//item(광물의 색)을 랜덤으로 정해줌
		float randomItem = rand() % 10001; //0 ~ 10000
		if (randomItem <= (mineralPercentage[DARK_SKYBLUE]*100)) { item[mineralY][mineralX] = DARK_SKYBLUE; } //가장 희귀한 광물
		else if (randomItem <= (mineralPercentage[DAKR_YELLOW] * 100)) { item[mineralY][mineralX] = DAKR_YELLOW; }
		else if (randomItem <= (mineralPercentage[DARK_GREEN] * 100)) { item[mineralY][mineralX] = DARK_GREEN; }
		else if (randomItem <= (mineralPercentage[DARK_RED] * 100)) { item[mineralY][mineralX] = DARK_RED; }
		else if (randomItem <= (mineralPercentage[DARK_VIOLET] * 100)) { item[mineralY][mineralX] = DARK_VIOLET; }
		else{ item[mineralY][mineralX] = DARK_BLUE; }

		mineralManager.AddMineral(randomMineral(item[mineralY][mineralX]), mineralX, mineralY);//랜덤 광물 생성해서 생성된 광물 추가
	}

	//광물 삭제 랜덤
	renderTimeCheck_delete = (currentTime_render - prevTime_render_delete) / CLOCKS_PER_SEC; //지나간 시간

	if (renderTime_delete <= renderTimeCheck_delete) {
		//랜덤한 시간이 지나면(처음은 10초) 삭제를 한다.
		renderTime_delete = rand() % deleteMineralSec + 5;//5 ~ deleteMineralSec+4초 사이의 랜덤한 삭제
		prevTime_render_delete = clock(); //이전 시간을 기록

		//랜덤한 광물을 삭제
		mineralManager.RandomMineralDel(ground, item);
	}
}

void Mine::Render() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), item[mineralY][mineralX]);
	gotoXY((COORDINATE_LEFT + mineralX) * 2, COORDINATE_TOP + mineralY);
	cout << ground[mineralY][mineralX];
}