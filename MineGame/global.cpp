#include "global.h"
MCI_OPEN_PARMS openBgm;
MCI_PLAY_PARMS playBgm;
MCI_OPEN_PARMS openShuffleSound;
MCI_PLAY_PARMS playShuffleSound;


int dwID;
void playingShuffleSound() {
	//효과음
	//openShuffleSound.lpstrElementName = "./sound/click.mp3"; //파일 오픈
	//openShuffleSound.lpstrDeviceType = "mpegvideo"; //mp3 형식
	//mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openShuffleSound);
	//dwID = openShuffleSound.wDeviceID;
	//mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openShuffleSound); //음악을 한 번 재생
	//Sleep(70); //효과음이 재생될 때까지 정지했다가
	//mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
}

void gotoXY(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void reverseScene() {
	gotoXY(0, 38);
	cout << endl;
	system("pause"); system("cls");
	//playingShuffleSound();
}

void soundPlay() {
	//음악
	//openBgm.lpstrElementName = "./sound/bgSound.mp3"; //파일 오픈
	//openBgm.lpstrDeviceType = "mpegvideo"; //mp3 형식
	//mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm);
	//dwID = openBgm.wDeviceID;
	//mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&openBgm); //음악 반복 재생
	//음악 END
}