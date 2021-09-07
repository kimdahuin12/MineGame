#include "global.h"
#include "UserAccount.h"
	//#include <my_global.h>
	//#include <mysql.h>

#include <thread> //������
#include <conio.h>//Ű �Է� ���� ���

//db����
//#pragma comment(lib, "libmySQL.lib")

//�Լ� ����
string fileRead(string fileName);
void StartGame();
void GoMining();
//void PlayerMove();
void CreateAccount();
void LogIn();
void LogOut();
void Destroy();
void gotoXY(int x, int y);
void cursorVisibleFalse();
void Update();
void Render();


//����
MCI_OPEN_PARMS openBgm;
MCI_PLAY_PARMS playBgm;
MCI_OPEN_PARMS openShuffleSound;
MCI_PLAY_PARMS playShuffleSound;

int dwID;
void playingShuffleSound(void) {
	//ȿ����
	openShuffleSound.lpstrElementName = L"D:\\cppProject\\playGame\\Debug\\sound\\click.wav"; //���� ����
	openShuffleSound.lpstrDeviceType = L"mpegvideo"; //mp3 ����
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openShuffleSound);
	dwID = openShuffleSound.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openShuffleSound); //������ �� �� ���
	Sleep(50); //ȿ������ ����� ������ �����ߴٰ�
	mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //���� ��� ��ġ�� ó������ �ʱ�ȭ
}
//���� END

//key�Է� �ƽ�Ű�ڵ�
//224 -> KEYBOARD

enum KEYBOARD {
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80

};

//key�Է� enum END

// https://kiffblog.tistory.com/151
int main() {

	//â ũ��
	system("mode con: cols=180 lines=40");
	system("title ����");

	//����
	//openBgm.lpstrElementName = L"D:\\cppProject\\playGame\\Debug\\sound\\bgSound.wav"; //���� ����
	//openBgm.lpstrDeviceType = L"mpegvideo"; //mp3 ����
	//mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm);
	//dwID = openBgm.wDeviceID;
	//mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&openBgm); //���� �ݺ� ���
	//���� END

	//����(Ŀ��)�� ������ �ʰ� ���ִ� �Լ�.
	cursorVisibleFalse();

	int sel; //���ÿ� ����
	int selX;
	int selY;

	while (true) {
		selX = 57;
		selY = 12;
		cout << endl;
		gotoXY(55, 8);
		cout << "----------------------------Menu----------------------------" << endl;
		gotoXY(selX, selY);
		cout << "> 1. ���� ����" << endl;
		gotoXY(selX, selY + 2);
		cout << "  2. �α���" << endl;
		gotoXY(selX, selY + 4);
		cout << "  3. �÷��̾� ����" << endl;
		gotoXY(selX, selY + 6);
		cout << "  4. ����" << endl;
		gotoXY(selX, selY + 8);
		cout << "  5. ����" << endl;
		gotoXY(55, 24);
		cout << "--------------------------------------------------------------" << endl << endl;
		gotoXY(55, 28);
		cout << "���� (SpaceBar) >> ";
		gotoXY(75, 28);
		cout << '1';
		sel = 1;
		//�޴� ���� ���� �̵��� �޴� ���� ��ȣ ������Ʈ ����
		int keyCheck = -1;
		while (keyCheck != 32) { //�����̽��ٰ� ������ ������ ��� ���Ʒ� ������ �̵��ϸ� sel�� ������Ʈ�Ѵ�.
			keyCheck = _getch();
			if (keyCheck == 224) { //����Ű�� 224 -> ����Ű UP, DOWN. �̷���
				keyCheck = _getch();
				switch (keyCheck) {
				case UP:
					if (selY > 12) { //12�� ���� ���� ��ġ�̹Ƿ� y���� �� Ŀ�� ���� �ö� �� ����
						gotoXY(selX, selY); cout << "  "; //���� �ڸ� ����
						gotoXY(selX, selY -= 2); cout << "> "; //�̵��ϱ�
					}
					break;
				case DOWN:
					if (selY < 20) { //20�� ���� �Ʒ� ��ġ�̹Ƿ� �� �۾ƾ� �Ʒ��� ������ �� ����.
						gotoXY(selX, selY); cout << "  ";
						gotoXY(selX, selY += 2); cout << "> ";
					}
					break;
				}
				//���Ʒ� �����ӿ� ���� ���� ���� ��ȣ ǥ�� & sel ������Ʈ
				gotoXY(75, 28);
				switch (selY) {
				case 12: cout << '1'; sel = 1; break;
				case 14: cout << '2'; sel = 2; break;
				case 16: cout << '3'; sel = 3; break;
				case 18: cout << '4'; sel = 4; break;
				case 20: cout << '5'; sel = 5; break;
				}
			}
		}
		cout << endl;
		//�޴� ���� ���� �̵��� �޴� ���� ��ȣ ������Ʈ ���� END

		switch (sel) {
		case 1:
			system("pause"); system("cls"); playingShuffleSound(); cout << endl;
			CreateAccount();
			cout << endl; system("pause"); system("cls");
			break;
		case 2:
			system("pause"); system("cls"); playingShuffleSound(); cout << endl;
			//�α��� �����ϸ� ���� ����
			LogIn();
			StartGame();
			LogOut();
			cout << endl; system("pause"); system("cls");
			break;
		case 3:
			system("pause"); system("cls"); playingShuffleSound(); cout << endl;
			//allAccountSearch();
			cout << endl; system("pause"); system("cls");
			break;
		case 4:
			system("pause"); system("cls"); playingShuffleSound(); cout << endl;
			//ȿ���� ���� �ѱ�, ������� ���� �ѱ�
			setting();
			cout << endl; system("pause"); system("cls");
			break;
		case 5:
			system("pause"); system("cls"); playingShuffleSound(); cout << endl;
			Destroy();
			return 0;
		default:
			cout << endl;
			system("pause"); system("cls"); playingShuffleSound();
		}

	}


	return 0;
}

