#include "global.h"
#include "UserAccount.h"
	//#include <my_global.h>
	//#include <mysql.h>

#include <conio.h>//키 입력 관련 헤더

//db연동
//#pragma comment(lib, "libmySQL.lib")

//함수 선언
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



//음악
MCI_OPEN_PARMS openBgm;
MCI_PLAY_PARMS playBgm;
MCI_OPEN_PARMS openShuffleSound;
MCI_PLAY_PARMS playShuffleSound;

int dwID;
void playingShuffleSound(void) {
	//효과움
	openShuffleSound.lpstrElementName = L"D:\\cppProject\\playGame\\Debug\\sound\\click.wav"; //파일 오픈
	openShuffleSound.lpstrDeviceType = L"mpegvideo"; //mp3 형식
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openShuffleSound);
	dwID = openShuffleSound.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openShuffleSound); //음악을 한 번 재생
	Sleep(50); //효과음이 재생될 때까지 정지했다가
	mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
}
//음악 END

//key입력 아스키코드
//224 -> KEYBOARD

enum KEYBOARD {
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80

};

//key입력 enum END

// https://kiffblog.tistory.com/151
int main() {

	//창 크기
	system("mode con: cols=180 lines=40");
	system("title MIneGame");

	//음악
	//openBgm.lpstrElementName = L"D:\\cppProject\\playGame\\Debug\\sound\\bgSound.wav"; //파일 오픈
	//openBgm.lpstrDeviceType = L"mpegvideo"; //mp3 형식
	//mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm);
	//dwID = openBgm.wDeviceID;
	//mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&openBgm); //음악 반복 재생
	//음악 END

	//밑줄(커서)가 보이지 않게 해주는 함수.
	cursorVisibleFalse();

	int sel; //선택용 변수
	int selX;
	int selY;
	/*HFONT font;
	LOGFONT log_font;
	log_font.lfHeight = FW_NORMAL;
	cout << "안녕하세용ㅇ오ㅗ오오ㅗ오ㅗ오오오오오" << endl;
	cout << "안녕하세용ㅇ오ㅗ오오ㅗ오ㅗ오오오오오" << endl;
	cout << "안녕하세용ㅇ오ㅗ오오ㅗ오ㅗ오오오오오" << endl;
	cout << "안녕하세용ㅇ오ㅗ오오ㅗ오ㅗ오오오오오" << endl;

	strcpy((char*)(log_font.lfFaceName), "Gulim");
	font = CreateFontIndirect(&log_font);*/

	LOGFONT lf;

	HFONT font, oldfont;

	lf.lfHeight = 100;
	lf.lfWidth = 100;
	lf.lfEscapement = 0;
	lf.lfOrientation = 0;
	lf.lfWeight = 0;
	lf.lfItalic = 0;
	lf.lfUnderline = 0;
	lf.lfStrikeOut = 0;
	lf.lfCharSet = HANGEUL_CHARSET;
	lf.lfOutPrecision = 0;
	lf.lfClipPrecision = 0;
	lf.lfQuality = 0;
	wcscpy(lf.lfFaceName, L"Gulim");
	
	font = CreateFontIndirect(&lf);
	
	cout << "안녕하세용ㅇ오ㅗ오오ㅗ오ㅗ오오오오오" << endl;
	cout << "안녕하세용ㅇ오ㅗ오오ㅗ오ㅗ오오오오오" << endl;
	cout << "안녕하세용ㅇ오ㅗ오오ㅗ오ㅗ오오오오오" << endl;
	cout << "안녕하세용ㅇ오ㅗ오오ㅗ오ㅗ오오오오오" << endl;

	while (true) {
		selX = 57;
		selY = 12;
		cout << endl;
		gotoXY(55, 8);
		cout << "----------------------------Menu----------------------------" << endl;
		gotoXY(selX, selY);
		cout << "> 1. 계정 생성" << endl;
		gotoXY(selX, selY + 2);
		cout << "  2. 로그인" << endl;
		gotoXY(selX, selY + 4);
		cout << "  3. 플레이어 순위" << endl;
		gotoXY(selX, selY + 6);
		cout << "  4. 설정" << endl;
		gotoXY(selX, selY + 8);
		cout << "  5. 종료" << endl;
		gotoXY(55, 24);
		cout << "--------------------------------------------------------------" << endl << endl;
		gotoXY(55, 28);
		cout << "선택 (SpaceBar) >> ";
		gotoXY(75, 28);
		cout << '1';
		sel = 1;
		//메뉴 선택 방향 이동과 메뉴 선택 번호 업데이트 관련
		int keyCheck = -1;
		while (keyCheck != 32) { //스페이스바가 눌러질 때까지 계속 위아래 방향을 이동하며 sel을 업데이트한다.
			keyCheck = _getch();
			if (keyCheck == 224) { //방향키는 224 -> 방향키 UP, DOWN. 이런식
				keyCheck = _getch();
				switch (keyCheck) {
				case UP:
					if (selY > 12) { //12는 가장 위의 위치이므로 y값이 더 커야 위로 올라갈 수 있음
						gotoXY(selX, selY); cout << "  "; //원래 자리 비우기
						gotoXY(selX, selY -= 2); cout << "> "; //이동하기
					}
					break;
				case DOWN:
					if (selY < 20) { //20은 가장 아래 위치이므로 더 작아야 아래로 내려갈 수 있음.
						gotoXY(selX, selY); cout << "  ";
						gotoXY(selX, selY += 2); cout << "> ";
					}
					break;
				}
				//위아래 움직임에 따른 현재 선택 번호 표시 & sel 업데이트
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
		//메뉴 선택 방향 이동과 메뉴 선택 번호 업데이트 관련 END

		switch (sel) {
		case 1:
			system("pause"); system("cls"); playingShuffleSound(); cout << endl;
			CreateAccount();
			cout << endl; system("pause"); system("cls");
			break;
		case 2:
			system("pause"); system("cls"); playingShuffleSound(); cout << endl;
			//로그인 성공하면 게임 시작
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
			//효과음 끄기 켜기, 배경음악 끄기 켜기
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

//함수 정의
//

string fileRead(string fileName) {

	//파일 불러오기
	fstream readFile(fileName);
	string fileContent;

	if (readFile.is_open()) {
		//파일 읽어오기 성공

		//맨끝으로 위치 이동
		readFile.seekg(0, ios::end);

		//맨 처음 위치부터 현재위치(파일 맨 끝)까지의 크기를 반환
		int size = readFile.tellg();

		//size만큼 문자열의 공간을 정해줌
		fileContent.resize(size);

		//파일의 맨 처음 위치로 이동
		readFile.seekg(0, ios::beg);

		//파일의 전체 내용을 fileContent에 저장
		readFile.read(&fileContent[0], size);
	}
	else {
		//파일 읽어오기 실패
		fileContent = "파일을 찾을 수 없습니다.";
	}

	return fileContent;
}

//MINEGAME 시작
void StartGame()
{
	//file로 불러와서 시작화면 띄우기.
	string startScreen = fileRead("gameStartTextImage.txt");
	cout << startScreen;

	system("pause");
	system("cls");
	playingShuffleSound();

	int sel; //선택용 변수
	int selX;
	int selY;

	while (true) {

		selX = 57;
		selY = 12;
		cout << endl;
		gotoXY(55, 8);
		cout << "-------------------------MineGameTown-------------------------" << endl;
		gotoXY(selX, selY);
		cout << "> 1. 광물 수확" << endl;
		gotoXY(selX, selY + 2);
		cout << "  2. 상점" << endl;
		gotoXY(selX, selY + 4);
		cout << "  3. 내 정보" << endl;
		gotoXY(selX, selY + 6);
		cout << "  4. 게임 나가기" << endl;
		gotoXY(55, 22);
		cout << "--------------------------------------------------------------" << endl << endl;
		gotoXY(55, 24);
		cout << "선택 (SpaceBar) >> ";
		gotoXY(75, 24);
		cout << '1';
		sel = 1;
		//메뉴 선택 방향 이동과 메뉴 선택 번호 업데이트 관련
		int keyCheck = -1;
		while (keyCheck != 32) { //스페이스바가 눌러질 때까지 계속 위아래 방향을 이동하며 sel을 업데이트한다.
			keyCheck = _getch();
			if (keyCheck == 224) { //방향키는 224 -> 방향키 UP, DOWN. 이런식
				keyCheck = _getch();
				switch (keyCheck) {
				case UP:
					if (selY > 12) { //12는 가장 위의 위치이므로 y값이 더 커야 위로 올라갈 수 있음
						gotoXY(selX, selY); cout << "  "; //원래 자리 비우기
						gotoXY(selX, selY -= 2); cout << "> "; //이동하기
					}
					break;
				case DOWN:
					if (selY < 18) { //18은 가장 아래 위치이므로 더 작아야 아래로 내려갈 수 있음.
						gotoXY(selX, selY); cout << "  ";
						gotoXY(selX, selY += 2); cout << "> ";
					}
					break;
				}
				//위아래 움직임에 따른 현재 선택 번호 표시 & sel 업데이트
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
		//메뉴 선택 방향 이동과 메뉴 선택 번호 업데이트 관련 END

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
			cout << "메뉴 화면으로 이동합니다." << endl;
			return;
		default:
			cout << endl;
			system("pause"); system("cls"); playingShuffleSound();
		}

	}

}

string ground[GAMEPLAY_SCREEN_HEIGHT][GAMEPLAY_SCREEN_WIDTH]; //
int item[GAMEPLAY_SCREEN_HEIGHT][GAMEPLAY_SCREEN_WIDTH];
int playerX = 0;
int playerY = 0;
int input = 0;

//음..

//void PlayerMove()
//{
//	//밑줄을 보이지 않게 하는 코드
//	CONSOLE_CURSOR_INFO cif;
//	cif.dwSize = 1;
//	cif.bVisible = FALSE;
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cif);
//	//END
//	srand(time(NULL));
//	while (true) {
//		if (input == 27)break;
//		system("cls"); cout << endl;
//		cout << "수확한 광물>>" << "여기" << endl << endl;
//
//		for (int i = 0; i < 35; i++) {
//			for (int j = 0; j < 70; j++) {
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), item[i][j]);
//				cout << ground[i][j];
//			}
//			cout << endl;
//		}
//
//		Sleep((rand() % 4001) + 1000);//1~5초정도 지나면 광물 생성 + 화면 갱신
//		int x = rand() % 70;
//		int y = rand() % 35;
//		ground[y][x] = "■";
//		//
//		item[y][x] = (rand() % 6)+1; //1~6
//
//	
//	}
//}
char mine[30] = "광물 1";
clock_t prevTime_render;
clock_t currentTime_render;
int renderTime = 3;
int renderTimeCheck;
string playerCharacter = "○";
void GoMining()
{

	cursorVisibleFalse(); //커서 안보이게 하기
	srand(time(NULL)); //랜덤수 랜덤하게 발생시키기

	cout << "수확한 광물>>" << endl << endl;
	
	//게임 플레이 부분의 모든 곳을 초기화
	for (int i = 0; i < GAMEPLAY_SCREEN_HEIGHT; i++) {
		for (int j = 0; j < GAMEPLAY_SCREEN_WIDTH; j++) {
			ground[i][j] = "  ";
			item[i][j] = EMPTY;
		}
	}

	//벽을 생성!
	for (int i = -1; i < GAMEPLAY_SCREEN_HEIGHT + 1; i++) {
		gotoXY((COORDINATE_LEFT - 1) * 2, COORDINATE_TOP + i);
		cout << "◆";
		gotoXY((COORDINATE_LEFT + GAMEPLAY_SCREEN_WIDTH) * 2, COORDINATE_TOP + i);
		cout << "◆";
	}
	for (int i = -1; i < GAMEPLAY_SCREEN_WIDTH + 1; i++) {
		gotoXY((COORDINATE_LEFT + i) * 2, COORDINATE_TOP - 1);
		cout << "◆";
		gotoXY((COORDINATE_LEFT + i) * 2, COORDINATE_TOP + GAMEPLAY_SCREEN_HEIGHT);
		cout << "◆";
	}
	
	//플레이어의 위치를 세팅
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	ground[playerY][playerX] = playerCharacter;
	gotoXY((COORDINATE_LEFT +playerX)*2, COORDINATE_TOP + playerY);
	cout << playerCharacter;

	prevTime_render = clock(); //시작했을 때의 시간 체크
	while (true) {
		//키 입력, 움직임 관련 구간
		if (_kbhit() != 0) {//_kbhit()는 키보드가 눌렸는지 체크해주는 함수이다. 눌리면 0 이외의 값을 리턴
			input = _getch();
			if (input == 224) {
				input = _getch();
				if ((input == UP) && ((playerY - 1) != -1)) { 
					ground[playerY][playerX] = "  "; 
					gotoXY((COORDINATE_LEFT + playerX)*2, COORDINATE_TOP + playerY);
					cout << ground[playerY][playerX];
					playerY-=1;
				}
				else if ((input == DOWN) && ((playerY + 1) != GAMEPLAY_SCREEN_HEIGHT)) { 
					ground[playerY][playerX] = "  ";
					gotoXY((COORDINATE_LEFT + playerX) * 2, COORDINATE_TOP + playerY);
					cout << ground[playerY][playerX];
					playerY+=1;
				}
				else if ((input == LEFT) && ((playerX - 1) != -1)) {
					ground[playerY][playerX] = "  ";
					gotoXY((COORDINATE_LEFT + playerX) * 2, COORDINATE_TOP + playerY);
					cout << ground[playerY][playerX];
					playerX-=1;
				}
				else if ((input == RIGHT) && ((playerX + 1) != GAMEPLAY_SCREEN_WIDTH)) { 
					ground[playerY][playerX] = "  "; 
					gotoXY((COORDINATE_LEFT + playerX) * 2, COORDINATE_TOP + playerY);
					cout << ground[playerY][playerX];
					playerX+=1;
				}
				Sleep(1);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
				ground[playerY][playerX] = playerCharacter;
				gotoXY((COORDINATE_LEFT + playerX)*2, COORDINATE_TOP + playerY);
				cout << ground[playerY][playerX];
			}
			if (input == 27) break; //esc가 눌리면 메뉴로 이동
			//키 입력, 움직임 관련 구간 END
		}
		else {
			Update();
			Render();
		}
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), EMPTY);
}
int mineX = 0;
int mineY = 0;
void Update()
{
	currentTime_render = clock();

	renderTimeCheck = (currentTime_render - prevTime_render) / CLOCKS_PER_SEC;

	if (renderTime <= renderTimeCheck) {
		//랜덤한 시간이 지나면(처음은 3초) 생성을 한다.
		renderTime = rand() % 10;//0 ~ 9초 사이의 랜덤한 생성
		prevTime_render = clock();

		//생성
		//x, y값을 생성하고 item은 실제 광물의 역할을 하며 번호에 따른 색이 부여됨.
		//그리고 ground는 땅의 출력을 할 때 사용되는 정도
		mineX = rand() % 70;
		mineY = rand() % 35;
		ground[mineY][mineX] = "■";
		item[mineY][mineX] = (rand() % 6) + 1; //1~6
	}


	//어떤 광물을 먹으면 수확한 광물의 이름을 변경
	//
}
void Render()
{
	//출력 관련

	/*if (수확을 했다면) {
	* 
		system("cls");
		cout << endl;
		cout << "수확한 광물>>" << mine << endl << endl;
		strcpy(mine, "광물 2");
	}*/

	/*item[playerY][playerX] = YELLOW;
	ground[playerY][playerX] = "□";*/

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), item[mineY][mineX]);
	gotoXY((COORDINATE_LEFT + mineX)*2, COORDINATE_TOP + mineY);
	cout << ground[mineY][mineX];

	//for (int i = 0; i < GAMEPLAY_SCREEN_HEIGHT; i++) {
	//	for (int j = 0; j < GAMEPLAY_SCREEN_WIDTH; j++) {
	//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), item[i][j]);
	//		cout << ground[i][j];
	//	}
	//	cout << endl;
	//}
	//출력 관련 END
}

