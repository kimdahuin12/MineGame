#define _CRT_SECURE_NO_WARNINGS
#include "MysqlDatabase.h"
#include "global.h"

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
void fileReadAndPrint(string fileName);
void StartGame();
void GoMining();
//void PlayerMove();
void LogOut();
void Destroy();
void cursorVisibleFalse();

//Ŭ���� ����
Player* player;
Mine* mine = nullptr; 

// https://kiffblog.tistory.com/151
int main() {
	//â ũ��
	system("mode con: cols=160 lines=40");
	system("title MIneGame");
	
	soundPlay(); //���� ���

	//����(Ŀ��)�� ������ �ʰ� ���ִ� �Լ�.
	cursorVisibleFalse();

	int sel; //���ÿ� ����
	int selX;
	int selY;
	
	cout << "test" << endl;

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
		case 1:														//ȸ������
			reverseScene();
			//ȸ������. (ȸ������ �� DB�� �����ϴ� �Լ�)
			MysqlDatabase::create_account();
			reverseScene();
			break;
		case 2:														//�α���
			reverseScene();
			//�α��� �����ϸ� ���� ����
			char id[50];
			unsigned long money;
			StartGame();
			//if (MysqlDatabase::login(id, money)) { //�α����� �ߴٸ� �α��ε� ���̵�� money ������ true, �ƴϸ� false�� return 
			//	//�α��� ����
			//	player = new Player(id, money);
			//	MysqlDatabase::playerInit(player); //�÷��̾� ������, ��, ��� �����ϱ�
			//	StartGame();
			//	LogOut();
			//}
			break;
		case 3:														//��ŷ
			reverseScene();
			MysqlDatabase::ranking_print();
			reverseScene();
			break;
		case 4:														//����
			system("pause"); system("cls"); playingShuffleSound(); cout << endl;
			//ȿ���� ���� �ѱ�, ������� ���� �ѱ�
			setting();
			cout << endl; system("pause"); system("cls");
			break;
		case 5:														//����
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

void fileReadAndPrint(string fileName) {

	//���� �ҷ�����
	fstream readFile(fileName);
	char* fileContent = nullptr;

	if (readFile.is_open()) {
		//���� �о���� ����

		//�ǳ����� ��ġ �̵�
		readFile.seekg(0, ios::end);
		//�� ó�� ��ġ���� ������ġ(���� �� ��)������ ũ�⸦ ��ȯ
		int size = readFile.tellg();
		size -= 40;
		//size��ŭ ���ڿ��� ������ ������
		fileContent = new char[size + 1];
		//������ �� ó�� ��ġ�� �̵�
		readFile.seekg(0, ios::beg);
		//������ ��ü ������ fileContent�� ����
		readFile.read(&fileContent[0], size);
		//�̺κ��� ���� ���� �ؽ�Ʈ �̹����� ���� �κ��̴�.
		if (true) {
			gotoXY(0, 0);
			int cnt = 0;
			for (int i = 0; i <= size; i++) {
				if (fileContent[i] == '0') {
					//C9A1
					cout << "��";
				}
				else if (fileContent[i] == 'o') {
					//C9A1
					cout << "  ";
				}
				else {
					cout << fileContent[i];
				}
			}

		}
	}
	else {
		//���� �о���� ����
		strcpy(fileContent, "������ ã�� �� �����ϴ�.");
	}
	readFile.close();
}

//MINEGAME ����
void StartGame()
{
	int sel; //���ÿ� ����
	int selX;
	int selY;

	while (true) {
		fileReadAndPrint("gameStartTextImage.txt");
		selX = 57;
		selY = 12;
		cout << endl;
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
				sel = (selY - 10) / 2;
			}
		}
		cout << endl;
		//�޴� ���� ���� �̵��� �޴� ���� ��ȣ ������Ʈ ���� END

		switch (sel) {
		case 1:															//���� ����
			reverseScene();
			GoMining();
			cout << endl; system("cls");
			break;
		case 2:															//����
			reverseScene();
			//MysqlDatabase::Market(*player);
			reverseScene();
			break;
		case 3:															//�κ��丮
			reverseScene();
			//MyInfo
			player->Inventory();
			reverseScene();
			break;
		case 4:															//�α׾ƿ�
  			reverseScene();
			//�α׾ƿ� �� �޴�ȭ������ �̵�
			//MysqlDatabase::playerMoneySave(player->getMoney(), player->getId());
			//MysqlDatabase::playerMineralSave(player->getInventory(), player->getItemCount(), player->getId()); //������ ������ db�� ����
			//delete player;
			cout << "�޴� ȭ������ �̵��մϴ�." << endl;
			reverseScene();
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
		cout << "> 1. �Ϲ� ���� - ������ :5,000��" << endl;
		gotoXY(selX, selY + 2);
		cout << "  2. �߱� ���� - ������ :10,000��" << endl;
		gotoXY(selX, selY + 4);
		cout << "  3. ��� ���� - ������ :50,000��" << endl;
		gotoXY(selX, selY + 6);
		cout << "  4. �׽�Ʈ1 ���� - ������ :100,000��" << endl;
		gotoXY(selX, selY + 8);
		cout << "  5. �׽�Ʈ2 ���� - ������ :150,000��" << endl;
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
				sel = (selY - 10) / 2; //������ ��ȣ
				
			}
		}
		cout << endl;
		//�޴� ���� ���� �̵��� �޴� ���� ��ȣ ������Ʈ ���� END
		if (sel == 6) {
			playingShuffleSound();
			return; 
		}
		//�� �� �ִ��� Ȯ��

		//�� ��ȣ�� �°� db���� ��ȸ�ؼ� �ʿ��� ������ ������ �����´�.
 	//	int mineral_condision = MysqlDatabase::MineralCondition(sel);

  //		if (player->MineAuthorityCheck(mineral_condision) && player->decreaseMoney(MysqlDatabase::GetEntrancePrice(sel))) {
		//	//���꿡 �� �� �ִٸ�
		//	//Mine��ü�� ����� �ʱ�ȭ
		//	mine = nullptr;
		//	mine = new Mine(player, sel);
		//	MysqlDatabase::MineInfoSave(*mine, sel);			//db���� mine�� ������ �ҷ��ͼ� mine��ü�� ������ ����

		//	break;
		//}
		//else {
		//	//���꿡 �� �� ���ٸ�
		//	reverseScene();
		//	gotoXY(50, 50);
		//	cout << "�� �� ���� ����" << endl;
		//	reverseScene();
		//}


		mine = nullptr;
		mine = new Mine(player, sel);
		char* name = new char[strlen("�Ϲ� ����") + 1];
		strcpy(name, "�Ϲ� ����");
		mine->SetMineInfo(name, 1, 1, new float[6]{0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f});
		break;
		//price
	//name
	//produce
	//delete
	//percentageS

	}
	reverseScene();

	GameInit();
	while (true) {
		//Ű �Է�, ������ ���� ����
		if (_kbhit() != 0) {//_kbhit()�� Ű���尡 ���ȴ��� üũ���ִ� �Լ��̴�. ������ 0 �̿��� ���� ����
			int input = mine->KeyInputRelated();//Ű ���� ó���� �ϰ� �Էµ� ���� ��ȯ���ش�.
			if (input == 27) {
				break;
			}//esc�� ������ �޴��� �̵�
			//Ű �Է�, ������ ���� ���� END
		}
		else if (!mine->mineBool) {
			break;
		}
		else {
			mine->Update();
			mine->Render();
		}
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), EMPTY);
}

//����� �޸� ����
void LogOut()
{

}

//������ ����Ǳ� �� �޸� ���� ���� �ϴ� �Լ�
void Destroy()
{
	//������ ����
	delete mine;
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
