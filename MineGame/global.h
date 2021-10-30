#pragma once
#include <iostream>
#include <fstream>
#include <stdio.h>

#include <windows.h>

#include "setting.h"

//À½¾Ç
#include <Digitalv.h>
#pragma comment(lib, "winmm.lib")

#define SCREEN_WIDTH 160
#define SCREEN_HEIGHT 40

using namespace std;

void playingShuffleSound();
void reverseScene();
void gotoXY(int x, int y);
void soundPlay();