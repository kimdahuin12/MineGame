#include "Mine.h"

//������ ���κ�?�� ������ ���� ���ҵǴ� ��
//�ƴϸ� ���꿡 ���Ͱ� ����ͼ� ���͸� ���ϸ鼭 �Ծ���ϰ� �ϱ�!!

Mine::Mine(Player* player, int id) {
 	this->player = player;
	playerX = 25;
	playerY = 5;
	mineBool = true;

	this->id = id;

	//
	////���� �̸�
	//this->mineName = new char[strlen(mineName) + 1];
	//strcpy(this->mineName, mineName);
	//if (!strcmp(mineName, "�Ϲ� ����")) {
	//	produceMineralSec = 2;
	//	deleteMineralSec = 3;
	//	//���� ���� ���� Ȯ��.
	//	mineralPercentage[YELLOW] = 45.0f;
	//	mineralPercentage[DARK_VIOLET] = 45.0f;
	//	mineralPercentage[DARK_RED] = 4.9f;
	//	mineralPercentage[DARK_GREEN] = 2.5f;
	//	mineralPercentage[DARK_BLUE] = 2.5f;
	//	mineralPercentage[DARK_SKYBLUE] = 0.1f;
	//	fileName = "test1.txt";
	//}
	//else if (!strcmp(mineName, "�߱� ����")) {
	//	produceMineralSec = 4;
	//	deleteMineralSec = 4;
	//	mineralPercentage[YELLOW] = 35.0f;
	//	mineralPercentage[DARK_VIOLET] = 35.0f;
	//	mineralPercentage[DARK_RED] = 23.5f;
	//	mineralPercentage[DARK_GREEN] = 3.0f;
	//	mineralPercentage[DARK_BLUE] = 3.0f;
	//	mineralPercentage[DARK_SKYBLUE] = 0.5f;
	//	fileName = "test2.txt";
	//}
	//else if (!strcmp(mineName, "��� ����")) {
	//	produceMineralSec = 5;
	//	deleteMineralSec = 5;
	//	mineralPercentage[YELLOW] = 30.0f;
	//	mineralPercentage[DARK_VIOLET] = 30.0f;
	//	mineralPercentage[DARK_RED] = 29.0f;
	//	mineralPercentage[DARK_GREEN] = 5.0f;
	//	mineralPercentage[DARK_BLUE] = 5.0f;
	//	mineralPercentage[DARK_SKYBLUE] = 1.0f;
	//	fileName = "test3.txt";
	//}
	//else if (!strcmp(mineName, "�׽�Ʈ1 ����")) {
	//	produceMineralSec = 5;
	//	deleteMineralSec = 5;
	//	mineralPercentage[YELLOW] = 30.0f;
	//	mineralPercentage[DARK_VIOLET] = 30.0f;
	//	mineralPercentage[DARK_RED] = 29.0f;
	//	mineralPercentage[DARK_GREEN] = 5.0f;
	//	mineralPercentage[DARK_BLUE] = 5.0f;
	//	mineralPercentage[DARK_SKYBLUE] = 1.0f;
	//	fileName = "test3.txt";
	//}
	//else if (!strcmp(mineName, "�׽�Ʈ2 ����")) {
	//	produceMineralSec = 5;
	//	deleteMineralSec = 5;
	//	mineralPercentage[YELLOW] = 30.0f;
	//	mineralPercentage[DARK_VIOLET] = 30.0f;
	//	mineralPercentage[DARK_RED] = 29.0f;
	//	mineralPercentage[DARK_GREEN] = 5.0f;
	//	mineralPercentage[DARK_BLUE] = 5.0f;
	//	mineralPercentage[DARK_SKYBLUE] = 1.0f;
	//	fileName = "test3.txt";
	//}
}
Mine::~Mine() {
	delete mineName;
}
 
//�ʱ�ȭ & player money
void Mine::SetMineInfo(char* name, int produceSec, int deleteSec, float* percentage) {
	this->mineName = new char[strlen(name) + 1];
	strcpy(this->mineName, name);										//���� �̸�
	produceMineralSec = produceSec;							//���ʻ��̸��� �������� ������ ����������
	deleteMineralSec = deleteSec;							//���ʻ��̸��� �������� ������ ��������
	for (int i = 0; i < MINERAL_ITEM_COUNT + 1; i++) {
		mineralPercentage[i] = percentage[i];
	}
 	sprintf(fileName, "%dminePrint.txt", 1); //����
}