//회원가입.
void CreateAccount() {

	//아이디는 최대 20까지, 한글X, 영어나 숫자만을 이용하여 만들기
	//비밀번호도 영어나 숫자만을 이용하여 만들기 최대 20

	char id[50];
	char pw[50];
	bool idAndPwCheck;

	while (true) {
		idAndPwCheck = true;

		cout << "--------회원가입--------" << endl << endl;
		cout << "아이디, 비밀번호는 모두 영어 소문자와 숫자만을 이용하여 만들 수 있으며\n최대 50자까지 설정 가능합니다." << endl << endl;
		cout << "아이디 입력 : "; cin >> id;
		cout << "비밀번호 입력 : "; cin >> pw;

		//id 체크
		for (int i = 0; id[i] != NULL; i++) {
			if ((id[i] < 'a' || id[i] > 'z') && (id[i] < '0' || id[i] > '9')) { idAndPwCheck = false; break; }
		}
		//pw체크
		for (int i = 0; pw[i] != NULL; i++) {
			if ((pw[i] < 'a' || pw[i] > 'z') && (pw[i] < '0' || pw[i] > '9')) { idAndPwCheck = false; break; }
		}

		//모두 잘 입력하면 while END
		if (idAndPwCheck == true) { break; }

		system("cls"); cout << endl;
		cout << "아이디와 비밀번호는 영어 소문자와 숫자만을 이용해서 만들어 주세요." << endl << endl;
		system("pause"); system("cls");

	}
	//while END

	int sel; //선택용 변수

	while (true) {

		system("pause"); system("cls"); playingShuffleSound();
		cout << "계정을 생성하시겠습니까?" << endl << endl;
		cout << "1. 네" << endl;
		cout << "2. 아니오" << endl << endl;
		cout << "번호 선택 >> "; cin >> sel;

		switch (sel) {
		case 1:
			system("pause"); system("cls"); playingShuffleSound(); cout << endl;
			cout << "계정이 생성됩니다." << endl;
			break;
			cout << endl; system("pause"); system("cls");
		case 2:
			system("pause"); system("cls"); cout << endl;
			cout << "메인 화면으로 돌아갑니다." << endl;
			playingShuffleSound();
			return;
		default:
			cout << endl; system("pause"); system("cls"); playingShuffleSound();
		}

		if (sel == 1) break;
	}
	//while END

	//계정 생성
	cout << "id: " << id << endl;
	cout << "pw: " << pw << endl;
	UserAccount accountCreate(id, pw);
	//db에 정보 저장(userId)
	cout << "계정 생성 완료" << endl;
}

////로그인
void LogIn()
{

	//db불러와서 같은 아이디와 비번의 정보를 모두 가져오고 세팅한다.
	//가져온 정보를 이용하여 객체 만든다.


}

//사용자 메모리 해제
void LogOut()
{

}

//게임이 종료되기 전 메모리 해제 등을 하는 함수
void Destroy()
{
	//게임을 종료

	cout << "게임이 종료됩니다." << endl;
	Sleep(300);
	cout << "안녕히 가십시오." << endl;
	Sleep(300);

	//메모리들 해제

}

void gotoXY(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void cursorVisibleFalse() {
	//밑줄을 보이지 않게 하는 코드
	CONSOLE_CURSOR_INFO cif;
	cif.dwSize = 1;
	cif.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cif);
	//END
}

//함수 정의 END
