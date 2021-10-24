#include "Mine.h"

//������ ���κ�?�� ������ ���� ���ҵǴ� ��
//�ƴϸ� ���꿡 ���Ͱ� ����ͼ� ���͸� ���ϸ鼭 �Ծ���ϰ� �ϱ�!!

Mine::Mine(const char* mineName, Player* player) {
	this->player = player;
	playerX = 25;
	playerY = 5;
	mineBool = true;

	//���� �̸�
	this->mineName = new char[strlen(mineName) + 1];
	strcpy(this->mineName, mineName);
	if (!strcmp(mineName, "�Ϲ� ����")) {
		produceMineralSec = 2;
		deleteMineralSec = 3;
		//���� ���� ���� Ȯ��.
		mineralPercentage[DARK_BLUE] = 45.0f;
		mineralPercentage[DARK_VIOLET] = 45.0f;
		mineralPercentage[DARK_RED] = 4.9f;
		mineralPercentage[DARK_GREEN] = 2.5f;
		mineralPercentage[DAKR_YELLOW] = 2.5f;
		mineralPercentage[DARK_SKYBLUE] = 0.1f;
		fileName = "test1.txt";
	}
	else if (!strcmp(mineName, "�߱� ����")) {
		produceMineralSec = 4;
		deleteMineralSec = 4;
		mineralPercentage[DARK_BLUE] = 35.0f;
		mineralPercentage[DARK_VIOLET] = 35.0f;
		mineralPercentage[DARK_RED] = 23.5f;
		mineralPercentage[DARK_GREEN] = 3.0f;
		mineralPercentage[DAKR_YELLOW] = 3.0f;
		mineralPercentage[DARK_SKYBLUE] = 0.5f;
		fileName = "test2.txt";
	}
	else if (!strcmp(mineName, "��� ����")) {
		produceMineralSec = 5;
		deleteMineralSec = 5;
		mineralPercentage[DARK_BLUE] = 30.0f;
		mineralPercentage[DARK_VIOLET] = 30.0f;
		mineralPercentage[DARK_RED] = 29.0f;
		mineralPercentage[DARK_GREEN] = 5.0f;
		mineralPercentage[DAKR_YELLOW] = 5.0f;
		mineralPercentage[DARK_SKYBLUE] = 1.0f;
		fileName = "test3.txt";
	}
	else if (!strcmp(mineName, "�׽�Ʈ1 ����")) {
		produceMineralSec = 5;
		deleteMineralSec = 5;
		mineralPercentage[DARK_BLUE] = 30.0f;
		mineralPercentage[DARK_VIOLET] = 30.0f;
		mineralPercentage[DARK_RED] = 29.0f;
		mineralPercentage[DARK_GREEN] = 5.0f;
		mineralPercentage[DAKR_YELLOW] = 5.0f;
		mineralPercentage[DARK_SKYBLUE] = 1.0f;
		fileName = "test3.txt";
	}
	else if (!strcmp(mineName, "�׽�Ʈ2 ����")) {
		produceMineralSec = 5;
		deleteMineralSec = 5;
		mineralPercentage[DARK_BLUE] = 30.0f;
		mineralPercentage[DARK_VIOLET] = 30.0f;
		mineralPercentage[DARK_RED] = 29.0f;
		mineralPercentage[DARK_GREEN] = 5.0f;
		mineralPercentage[DAKR_YELLOW] = 5.0f;
		mineralPercentage[DARK_SKYBLUE] = 1.0f;
		fileName = "test3.txt";
	}
}
Mine::~Mine() {
	delete mineName;
}
 