//�Լ� ����
//

string fileRead(string fileName) {

	//���� �ҷ�����
	fstream readFile(fileName);
	string fileContent;

	if (readFile.is_open()) {
		//���� �о���� ����

		//�ǳ����� ��ġ �̵�
		readFile.seekg(0, ios::end);

		//�� ó�� ��ġ���� ������ġ(���� �� ��)������ ũ�⸦ ��ȯ
		int size = readFile.tellg();

		//size��ŭ ���ڿ��� ������ ������
		fileContent.resize(size);

		//������ �� ó�� ��ġ�� �̵�
		readFile.seekg(0, ios::beg);

		//������ ��ü ������ fileContent�� ����
		readFile.read(&fileContent[0], size);
	}
	else {
		//���� �о���� ����
		fileContent = "������ ã�� �� �����ϴ�.";
	}

	return fileContent;
}

//MINEGAME ����
void StartGame()
{
	//file�� �ҷ��ͼ� ����ȭ�� ����.
	string startScreen = fileRead("gameStartTextImage.txt");
	cout << startScreen;

	system("pause");
	system("cls");
	playingShuffleSound();

	int sel; //���ÿ� ����
	int selX;
	int selY;

	while (true) {

		selX = 57;
		selY = 12;
		cout << endl;
		gotoXY(55, 8);
		cout << "-------------------------MineGameTown-------------------------" << endl;
		gotoXY(selX, selY);
		cout << "> 1. ���� ��Ȯ" << endl;
		gotoXY(selX, selY + 2);
		cout << "  2. ����" << endl;
		gotoXY(selX, selY + 4);
		cout << "  3. �� ����" << endl;
		gotoXY(selX, selY + 6);
		cout << "  4. ���� ������" << endl;
		gotoXY(55, 22);
		cout << "--------------------------------------------------------------" << endl << endl;
		gotoXY(55, 24);
		cout << "���� (SpaceBar) >> ";
		gotoXY(75, 24);
		cout << '1';
		sel = 1;
		//�޴� ���� ���� �̵��� �޴� ���� ��ȣ ������Ʈ ����
		int keyCheck = -1;
		while (keyCheck != 32) { //�����̽��ٰ� ������ ������ ��� ���Ʒ� ������ �̵��ϸ� sel�� ������Ʈ�Ѵ�.
			keyCheck = _getch();
			if (keyCheck == 224) { //����Ű�� 224 -> ����Ű UP, DOWN. �̷���
				keyCheck = _getch();
				switch (keyCheck) {
				case UP:
					if (selY > 12) { //12�� ���� ���� ��ġ�̹Ƿ� y���� �� Ŀ�� ���� �ö� �� ����
						gotoXY(selX, selY); cout << "  "; //���� �ڸ� ����
						gotoXY(selX, selY -= 2); cout << "> "; //�̵��ϱ�
					}
					break;
				case DOWN:
					if (selY < 18) { //18�� ���� �Ʒ� ��ġ�̹Ƿ� �� �۾ƾ� �Ʒ��� ������ �� ����.
						gotoXY(selX, selY); cout << "  ";
						gotoXY(selX, selY += 2); cout << "> ";
					}
					break;
				}
				//���Ʒ� �����ӿ� ���� ���� ���� ��ȣ ǥ�� & sel ������Ʈ
				gotoXY(75, 24);
				switch (selY) {
				case 12: cout << '1'; sel = 1; break;
				case 14: cout << '2'; sel = 2; break;
				case 16: cout << '3'; sel = 3; break;
				case 18: cout << '4'; sel = 4; break;
				}
			}
		}
		cout << endl;
		//�޴� ���� ���� �̵��� �޴� ���� ��ȣ ������Ʈ ���� END

		switch (sel) {
		case 1:
			system("cls"); playingShuffleSound(); cout << endl;
			GoMining();
			cout << endl; system("cls");
			break;
		case 2:
			system("pause"); system("cls"); playingShuffleSound(); cout << endl;
			//Market();
			cout << endl; system("pause"); system("cls");
			break;
		case 3:
			system("pause"); system("cls"); playingShuffleSound(); cout << endl;
			//MyInfo
			cout << endl; system("pause"); system("cls");
			break;
		case 4:
			cout << endl; system("pause"); system("cls"); playingShuffleSound();
			cout << "�޴� ȭ������ �̵��մϴ�." << endl;
			return;
		default:
			cout << endl;
			system("pause"); system("cls"); playingShuffleSound();
		}

	}

}

