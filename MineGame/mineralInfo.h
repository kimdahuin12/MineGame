#pragma once

#define MINERAL_ITEM_COUNT 6 //���� �� ���� ����

//������ ������

/*
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VIOLET,
	DAKR_YELLOW,
*/

//�Ķ��� ����
const char* BlueMineralName[] = { "BLUE����-1", "BLUE����-2", "BLUE����-3"}; //�����͹迭. �����͸� ��� �ִ� �迭.
const int BlueMineralCount = sizeof(BlueMineralName) / sizeof(char*);

unsigned int BlueMineralPrice[BlueMineralCount] = { 200, 300, 400};
float BlueMineralRarity[BlueMineralCount] = { 1.4, 2.3, 4.3};
int BlueMineralDelTime[BlueMineralCount] = { 2, 3, 4}; //���ְ� ��͵��� ���� �ص� �� ���ϴ�.

//�ʷϻ� ����
const char* GreenMineralName[] = { "GREEN����-1", "GREEN����-2", "GREEN����-3" }; //�����͹迭. �����͸� ��� �ִ� �迭.
const int GreenMineralCount = sizeof(GreenMineralName) / sizeof(char*);

unsigned int GreenMineralPrice[GreenMineralCount] = { 200, 300, 400 };
float GreenMineralRarity[GreenMineralCount] = { 1.4, 2.3, 4.3 };
int GreenMineralDelTime[GreenMineralCount] = { 2, 3, 4 }; //���ְ� ��͵��� ���� �ص� �� ���ϴ�.

//�ϴû� ����
const char* SkyBlueMineralName[] = { "SKYBLUE����-1", "SKYBLUE����-2", "SKYBLUE����-3" }; //�����͹迭. �����͸� ��� �ִ� �迭.
const int SkyBlueMineralCount = sizeof(SkyBlueMineralName) / sizeof(char*);

unsigned int SkyBlueMineralPrice[SkyBlueMineralCount] = { 200, 300, 400 };
float SkyBlueMineralRarity[SkyBlueMineralCount] = { 1.4, 2.3, 4.3 };
int SkyBlueMineralDelTime[SkyBlueMineralCount] = { 2, 3, 4 }; //���ְ� ��͵��� ���� �ص� �� ���ϴ�.


//������ ����
const char* RedMineralName[] = { "RED����-1", "RED����-2", "RED����-3" }; //�����͹迭. �����͸� ��� �ִ� �迭.
const int RedMineralCount = sizeof(RedMineralName) / sizeof(char*);

unsigned int RedMineralPrice[RedMineralCount] = { 200, 300, 400 };
float RedMineralRarity[RedMineralCount] = { 1.4, 2.3, 4.3 };
int RedMineralDelTime[RedMineralCount] = { 2, 3, 4 }; //���ְ� ��͵��� ���� �ص� �� ���ϴ�.

//����� ����
const char* VioletMineralName[] = { "VIOLET����-1", "VIOLET����-2", "VIOLET����-3" }; //�����͹迭. �����͸� ��� �ִ� �迭.
const int VioletMineralCount = sizeof(VioletMineralName) / sizeof(char*);

unsigned int VioletMineralPrice[VioletMineralCount] = { 200, 300, 400 };
float VioletMineralRarity[VioletMineralCount] = { 1.4, 2.3, 4.3 };
int VioletMineralDelTime[VioletMineralCount] = { 2, 3, 4 }; //���ְ� ��͵��� ���� �ص� �� ���ϴ�.

//����� ����
const char* YellowMineralName[] = { "YELLOW����-1", "YELLOW����-2", "YELLOW����-3" }; //�����͹迭. �����͸� ��� �ִ� �迭.
const int YellowMineralCount = sizeof(YellowMineralName) / sizeof(char*);

unsigned int YellowMineralPrice[YellowMineralCount] = { 200, 300, 400 };
float YellowMineralRarity[YellowMineralCount] = { 1.4, 2.3, 4.3 };
int YellowMineralDelTime[YellowMineralCount] = { 2, 3, 4 }; //���ְ� ��͵��� ���� �ص� �� ���ϴ�.