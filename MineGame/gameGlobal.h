#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define GAMEPLAY_GROUND_WIDTH 35
#define GAMEPLAY_GROUND_HEIGHT 35
#define COORDINATE_TOP 3  //���� ��ǥ�� �� �� ��ǥ �⺻. 
#define COORDINATE_LEFT 25  //���� ��ǥ�� �� ���� ��ǥ �⺻. 
#define MINERAL_ITEM_COUNT 6 //���� �� ����
#define MINE_COUNT 3

#include <windows.h>
#include <iostream>
#include <conio.h>//Ű �Է� ���� ���

using namespace std;

//key�Է� �ƽ�Ű�ڵ�
//224 -> KEYBOARD

enum KEYBOARD {
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80

};

//key�Է� enum END

enum COLOR {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VIOLET,
	DAKR_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	EMPTY,
};

