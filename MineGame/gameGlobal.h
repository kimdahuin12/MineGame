#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define GAMEPLAY_GROUND_WIDTH 80//160������ ĳ���ͳ� ���� ��� ���θ� 2�� �����ϱ� ������ 80���� ����
#define GAMEPLAY_GROUND_HEIGHT 37
#define COORDINATE_TOP 2  //���� ��ǥ�� �� �� ��ǥ �⺻. 
#define COORDINATE_LEFT 25  //���� ��ǥ�� �� ���� ��ǥ �⺻. 
#define MINERAL_ITEM_COUNT 6 //���� �� ����
#define MINE_COUNT 3
#define ROAD "  "
#define PLAYER_CHARACTER "��"
/*
#define COORDINATE_TOP 4  //���� ��ǥ�� �� �� ��ǥ �⺻.
#define COORDINATE_LEFT 70  //���� ��ǥ�� �� ���� ��ǥ �⺻.
*/

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
	DARK_YELLOW,
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

