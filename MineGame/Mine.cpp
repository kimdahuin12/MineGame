#include "Mine.h"
Mine::Mine(const char* mineName, Player* player) {
	this->player = player;
	playerX = 0;
	playerY = 0;

	//���� �̸�
	this->mineName = new char[strlen(mineName) + 1];
	strcpy(this->mineName, mineName);
	cout << "��ο�" << endl;
	if (!strcmp(mineName, "�Ϲ� ����")) {
		produceMineralSec = 3;
		deleteMineralSec = 10;
		//���� ���� ���� Ȯ��.
		mineralPercentage[DARK_BLUE] = 45.0f;
		mineralPercentage[DARK_VIOLET] = 45.0f;
		mineralPercentage[DARK_RED] = 4.9f;
		mineralPercentage[DARK_GREEN] = 2.5f;
		mineralPercentage[DAKR_YELLOW] = 2.5f;
		mineralPercentage[DARK_SKYBLUE] = 0.1f;
		
	}
	else if (!strcmp(mineName, "�߱� ����")) {
		produceMineralSec = 4;
		deleteMineralSec = 8;
		mineralPercentage[DARK_BLUE] = 35.0f;
		mineralPercentage[DARK_VIOLET] = 35.0f;
		mineralPercentage[DARK_RED] = 23.5f;
		mineralPercentage[DARK_GREEN] = 3.0f;
		mineralPercentage[DAKR_YELLOW] = 3.0f;
		mineralPercentage[DARK_SKYBLUE] = 0.5f;
	}
	else if (!strcmp(mineName, "��� ����")) {
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
	//������ �����Ѵ�.

	gotoXY(0, 0);
	cout << "��Ȯ�� ����>>" << endl << endl;

	//���� �÷��� �κ��� ��� ���� �ʱ�ȭ
	for (int i = 0; i < GAMEPLAY_GROUND_HEIGHT; i++) {
		for (int j = 0; j < GAMEPLAY_GROUND_WIDTH; j++) {
			ground[i][j] = "  ";
			item[i][j] = EMPTY;
		}
	}

	//���� ����
	for (int i = -1; i < GAMEPLAY_GROUND_HEIGHT + 1; i++) {
		gotoXY((COORDINATE_LEFT - 1) * 2, COORDINATE_TOP + i); cout << "��";
		gotoXY((COORDINATE_LEFT + GAMEPLAY_GROUND_WIDTH) * 2, COORDINATE_TOP + i); cout << "��";
	}
	for (int i = -1; i < GAMEPLAY_GROUND_WIDTH + 1; i++) {
		gotoXY((COORDINATE_LEFT + i) * 2, COORDINATE_TOP - 1); cout << "��";
		gotoXY((COORDINATE_LEFT + i) * 2, COORDINATE_TOP + GAMEPLAY_GROUND_HEIGHT); cout << "��";
	}

	//�÷��̾��� ��ġ�� ����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	ground[playerY][playerX] = (*player).getCharacter();
	gotoXY((COORDINATE_LEFT + playerX) * 2, COORDINATE_TOP + playerY); //���� ��
	cout << (*player).getCharacter();

	prevTime_render = clock(); //�������� ���� �ð� üũ
}

int Mine::KeyInputRelated() {
	int input = _getch();
	if (input == 224) { //224�� ����Ű���� �˷��ִ� �ƽ�Ű�ڵ尪
		input = _getch();

		//������ �ڸ��� �ٽ� �ǵ�����.
		ground[playerY][playerX] = "  ";
		item[playerY][playerX] = EMPTY;
		gotoXY((COORDINATE_LEFT + playerX) * 2, COORDINATE_TOP + playerY);
		cout << ground[playerY][playerX];
		if ((input == UP) && ((playerY - 1) != -1)) { playerY -= 1; }
		else if ((input == DOWN) && ((playerY + 1) != GAMEPLAY_GROUND_HEIGHT)) { playerY += 1; }
		else if ((input == LEFT) && ((playerX - 1) != -1)) { playerX -= 1; }
		else if ((input == RIGHT) && ((playerX + 1) != GAMEPLAY_GROUND_WIDTH)) { playerX += 1; }

		if (strcmp(ground[playerY][playerX], "��") == 0) { //�������µ� ������ �Ծ��ٸ�
			//�÷��̾��� ��ġ�� ������ �ִ� ��ġ���
			//�÷��̾ � ������ ������ �� ������ ��� ��ġ�� �ִ��� üũ.
			strcpy(mineral, mineralManager.MineralCheck(playerX, playerY)); //�� ��ġ�� �ִ� ������ �̸��� �޾ƿ´�.
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), EMPTY);
			gotoXY(0, 0);
			cout << "��Ȯ�� ����>>  " << mineral << "                              ";
			(*player).AddMineral(mineral); //�÷��̾�� �� ������ �߰��Ѵ�.
		}
		//�÷��̾ ������ ������ ����
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
		ground[playerY][playerX] = (*player).getCharacter();
		item[playerY][playerX] = EMPTY;
		gotoXY((COORDINATE_LEFT + playerX) * 2, COORDINATE_TOP + playerY);
		cout << ground[playerY][playerX];
	}
	return input;
}


char* Mine::randomMineral(int mineralItem) {
	//������ ���� ���� ������ �������� �����Ѵ�.
	int randomIdx;
	char* res_mineralName;
	//srand(time(NULL));�� ���ο�..
	switch (mineralItem) {
	case 1:
		//DARK_BLUE

		//���� �ε��� ����
		randomIdx = 1;//rand() % BlueMineralCount; // �Ķ��� ������ ���� ���̿��� �����ϰ� ����

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

	currentTime_render = clock(); //���� �ð�

	renderTimeCheck = (currentTime_render - prevTime_render) / CLOCKS_PER_SEC; //������ �ð�

	if (renderTime <= renderTimeCheck) {
		//������ �ð��� ������(ó���� 3��) ������ �Ѵ�.
		renderTime = rand() % produceMineralSec + 1;//1 ~ produceMineralSec�� ������ ������ ����
		prevTime_render = clock();

		//����
		//x, y���� �����ϰ� item�� ���� ������ ������ �ϸ� ��ȣ�� ���� ���� �ο���.
		//�׸��� ground�� ���� ����� �� �� ���Ǵ� ����
		mineralX = rand() % GAMEPLAY_GROUND_WIDTH;
		mineralY = rand() % GAMEPLAY_GROUND_HEIGHT;
		ground[mineralY][mineralX] = "��";

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
		renderTime_delete = rand() % deleteMineralSec + 5;//5 ~ deleteMineralSec+4�� ������ ������ ����
		prevTime_render_delete = clock(); //���� �ð��� ���

		//������ ������ ����
		mineralManager.RandomMineralDel(ground, item);
	}
}

void Mine::Render() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), item[mineralY][mineralX]);
	gotoXY((COORDINATE_LEFT + mineralX) * 2, COORDINATE_TOP + mineralY);
	cout << ground[mineralY][mineralX];
}