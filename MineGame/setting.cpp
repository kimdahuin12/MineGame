#include "global.h"

void setting() {
	int sel;
	
	while (1) {
		cout << endl;
		cout << "1. 배경음악 on" << endl;
		cout << "2. 배경음악 off" << endl;
		cout << "3. 효과음 on" << endl;
		cout << "4. 효과음 off" << endl;
		cout << "5. 나가기" << endl;
		cout << endl;
		
		cin >> sel; 

		switch (sel) {
		case 1: 
			system("pause"); system("cls");
			cout << endl;
			//openBgm.lpstrElementName = L"D:\\cppProject\\playGame\\Debug\\sound\\bgSound.mp3"; //파일 오픈
			//openBgm.lpstrDeviceType = L"mpegvideo"; //mp3 형식
			//mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm);
			//dwID = openBgm.wDeviceID;
			//mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&openBgm); //음악 반복 재생

			cout << endl;
			system("pause"); system("cls");
			break;
		case 2:
			system("pause"); system("cls");
			cout << endl;
			PlaySound(nullptr, nullptr, SND_ASYNC);
			cout << endl;
			system("pause"); system("cls");
			break;
		case 3:
			system("pause"); system("cls"); 
			cout << endl;

			cout << endl;
			system("pause"); system("cls");
			break;
		case 4:
			system("pause"); system("cls"); 
			cout << endl;

			cout << endl;
			system("pause"); system("cls");
			break;
		case 5:
			system("pause"); system("cls");
			cout << endl;
			return;
		}

	}

}
