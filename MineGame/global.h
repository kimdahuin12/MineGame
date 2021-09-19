#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define GAMEPLAY_SCREEN_WIDTH 35
#define GAMEPLAY_SCREEN_HEIGHT 35
#define COORDINATE_TOP 3  //���� ��ǥ�� �� �� ��ǥ �⺻. 
#define COORDINATE_LEFT 25  //���� ��ǥ�� �� ���� ��ǥ �⺻. 

#include <iostream>
#include <fstream>

#include <windows.h>

#include "setting.h"

//����
#include <Digitalv.h>
#pragma comment(lib, "winmm.lib")


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