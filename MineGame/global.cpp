#include "global.h"
MCI_OPEN_PARMS openBgm;
MCI_PLAY_PARMS playBgm;
MCI_OPEN_PARMS openShuffleSound;
MCI_PLAY_PARMS playShuffleSound;


int dwID;
void playingShuffleSound() {
	//ȿ����
	//openShuffleSound.lpstrElementName = "./sound/click.mp3"; //���� ����
	//openShuffleSound.lpstrDeviceType = "mpegvideo"; //mp3 ����
	//mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openShuffleSound);
	//dwID = openShuffleSound.wDeviceID;
	//mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openShuffleSound); //������ �� �� ���
	//Sleep(70); //ȿ������ ����� ������ �����ߴٰ�
	//mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //���� ��� ��ġ�� ó������ �ʱ�ȭ
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
	//����
	//openBgm.lpstrElementName = "./sound/bgSound.mp3"; //���� ����
	//openBgm.lpstrDeviceType = "mpegvideo"; //mp3 ����
	//mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm);
	//dwID = openBgm.wDeviceID;
	//mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&openBgm); //���� �ݺ� ���
	//���� END
}