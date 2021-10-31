#pragma once
#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "libmysql.lib")
#include <my_global.h>
#include <mysql.h>
#include <iostream>
#include <string>
#include "Player.h"
#include "Mine.h"
#include "global.h"
#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "0407"
#define DB_NAME "minegame_db"
#define CHOP(x) x[strlen(x)-1] = ' '
#define MINERAL_MAX 18

using namespace std;


class MysqlDatabase
{
private:

public:
	static void create_account(); //회원가입을 하고 id, password, money를 데이터 베이스에 저장. id는 중복 x
	static void ranking_print();//돈이 많은 회원순으로 출력
	static bool login(char* id, unsigned long& money); //로그인 성공하면 돈이랑 id저장
	static void moneySave(char* money);
	static void playerInit(Player* player);
	static void playerMineralSave(MyItem** items, int itemsCount, const char* playerId);
	static void playerMoneySave(unsigned long playerMoney, const char* playerId);
	static int MineralCondition(int id);
	static void MineInfoSave(Mine& mine, int id);
	static int GetEntrancePrice(int id);
	//상점
	static void Market(Player& player);
};

