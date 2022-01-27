#define _CRT_SECURE_NO_WARNINGS
#include "MysqlDatabase.h"
#include "global.h"

#include "Player.h"

#include "MyItem.h"
#include "Mine.h"

//db에 넣을거
//광물 테이블
//(광물 이름, 광물 가격)
//포션

//맵에 장애물이 추가가 된다.
//광산을 더 추가하자
//광산에 따라 모양을 다르게 하고 싶다.
//

//
//함수 선언
void fileReadAndPrint(string fileName);
void StartGame();
void GoMining();
//void PlayerMove();
void LogOut();
void Destroy();
void cursorVisibleFalse();

//클래스 선언
Player* player;
Mine* mine = nullptr; 

// https://kiffblog.tistory.com/151
int main() {
	//창 크기
	system("mode con: cols=160 lines=40");
	system("title MIneGame");
	
	soundPlay(); //음악 재생

	//밑줄(커서)가 보이지 않게 해주는 함수.
	cursorVisibleFalse();

	int sel; //선택용 변수
	int selX;
	int selY;
	
	cout << "test" << endl;

	while (true) {
		//아래와 같이 할 수 있는 그런..
		//x, y 좌표를 설정해주면 간격 2로 차례대로 나올 수 있도록 했으면 좋겠다.
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
		case 1:														//회원가입
			reverseScene();
			//회원가입. (회원가입 후 DB에 저장하는 함수)
			MysqlDatabase::create_account();
			reverseScene();
			break;
		case 2:														//로그인
			reverseScene();
			//로그인 성공하면 게임 시작
			char id[50];
			unsigned long money;
			StartGame();
			//if (MysqlDatabase::login(id, money)) { //로그인을 했다면 로그인된 아이디와 money 저장후 true, 아니면 false를 return 
			//	//로그인 성공
			//	player = new Player(id, money);
			//	MysqlDatabase::playerInit(player); //플레이어 아이템, 돈, 등등 설정하기
			//	StartGame();
			//	LogOut();
			//}
			break;
		case 3:														//랭킹
			reverseScene();
			MysqlDatabase::ranking_print();
			reverseScene();
			break;
		case 4:														//설정
			system("pause"); system("cls"); playingShuffleSound(); cout << endl;
			//효과음 끄기 켜기, 배경음악 끄기 켜기
			setting();
			cout << endl; system("pause"); system("cls");
			break;
		case 5:														//종료
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

void fileReadAndPrint(string fileName) {

	//파일 불러오기
	fstream readFile(fileName);
	char* fileContent = nullptr;

	if (readFile.is_open()) {
		//파일 읽어오기 성공

		//맨끝으로 위치 이동
		readFile.seekg(0, ios::end);
		//맨 처음 위치부터 현재위치(파일 맨 끝)까지의 크기를 반환
		int size = readFile.tellg();
		size -= 40;
		//size만큼 문자열의 공간을 정해줌
		fileContent = new char[size + 1];
		//파일의 맨 처음 위치로 이동
		readFile.seekg(0, ios::beg);
		//파일의 전체 내용을 fileContent에 저장
		readFile.read(&fileContent[0], size);
		//이부분은 게임 관련 텍스트 이미지를 위한 부분이다.
		if (true) {
			gotoXY(0, 0);
			int cnt = 0;
			for (int i = 0; i <= size; i++) {
				if (fileContent[i] == '0') {
					//C9A1
					cout << "▼";
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
		//파일 읽어오기 실패
		strcpy(fileContent, "파일을 찾을 수 없습니다.");
	}
	readFile.close();
}

//MINEGAME 시작
void StartGame()
{
	int sel; //선택용 변수
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
				sel = (selY - 10) / 2;
			}
		}
		cout << endl;
		//메뉴 선택 방향 이동과 메뉴 선택 번호 업데이트 관련 END

		switch (sel) {
		case 1:															//광산 입장
			reverseScene();
			GoMining();
			cout << endl; system("cls");
			break;
		case 2:															//상점
			reverseScene();
			//MysqlDatabase::Market(*player);
			reverseScene();
			break;
		case 3:															//인벤토리
			reverseScene();
			//MyInfo
			player->Inventory();
			reverseScene();
			break;
		case 4:															//로그아웃
  			reverseScene();
			//로그아웃 후 메뉴화면으로 이동
			//MysqlDatabase::playerMoneySave(player->getMoney(), player->getId());
			//MysqlDatabase::playerMineralSave(player->getInventory(), player->getItemCount(), player->getId()); //광물의 갯수를 db에 저장
			//delete player;
			cout << "메뉴 화면으로 이동합니다." << endl;
			reverseScene();
			return;
		default:
			cout << endl;
			system("pause"); system("cls"); playingShuffleSound();
		}
	}
}



void GameInit() {
	cursorVisibleFalse(); //커서 안보이게 하기
	srand(time(NULL)); //랜덤수 랜덤하게 발생시키기
	mine->MineInit();
}

void GoMining()
{
	//어느 광산에 들어갈지
	int sel; //선택용 변수
	int selX;
	int selY;

	while (true) {
		selX = 57; selY = 12;

		gotoXY(selX, selY);
		cout << "> 1. 일반 광산 - 입장비용 :5,000원" << endl;
		gotoXY(selX, selY + 2);
		cout << "  2. 중급 광산 - 입장비용 :10,000원" << endl;
		gotoXY(selX, selY + 4);
		cout << "  3. 고급 광산 - 입장비용 :50,000원" << endl;
		gotoXY(selX, selY + 6);
		cout << "  4. 테스트1 광산 - 입장비용 :100,000원" << endl;
		gotoXY(selX, selY + 8);
		cout << "  5. 테스트2 광산 - 입장비용 :150,000원" << endl;
		gotoXY(selX, selY + 10);
		cout << "  6. 나가기" << endl;
		gotoXY(35, 12 + 22);
		cout << "선택 (SpaceBar) >> ";
		gotoXY(55, 12 + 24);
		cout << '1'; sel = 1;
		//메뉴 선택 방향 이동과 메뉴 선택 번호 업데이트 관련
		int keyCheck = -1;
		while (keyCheck != 32) { //스페이스바가 눌러질 때까지 계속 위아래 방향을 이동하며 sel을 업데이트한다.
			keyCheck = _getch();
			if (keyCheck == 224) { //방향키는 224 -> 방향키 UP, DOWN.만 체크할 것이다.
				keyCheck = _getch();
				switch (keyCheck) {
				case UP:
					if (selY > 12) { //12는 가장 위의 위치이므로 y값이 더 커야 위로 올라갈 수 있음
						gotoXY(selX, selY); cout << "  "; //원래 자리 비우기
						gotoXY(selX, selY -= 2); cout << "> "; //이동하기
					}
					break;
				case DOWN:
					if (selY < 12 + 12) { //12+12은 가장 아래 위치이므로 더 작아야 아래로 내려갈 수 있음.
						gotoXY(selX, selY); cout << "  ";
						gotoXY(selX, selY += 2); cout << "> ";
					}
					break;
				}
				//위아래 움직임에 따른 현재 선택 번호 표시 & sel 업데이트
				gotoXY(55, 34);
				sel = (selY - 10) / 2; //선택한 번호
				
			}
		}
		cout << endl;
		//메뉴 선택 방향 이동과 메뉴 선택 번호 업데이트 관련 END
		if (sel == 6) {
			playingShuffleSound();
			return; 
		}
		//들어갈 수 있는지 확인

		//고른 번호에 맞게 db에서 조회해서 필요한 광물의 갯수를 가져온다.
 	//	int mineral_condision = MysqlDatabase::MineralCondition(sel);

  //		if (player->MineAuthorityCheck(mineral_condision) && player->decreaseMoney(MysqlDatabase::GetEntrancePrice(sel))) {
		//	//광산에 들어갈 수 있다면
		//	//Mine객체를 만들고 초기화
		//	mine = nullptr;
		//	mine = new Mine(player, sel);
		//	MysqlDatabase::MineInfoSave(*mine, sel);			//db에서 mine의 정보를 불러와서 mine객체의 변수에 저장

		//	break;
		//}
		//else {
		//	//광산에 들어갈 수 없다면
		//	reverseScene();
		//	gotoXY(50, 50);
		//	cout << "들어갈 수 없는 광산" << endl;
		//	reverseScene();
		//}


		mine = nullptr;
		mine = new Mine(player, sel);
		char* name = new char[strlen("일반 광산") + 1];
		strcpy(name, "일반 광산");
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
		//키 입력, 움직임 관련 구간
		if (_kbhit() != 0) {//_kbhit()는 키보드가 눌렸는지 체크해주는 함수이다. 눌리면 0 이외의 값을 리턴
			int input = mine->KeyInputRelated();//키 관련 처리를 하고 입력된 값을 반환해준다.
			if (input == 27) {
				break;
			}//esc가 눌리면 메뉴로 이동
			//키 입력, 움직임 관련 구간 END
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

//사용자 메모리 해제
void LogOut()
{

}

//게임이 종료되기 전 메모리 해제 등을 하는 함수
void Destroy()
{
	//게임을 종료
	delete mine;
	cout << "게임이 종료됩니다." << endl;
	Sleep(300);
	cout << "안녕히 가십시오." << endl;
	Sleep(300);

	//메모리들 해제

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
