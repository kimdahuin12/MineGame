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


enum COLOR {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VOILET,
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