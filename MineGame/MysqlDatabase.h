#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
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

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

class MysqlDatabase
{
private:

public:
	static void create_account(); //ȸ�������� �ϰ� id, password, money�� ������ ���̽��� ����. id�� �ߺ� x
	static void ranking_print();//���� ���� ȸ�������� ���
	//static bool login(char* id, unsigned long& money); //�α��� �����ϸ� ���̶� id����
	//static void moneySave(char* money);
	//static void playerInit(Player* player);
	//static void playerMineralSave(MyItem** items, int itemsCount, const char* playerId);
	//static void playerMoneySave(unsigned long playerMoney, const char* playerId);
	//static int MineralCondition(int id);
	//static void MineInfoSave(Mine& mine, int id);
	//static int GetEntrancePrice(int id);
	////����
	//static void Market(Player& player);
};