void Mine::MineInit() {
	//������ �����Ѵ�.

	//������ ����� �ҷ��´�.
	//���� �ҷ�����
	fstream readFile(fileName);
	char* fileContent = nullptr;
	if (readFile.is_open()) {
		//���� �о���� ����

		//�ǳ����� ��ġ �̵�
		readFile.seekg(0, ios::end);
		//�� ó�� ��ġ���� ������ġ(���� �� ��)������ ũ�⸦ ��ȯ
		int size = readFile.tellg();
		//size��ŭ ���ڿ��� ������ ������
		fileContent = new char[size + 1];
		//������ �� ó�� ��ġ�� �̵�
		readFile.seekg(0, ios::beg);
		//������ ��ü ������ fileContent�� ����
		readFile.read(&fileContent[0], size);
		//�̺κ��� ���� ���� �ؽ�Ʈ �̹����� ���� �κ��̴�.
		if (true) {
			gotoXY(0, 0);
			cout << "��Ȯ�� ����>>" << endl << endl;
			int cnt = 0;
			for (int i = 0; i <= size; i++) {
				if (fileContent[i] == '0') {
					//C9A1
					ground[cnt++] = "��";
				}
				else if (fileContent[i] == '1') {
					ground[cnt++] = "��";
				}
				else if (fileContent[i] == '2') {
					ground[cnt++] = "  ";
				}
			}
			cout << cnt;
			for (int i = 0; i < GAMEPLAY_GROUND_HEIGHT; i++) {
				for (int j = 0; j < GAMEPLAY_GROUND_WIDTH; j++) {
					gotoXY(j*2, i + COORDINATE_TOP);
					cout << ground[i * GAMEPLAY_GROUND_WIDTH + j];
				}
			}
		}
	}
	else {
		//���� �о���� ����
		strcpy(fileContent, "������ ã�� �� �����ϴ�.");
		return;
	}
	

	//���� �÷��� �κ��� ��� ���� �ʱ�ȭ
	for (int i = 0; i < GAMEPLAY_GROUND_HEIGHT; i++) {
		for (int j = 0; j < GAMEPLAY_GROUND_WIDTH; j++) {
			item[i][j] = EMPTY;
		}
	}

	//�÷��̾��� ��ġ�� ����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	ground[playerY*GAMEPLAY_GROUND_WIDTH + playerX] = PLAYER_CHARACTER;
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
		ground[playerY * GAMEPLAY_GROUND_WIDTH + playerX] = ROAD;
		item[playerY][playerX] = EMPTY;
		gotoXY(playerX * 2, COORDINATE_TOP + playerY);
		cout << ground[playerY * GAMEPLAY_GROUND_WIDTH + playerX];
		if ((input == UP) && (ground[(playerY-1) * GAMEPLAY_GROUND_WIDTH + playerX] == ROAD|| ground[(playerY - 1) * GAMEPLAY_GROUND_WIDTH + playerX] == "��")) {
			playerY -= 1;
		}
		else if ((input == DOWN) && (ground[(playerY+1) * GAMEPLAY_GROUND_WIDTH + playerX] == ROAD || ground[(playerY + 1) * GAMEPLAY_GROUND_WIDTH + playerX] == "��")) { 
			playerY += 1;
		}
		else if ((input == LEFT) && (ground[playerY * GAMEPLAY_GROUND_WIDTH + playerX-1] == ROAD|| ground[playerY * GAMEPLAY_GROUND_WIDTH + playerX - 1] == "��")) {
			playerX -= 1;
		}
		else if ((input == RIGHT) && (ground[playerY * GAMEPLAY_GROUND_WIDTH + playerX+1] == ROAD|| ground[playerY * GAMEPLAY_GROUND_WIDTH + playerX + 1] == "��")) { 
			playerX += 1;
		}
		enemy.playerMoveSave(playerX, playerY);
		
		if (ground[playerY * GAMEPLAY_GROUND_WIDTH + playerX] == "��") { //�������µ� ������ �Ծ��ٸ�
			//�÷��̾��� ��ġ�� ������ �ִ� ��ġ���
			//�÷��̾ � ������ ������ �� ������ ��� ��ġ�� �ִ��� üũ.
			strcpy(mineral, mineralManager.MineralCheck(playerX, playerY)); //�� ��ġ�� �ִ� ������ �̸��� �޾ƿ´�.
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), EMPTY);
			gotoXY(0, 0);
			cout << "��Ȯ�� ����>>  " << mineral << "                                                       ";
			(*player).AddMineral(mineral); //�÷��̾�� �� ������ �߰��Ѵ�.
		}
		//�÷��̾ ������ ������ ����
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
		ground[playerY* GAMEPLAY_GROUND_WIDTH + playerX] = PLAYER_CHARACTER;
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
	enemy.Update(ground, &mineBool);

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
			if (ground[mineralY * GAMEPLAY_GROUND_WIDTH + mineralX] == ROAD) {
				ground[mineralY * GAMEPLAY_GROUND_WIDTH + mineralX] = "��";
				break;
			}
		} while (ground[mineralY * GAMEPLAY_GROUND_WIDTH + mineralX] != "��");

		//item(������ ��)�� �������� ������
		float randomItem = rand() % 10001; //0 ~ 10000
		if (randomItem <= (mineralPercentage[DARK_SKYBLUE]*100)) { item[mineralY][mineralX] = DARK_SKYBLUE; } //���� ����� ����
		else if (randomItem <= (mineralPercentage[DAKR_YELLOW] * 100)) { item[mineralY][mineralX] = DAKR_YELLOW; }
		else if (randomItem <= (mineralPercentage[DARK_GREEN] * 100)) { item[mineralY][mineralX] = DARK_GREEN; }
		else if (randomItem <= (mineralPercentage[DARK_RED] * 100)) { item[mineralY][mineralX] = DARK_RED; }
		else if (randomItem <= (mineralPercentage[DARK_VIOLET] * 100)) { item[mineralY][mineralX] = DARK_VIOLET; }
		else{ item[mineralY][mineralX] = DARK_BLUE; }

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