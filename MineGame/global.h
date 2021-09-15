#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define GAMEPLAY_SCREEN_WIDTH 35
#define GAMEPLAY_SCREEN_HEIGHT 35
#define COORDINATE_TOP 3  //°ÔÀÓ ÁÂÇ¥ÀÇ ¸Ç À§ ÁÂÇ¥ ±âº». 
#define COORDINATE_LEFT 25  //°ÔÀÓ ÁÂÇ¥ÀÇ ¸Ç ¿ÞÂÊ ÁÂÇ¥ ±âº». 

#include <iostream>
#include <fstream>

#include <windows.h>

#include "setting.h"

//À½¾Ç
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