#pragma once

//������ ������

/*
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VIOLET,
	DAKR_YELLOW,
*/

/*
���� ���̶� �̸� ���ϰ�
*/

/*
	������ ����

	���Ͽ� ������ 

*/

//static const char* MineralName[] = {
//	"�� ��ĳ������Ʈ", "�� ���̽��ҳ���Ʈ", "�� ��Ʈ��",
//	"�� �÷����Ʈ", "�� �Ƹ�����Ʈ", "�� ���ǵ�����Ʈ",
//	"�� ���ǳ�", "�� ���", "�� ����",
//	"�� ��Ű��", "�� �丮��Ʈ", "�� ���޶���",
//	"�� ����Ƹ���", "�� ���ֶ���Ʈ", "�� �����̾�",
//	"�� ���̾Ƹ��", "�� �׶��������Ʈ", "�� ��������Ʈ",
//};
//
//static const int MineralColor[] = {
//	DARK_YELLOW, DARK_YELLOW, DARK_YELLOW,
//	VIOLET, VIOLET, VIOLET,
//	DARK_RED, DARK_RED, DARK_RED,
//	GREEN, GREEN, GREEN,
//	BLUE, BLUE, BLUE,
//	SKYBLUE, SKYBLUE, SKYBLUE
//};
//



//�Ķ��� ����
static const char* BlueMineralName[] = { "�� ����Ƹ���", "�� ���ֶ���Ʈ", "�� �����̾�"}; //�����͹迭. �����͸� ��� �ִ� �迭.
static const int BlueMineralCount = sizeof(BlueMineralName) / sizeof(char*);

//�ʷϻ� ����
static const char* GreenMineralName[] = { "�� ��Ű��", "�� �丮��Ʈ", "�� ���޶���" }; //�����͹迭. �����͸� ��� �ִ� �迭.
static const int GreenMineralCount = sizeof(GreenMineralName) / sizeof(char*);

//�ϴû� ����
static const char* SkyBlueMineralName[] = { "�� ���̾Ƹ��", "�� �׶��������Ʈ", "�� ��������Ʈ" }; //�����͹迭. �����͸� ��� �ִ� �迭.
static const int SkyBlueMineralCount = sizeof(SkyBlueMineralName) / sizeof(char*);

//������ ����
static const char* RedMineralName[] = { "�� ���ǳ�", "�� ���", "�� ����" }; //�����͹迭. �����͸� ��� �ִ� �迭.
static const int RedMineralCount = sizeof(RedMineralName) / sizeof(char*);

//����� ����
static const char* VioletMineralName[] = { "�� �÷����Ʈ", "�� �Ƹ�����Ʈ", "�� ���ǵ�����Ʈ" }; //�����͹迭. �����͸� ��� �ִ� �迭.
static const int VioletMineralCount = sizeof(VioletMineralName) / sizeof(char*);

//����� ����
static const char* YellowMineralName[] = { "�� ��ĳ������Ʈ", "�� ���̽��ҳ���Ʈ", "�� ��Ʈ��" }; //�����͹迭. �����͸� ��� �ִ� �迭.
static const int YellowMineralCount = sizeof(YellowMineralName) / sizeof(char*);