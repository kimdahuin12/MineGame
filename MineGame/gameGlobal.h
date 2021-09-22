#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define GAMEPLAY_GROUND_WIDTH 35
#define GAMEPLAY_GROUND_HEIGHT 35
#define COORDINATE_TOP 3  //게임 좌표의 맨 위 좌표 기본. 
#define COORDINATE_LEFT 25  //게임 좌표의 맨 왼쪽 좌표 기본. 
#define MINERAL_ITEM_COUNT 6 //광물 색 갯수
#define MINE_COUNT 3

#include <windows.h>
#include <iostream>
#include <conio.h>//키 입력 관련 헤더

using namespace std;

//key입력 아스키코드
//224 -> KEYBOARD

enum KEYBOARD {
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80

};

//key입력 enum END

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

