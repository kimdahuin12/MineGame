#define _CRT_SECURE_NO_WARNINGS
#include "MysqlDatabase.h"
#include "global.h"
#include "gameGlobal.h"

#include "Player.h"

#include "MyItem.h"
#include "Mine.h"

//db�� ������
//���� ���̺�
//(���� �̸�, ���� ����)
//����

//�ʿ� ��ֹ��� �߰��� �ȴ�.
//������ �� �߰�����
//���꿡 ���� ����� �ٸ��� �ϰ� �ʹ�.
//

//

//�Լ� ����
char* fileRead(string fileName);
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

//Ŭ���� ����
Player player;
Mine* mine = nullptr; 

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

//database

void data_select(const char* tableName) {
	
}
// https://kiffblog.tistory.com/151
int main() {

	////â �ִ�
	//HWND hwnd = GetForegroundWindow();
	//int cx = GetSystemMetrics(SM_CXSCREEN);            /* Screen width pixels */
	//int cy = GetSystemMetrics(SM_CYSCREEN);            /* Screen Height Pixel */
	//LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);   /* Get window information */
	///* Set window information to maximize the removal of title bar and border*/
	//SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
	//SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
	//â ũ��
	system("mode con: cols=160 lines=40");
	system("title MIneGame");
	////����
	//openBgm.lpstrElementName = L"D:\\cppProject\\playGame\\Debug\\sound\\bgSound.wav"; //���� ����
	//openBgm.lpstrDeviceType = L"mpegvideo"; //mp3 ����
	//mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm);
	//dwID = openBgm.wDeviceID;
	//mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&openBgm); //���� �ݺ� ���
	////���� END

	//����(Ŀ��)�� ������ �ʰ� ���ִ� �Լ�.
	cursorVisibleFalse();

	int sel; //���ÿ� ����
	int selX;
	int selY;
	
	while (true) {
		//�Ʒ��� ���� �� �� �ִ� �׷�..
		//x, y ��ǥ�� �������ָ� ���� 2�� ���ʴ�� ���� �� �ֵ��� ������ ���ڴ�.
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
			//ȸ������. (ȸ������ �� DB�� �����ϴ� �Լ�)
			//MysqlDatabase::create_account("playeraccount");
			MysqlDatabase::create_account(&player);
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
			MysqlDatabase::ranking_print();
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

char* fileRead(string fileName) {

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
		fileContent = new char[size+1];
		for (int i = 0; i < size + 1; i++) { fileContent[i] = 0; }

		//������ �� ó�� ��ġ�� �̵�
		readFile.seekg(0, ios::beg);

		//������ ��ü ������ fileContent�� ����
		readFile.read(&fileContent[0], size);

		//�̺κ��� ���� ���� �ؽ�Ʈ �̹����� ���� �κ��̴�.
		//���� ����ų� ���θ� �����ؼ� �ص� �� �� ����
		if (true) {
			for (int i = 0; i < size + 1; i++) {
				if (fileContent[i] == '0') {
					fileContent[i] = 'O';
				}
				else if (fileContent[i] == '1') {
					fileContent[i] = 'I';
				}
				else if (fileContent[i] == '2') {
					fileContent[i] = ' ';
				}
			}
		}
	}
	else {
		//���� �о���� ����
		strcpy(fileContent, "������ ã�� �� �����ϴ�.");
	}


	//fileContent()

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
			player.Inventory();
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



void GameInit() {
	
	cursorVisibleFalse(); //Ŀ�� �Ⱥ��̰� �ϱ�
	srand(time(NULL)); //������ �����ϰ� �߻���Ű��

	mine->MineInit();


}

void GoMining()
{
	//��� ���꿡 ����
	int sel; //���ÿ� ����
	int selX;
	int selY;

	while (true) {
		selX = 57; selY = 12;

		gotoXY(selX, selY);
		cout << "> 1. �Ϲ� ����" << endl;
		gotoXY(selX, selY + 2);
		cout << "  2. �߱� ����" << endl;
		gotoXY(selX, selY + 4);
		cout << "  3. ��� ����" << endl;
		gotoXY(selX, selY + 6);
		cout << "  4. �׽�Ʈ1 ����" << endl;
		gotoXY(selX, selY + 8);
		cout << "  5. �׽�Ʈ2 ����" << endl;
		gotoXY(selX, selY + 10);
		cout << "  6. ������" << endl;
		gotoXY(35, 12 + 22);
		cout << "���� (SpaceBar) >> ";
		gotoXY(55, 12 + 24);
		cout << '1'; sel = 1;
		//�޴� ���� ���� �̵��� �޴� ���� ��ȣ ������Ʈ ����
		int keyCheck = -1;
		while (keyCheck != 32) { //�����̽��ٰ� ������ ������ ��� ���Ʒ� ������ �̵��ϸ� sel�� ������Ʈ�Ѵ�.
			keyCheck = _getch();
			if (keyCheck == 224) { //����Ű�� 224 -> ����Ű UP, DOWN.�� üũ�� ���̴�.
				keyCheck = _getch();
				switch (keyCheck) {
				case UP:
					if (selY > 12) { //12�� ���� ���� ��ġ�̹Ƿ� y���� �� Ŀ�� ���� �ö� �� ����
						gotoXY(selX, selY); cout << "  "; //���� �ڸ� ����
						gotoXY(selX, selY -= 2); cout << "> "; //�̵��ϱ�
					}
					break;
				case DOWN:
					if (selY < 12 + 12) { //12+12�� ���� �Ʒ� ��ġ�̹Ƿ� �� �۾ƾ� �Ʒ��� ������ �� ����.
						gotoXY(selX, selY); cout << "  ";
						gotoXY(selX, selY += 2); cout << "> ";
					}
					break;
				}
				//���Ʒ� �����ӿ� ���� ���� ���� ��ȣ ǥ�� & sel ������Ʈ
				gotoXY(55, 34);
				switch (selY) {
				case 12: cout << '1'; sel = 1; break;
				case 14: cout << '2'; sel = 2; break;
				case 16: cout << '3'; sel = 3; break;
				case 18: cout << '4'; sel = 4; break;
				case 20: cout << '5'; sel = 5; break;
				case 22: cout << '6'; sel = 6; break;
				}
			}
		}
		cout << endl;
		//�޴� ���� ���� �̵��� �޴� ���� ��ȣ ������Ʈ ���� END
		if (sel == 6) {
			playingShuffleSound();
			return; 
		}
		//�� �� �ִ��� Ȯ��
		char* mineName = player.MineAuthorityCheck(sel);

		if (mineName == nullptr) {
			system("pause"); system("cls"); playingShuffleSound();
			gotoXY(50, 50);
			cout << "�� �� ���� ����" << endl;
			system("pause"); system("cls");
		}
		else {
			//���� ����
			mine = new Mine(mineName, &player);
			break;
		}
	}
	system("pause"); system("cls");

	GameInit();
	while (true) {
		//Ű �Է�, ������ ���� ����
		if (_kbhit() != 0) {//_kbhit()�� Ű���尡 ���ȴ��� üũ���ִ� �Լ��̴�. ������ 0 �̿��� ���� ����
			int input = mine->KeyInputRelated();//Ű ���� ó���� �ϰ� �Էµ� ���� ��ȯ���ش�.
			if (input == 27) {
				delete mine;
				break;
			}//esc�� ������ �޴��� �̵�
			//Ű �Է�, ������ ���� ���� END
		}
		else if (!mine->mineBool) {
			//���� ����
			delete mine;
			break;
		}
		else {
			mine->Update();
			mine->Render();
		}
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), EMPTY);
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


void cursorVisibleFalse() {
	//������ ������ �ʰ� �ϴ� �ڵ�
	CONSOLE_CURSOR_INFO cif;
	cif.dwSize = 1;
	cif.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cif);
	//END
}

//�Լ� ���� END