void Mine::MineInit() {
#pragma region ���Ϸ� ����..

	////������ �����Ѵ�.

	////������ ����� �ҷ��´�.
	////���� �ҷ�����
	//fstream readfile(filename);
	//char* filecontent = nullptr;
	//if (readfile.is_open()) {
	//	//���� �о���� ����

	//	//�ǳ����� ��ġ �̵�
	//	readfile.seekg(0, ios::end);
	//	//�� ó�� ��ġ���� ������ġ(���� �� ��)������ ũ�⸦ ��ȯ
	//	int size = readfile.tellg();
	//	//size��ŭ ���ڿ��� ������ ������
	//	filecontent = new char[size + 1];
	//	//������ �� ó�� ��ġ�� �̵�
	//	readfile.seekg(0, ios::beg);
	//	//������ ��ü ������ filecontent�� ����
	//	readfile.read(&filecontent[0], size);
	//	//�̺κ��� ���� ���� �ؽ�Ʈ �̹����� ���� �κ��̴�.
	//	if (true) {
	//		gotoxy(0, 0);
	//		cout << "��Ȯ�� ����>>" << endl << endl;
	//		int cnt = 0;
	//		for (int i = 0; i < gameplay_ground_height; i++) {
	//			for (int j = 0; j < gameplay_ground_width; j++) {
	//				if (filecontent[i] == '0') {
	//					//c9a1
	//					ground[i][j] = "��";
	//				}
	//				else if (filecontent[i] == '1') {
	//					ground[i][j] = "��";
	//				}
	//				else if (filecontent[i] == '2') {
	//					ground[i][j] = road;
	//				}
	//			}
	//			cout << endl;
	//		}
	//		for (int i = 0; i < gameplay_ground_height; i++) {
	//			for (int j = 0; j < gameplay_ground_width; j++) {
	//				gotoxy(j*2, i + coordinate_top);
	//				cout << ground[i][j];
	//			}
	//		}
	//	}
	//}
	//else {
	//	//���� �о���� ����
	//	strcpy(filecontent, "������ ã�� �� �����ϴ�.");
	//	return;
	//}
	//readfile.close();

#pragma endregion

	//���� �÷��� �κ��� ��� ���� �ʱ�ȭ
	for (int i = 0; i < GAMEPLAY_GROUND_HEIGHT; i++) {
		for (int j = 0; j < GAMEPLAY_GROUND_WIDTH; j++) {
			item[i][j] = EMPTY;
		}
	}

	//�÷��̾��� ��ġ�� ����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	ground[playerY][playerX] = PLAYER_CHARACTER;
	gotoXY(playerX * 2, COORDINATE_TOP + playerY); //���� ��
	cout << PLAYER_CHARACTER;

	prevTime_render = clock(); //�������� ���� �ð� üũ
}

int Mine::KeyInputRelated() {
	//Ű ���õ� ó��

	int input = _getch();
	if (input == 224) { //224�� ����Ű���� �˷��ִ� �ƽ�Ű�ڵ尪
		input = _getch();

		//������ �ڸ��� �ٽ� �ǵ�����.
		ground[playerY][playerX] = ROAD;
		item[playerY][playerX] = EMPTY;
		gotoXY(playerX * 2, COORDINATE_TOP + playerY);
		cout << ground[playerY * GAMEPLAY_GROUND_WIDTH + playerX];
		if ((input == UP) && (ground[(playerY-1)][playerX] == ROAD|| ground[(playerY - 1)][playerX] == "��")) {
			playerY -= 1;
		}
		else if ((input == DOWN) && (ground[(playerY+1)][playerX] == ROAD || ground[(playerY + 1)][playerX] == "��")) { 
			playerY += 1;
		}
		else if ((input == LEFT) && (ground[playerY][playerX-1] == ROAD|| ground[playerY][playerX - 1] == "��")) {
			playerX -= 1;
		}
		else if ((input == RIGHT) && (ground[playerY][playerX+1] == ROAD|| ground[playerY][playerX + 1] == "��")) { 
			playerX += 1;
		}
		enemy.playerMoveSave(playerX, playerY);
		
		if (ground[playerY][playerX] == "��") { //�������µ� ������ �Ծ��ٸ�
			//�÷��̾��� ��ġ�� ������ �ִ� ��ġ���
			//�÷��̾ � ������ ������ �� ������ ��� ��ġ�� �ִ��� üũ.
			strcpy(mineral, mineralManager.MineralCheck(playerX, playerY)); //�� ��ġ�� �ִ� ������ �̸��� �޾ƿ´�.
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), EMPTY);
			gotoXY(0, 0);
			cout << "��Ȯ�� ����>>  " << mineral << "                                                       ";
			player->AddMineral(mineral); //�÷��̾�� �� ������ �߰��Ѵ�.
		}
		//�÷��̾ ������ ������ ����
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
		ground[playerY][playerX] = PLAYER_CHARACTER;
		item[playerY][playerX] = EMPTY;
		gotoXY(playerX * 2, COORDINATE_TOP + playerY);
		cout << ground[playerY * GAMEPLAY_GROUND_WIDTH + playerX];
	}
	return input;
}


