#include "global.h"

void setting() {
	int sel;
	
	while (1) {
		cout << endl;
		cout << "1. ������� on" << endl;
		cout << "2. ������� off" << endl;
		cout << "3. ȿ���� on" << endl;
		cout << "4. ȿ���� off" << endl;
		cout << "5. ������" << endl;
		cout << endl;
		
		cin >> sel; 

		switch (sel) {
		case 1: 
			system("pause"); system("cls");
			cout << endl;
			//openBgm.lpstrElementName = L"D:\\cppProject\\playGame\\Debug\\sound\\bgSound.mp3"; //���� ����
			//openBgm.lpstrDeviceType = L"mpegvideo"; //mp3 ����
			//mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm);
			//dwID = openBgm.wDeviceID;
			//mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&openBgm); //���� �ݺ� ���

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