enum COLOR {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VOILET,
	DAKR_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	EMPTY,
};

string ground[35][70]; //
int item[35][70];
int playerX = 0;
int playerY = 0;
int input = 0;

//��..

//void PlayerMove()
//{
//	//������ ������ �ʰ� �ϴ� �ڵ�
//	CONSOLE_CURSOR_INFO cif;
//	cif.dwSize = 1;
//	cif.bVisible = FALSE;
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cif);
//	//END
//	srand(time(NULL));
//	while (true) {
//		if (input == 27)break;
//		system("cls"); cout << endl;
//		cout << "��Ȯ�� ����>>" << "����" << endl << endl;
//
//		for (int i = 0; i < 35; i++) {
//			for (int j = 0; j < 70; j++) {
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), item[i][j]);
//				cout << ground[i][j];
//			}
//			cout << endl;
//		}
//
//		Sleep((rand() % 4001) + 1000);//1~5������ ������ ���� ���� + ȭ�� ����
//		int x = rand() % 70;
//		int y = rand() % 35;
//		ground[y][x] = "��";
//		//
//		item[y][x] = (rand() % 6)+1; //1~6
//
//	
//	}
//}
char mine[30] = "���� 1";
clock_t prevTime_render;
clock_t currentTime_render;
int renderTime = 3;
int renderTimeCheck;
void GoMining()
{
	cursorVisibleFalse(); //Ŀ�� �Ⱥ��̰� �ϱ�
	srand(time(NULL)); //������ �����ϰ� �߻���Ű��


	for (int i = 0; i < 35; i++) {
		for (int j = 0; j < 70; j++) {
			ground[i][j] = "  ";
			item[i][j] = EMPTY;
		}
	}
	prevTime_render = clock(); //�������� ���� �ð� üũ
	while (true) {
		//Ű �Է�, ������ ���� ����
		if (_kbhit() != 0) {//_kbhit()�� Ű���尡 ���ȴ��� üũ���ִ� �Լ��̴�. ������ 0 �̿��� ���� ����
			input = _getch();
			if (input == 224) {
				input = _getch();
				if ((input == UP) && ((playerY - 1) != -1)) { ground[playerY][playerX] = "  "; playerY--; }
				else if ((input == DOWN) && ((playerY + 1) != 35)) { ground[playerY][playerX] = "  "; playerY++; }
				else if ((input == LEFT) && ((playerX - 1) != -1)) { ground[playerY][playerX] = "  "; playerX--; }
				else if ((input == RIGHT) && ((playerX + 1) != 70)) { ground[playerY][playerX] = "  "; playerX++; }
			}
			if (input == 27)break; //esc�� ������ �޴��� �̵�
			//Ű �Է�, ������ ���� ���� END
		}
		else {
			Update();
			Render();
		}
	}

}