char* Mine::randomMineral(int mineralItem) {
	//������ ���� ���� �� ������ ���� ������ �������� �����Ѵ�.
	int randomIdx;
	char* res_mineralName;
	//srand(time(NULL));�� ���ο�..
	switch (mineralItem) {
	case 1:
		//DARK_BLUE

		//���� �ε��� ����
		randomIdx = rand() % BlueMineralCount; // �Ķ��� ������ ���� ���̿��� �����ϰ� ����

		//�̸� 
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
		res_mineralName = new char[strlen("�� �� ���� ����(����)")+1];
		strcpy(res_mineralName, "�� �� ���� ����(����)");
	}
	return res_mineralName;
}

void Mine::Update() {
	enemy.Update(playerX, playerY, ground, &mineBool);

	currentTime_render = clock(); //���� �ð�

	renderTimeCheck = (currentTime_render - prevTime_render) / CLOCKS_PER_SEC; //������ �ð�

	if (renderTime <= renderTimeCheck) {
		//������ �ð��� ������(ó���� 3��) ������ �Ѵ�.
		renderTime = rand() % produceMineralSec + 1;//1 ~ produceMineralSec�� ������ ������ ����
		prevTime_render = clock();

		//����(������ ������ ���� �ִٸ� �װ��� ������ ���ϵ��� �ϱ�)
		//x, y���� �����ϰ� item�� ���� ������ ������ �ϸ� ��ȣ�� ���� ���� �ο���.
		//�׸��� ground�� ���� ����� �� �� ����
		do {
			mineralX = rand() % GAMEPLAY_GROUND_WIDTH;
			mineralY = rand() % GAMEPLAY_GROUND_HEIGHT;
			if (ground[mineralY][mineralX] == ROAD) {
				ground[mineralY][mineralX] = "��";
				break;
			}
		} while (ground[mineralY][mineralX] != "��");

		//item(������ ��)�� �������� ������
		float randomItem = rand() % 10001; //0 ~ 10000
		if (randomItem <= (mineralPercentage[DARK_SKYBLUE]*100)) { item[mineralY][mineralX] = DARK_SKYBLUE; } //���� ����� ����
		else if (randomItem <= (mineralPercentage[DARK_BLUE] * 100)) { item[mineralY][mineralX] = DARK_BLUE; }
		else if (randomItem <= (mineralPercentage[DARK_GREEN] * 100)) { item[mineralY][mineralX] = DARK_GREEN; }
		else if (randomItem <= (mineralPercentage[DARK_RED] * 100)) { item[mineralY][mineralX] = DARK_RED; }
		else if (randomItem <= (mineralPercentage[DARK_VIOLET] * 100)) { item[mineralY][mineralX] = DARK_VIOLET; }
		else{ item[mineralY][mineralX] = DARK_YELLOW; }

		mineralManager.AddMineral(randomMineral(item[mineralY][mineralX]), mineralX, mineralY);//���� ���� �����ؼ� ������ ���� �߰�
	}

	//���� ���� ����
	renderTimeCheck_delete = (currentTime_render - prevTime_render_delete) / CLOCKS_PER_SEC; //������ �ð�

	if (renderTime_delete <= renderTimeCheck_delete) {
		//������ �ð��� ������(ó���� 10��) ������ �Ѵ�.
		renderTime_delete = rand() % deleteMineralSec + 1;//1 ~ deleteMineralSec�� ������ ������ ����
		prevTime_render_delete = clock(); //���� �ð��� ���

		//������ ������ ����
		mineralManager.RandomMineralDel(ground, item);
	}
}

void Mine::Render() {
	enemy.Render(ground);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), item[mineralY][mineralX]);
	gotoXY(mineralX * 2, COORDINATE_TOP + mineralY);
	cout << ground[mineralY*GAMEPLAY_GROUND_WIDTH+mineralX];
}