void Update()
{
	currentTime_render = clock();

	renderTimeCheck = (currentTime_render - prevTime_render) / CLOCKS_PER_SEC;

	if (renderTime <= renderTimeCheck) {
		//������ �ð��� ������(ó���� 3��) ������ �Ѵ�.
		renderTime = rand() % 10;//0 ~ 9�� ������ ������ ����
		prevTime_render = clock();

		//����
		//x, y���� �����ϰ� item�� ���� ������ ������ �ϸ� ��ȣ�� ���� ���� �ο���.
		//�׸��� ground�� ���� ����� �� �� ���Ǵ� ����
		int x = rand() % 70;
		int y = rand() % 35;
		ground[y][x] = "��";
		item[y][x] = (rand() % 6) + 1; //1~6

	}


	//� ������ ������ ��Ȯ�� ������ �̸��� ����
	//
}
void Render()
{
	//��� ����
	system("cls");
	cout << endl;
	cout << "��Ȯ�� ����>>" << mine << endl << endl;
	strcpy(mine, "���� 2");

	item[playerY][playerX] = YELLOW;
	ground[playerY][playerX] = "��";

	for (int i = 0; i < 35; i++) {
		for (int j = 0; j < 70; j++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), item[i][j]);
			cout << ground[i][j];
		}
		cout << endl;
	}
	//��� ���� END
}


//ȸ������.
void CreateAccount() {

	//���̵�� �ִ� 20����, �ѱ�X, ��� ���ڸ��� �̿��Ͽ� �����
	//��й�ȣ�� ��� ���ڸ��� �̿��Ͽ� ����� �ִ� 20

	char id[50];
	char pw[50];
	bool idAndPwCheck;

	while (true) {
		idAndPwCheck = true;

		cout << "--------ȸ������--------" << endl << endl;
		cout << "���̵�, ��й�ȣ�� ��� ���� �ҹ��ڿ� ���ڸ��� �̿��Ͽ� ���� �� ������\n�ִ� 50�ڱ��� ���� �����մϴ�." << endl << endl;
		cout << "���̵� �Է� : "; cin >> id;
		cout << "��й�ȣ �Է� : "; cin >> pw;

		//id üũ
		for (int i = 0; id[i] != NULL; i++) {
			if ((id[i] < 'a' || id[i] > 'z') && (id[i] < '0' || id[i] > '9')) { idAndPwCheck = false; break; }
		}
		//pwüũ
		for (int i = 0; pw[i] != NULL; i++) {
			if ((pw[i] < 'a' || pw[i] > 'z') && (pw[i] < '0' || pw[i] > '9')) { idAndPwCheck = false; break; }
		}

		//��� �� �Է��ϸ� while END
		if (idAndPwCheck == true) { break; }

		system("cls"); cout << endl;
		cout << "���̵�� ��й�ȣ�� ���� �ҹ��ڿ� ���ڸ��� �̿��ؼ� ����� �ּ���." << endl << endl;
		system("pause"); system("cls");

	}
	//while END

	int sel; //���ÿ� ����

	while (true) {

		system("pause"); system("cls"); playingShuffleSound();
		cout << "������ �����Ͻðڽ��ϱ�?" << endl << endl;
		cout << "1. ��" << endl;
		cout << "2. �ƴϿ�" << endl << endl;
		cout << "��ȣ ���� >> "; cin >> sel;

		switch (sel) {
		case 1:
			system("pause"); system("cls"); playingShuffleSound(); cout << endl;
			cout << "������ �����˴ϴ�." << endl;
			break;
			cout << endl; system("pause"); system("cls");
		case 2:
			system("pause"); system("cls"); cout << endl;
			cout << "���� ȭ������ ���ư��ϴ�." << endl;
			playingShuffleSound();
			return;
		default:
			cout << endl; system("pause"); system("cls"); playingShuffleSound();
		}

		if (sel == 1) break;
	}
	//while END

	//���� ����
	cout << "id: " << id << endl;
	cout << "pw: " << pw << endl;
	UserAccount accountCreate(id, pw);
	//db�� ���� ����(userId)
	cout << "���� ���� �Ϸ�" << endl;
}

////�α���
void LogIn()
{

	//db�ҷ��ͼ� ���� ���̵�� ����� ������ ��� �������� �����Ѵ�.
	//������ ������ �̿��Ͽ� ��ü �����.


}

//����� �޸� ����
void LogOut()
{

}

//������ ����Ǳ� �� �޸� ���� ���� �ϴ� �Լ�
void Destroy()
{
	//������ ����

	cout << "������ ����˴ϴ�." << endl;
	Sleep(300);
	cout << "�ȳ��� ���ʽÿ�." << endl;
	Sleep(300);

	//�޸𸮵� ����

}

void gotoXY(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void cursorVisibleFalse() {
	//������ ������ �ʰ� �ϴ� �ڵ�
	CONSOLE_CURSOR_INFO cif;
	cif.dwSize = 1;
	cif.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cif);
	//END
}

//�Լ� ���� END
